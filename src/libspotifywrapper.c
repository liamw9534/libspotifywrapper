#include <dlfcn.h>
#include <malloc.h>
#include <sys/queue.h>
#include <pthread.h>
#include <libspotify/api.h>

#ifdef WITH_DEBUG

#define DEBUG(str, ...) printf(str, ## __VA_ARGS__)
#define DEBUG_FN(str, ...) printf("[%x](%d): %s: " str, (int)pthread_self(), __LINE__, __func__, ## __VA_ARGS__)

#else

#define DEBUG(str, ...)    // Do Nothing
#define DEBUG_FN(str, ...) // Do Nothing

#endif

static void
logged_in (sp_session *session, sp_error error);
static void
logged_out (sp_session *session);
static void
metadata_updated (sp_session *session);
static void
connection_error (sp_session *session, sp_error error);
static void
message_to_user (sp_session *session, const char *message);
static void
notify_main_thread (sp_session *session);
static int
music_delivery (sp_session *session, const sp_audioformat *format,
                const void *frames, int num_frames);
static void
play_token_lost (sp_session *session);
static void
log_message (sp_session *session, const char *data);
static void
end_of_track (sp_session *session);
static void
streaming_error (sp_session *session, sp_error error);
static void
userinfo_updated (sp_session *session);
static void
start_playback (sp_session *session);
static void
stop_playback (sp_session *session);
static void
get_audio_buffer_stats (sp_session *session, sp_audio_buffer_stats *stats);
static void
offline_status_updated (sp_session *session);
static void
offline_error (sp_session *session, sp_error error);
static void
credentials_blob_updated (sp_session *session, const char *blob);
static void
connectionstate_updated (sp_session *session);
static void
scrobble_error (sp_session *session, sp_error error);
static void
private_session_mode_changed (sp_session *session, bool is_private);

static sp_session *g_session = (sp_session *) NULL;
static unsigned int g_nclients = 0;
static pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

// This table of callbacks are used by the wrapper
// and intercept all events sent by the spotify
// session before delivery to the required clients
static sp_session_callbacks g_callbacks =
    { &logged_in, &logged_out, &metadata_updated, &connection_error,
        &message_to_user, &notify_main_thread, &music_delivery, &play_token_lost,
        &log_message, &end_of_track, &streaming_error, &userinfo_updated,
        &start_playback, &stop_playback, &get_audio_buffer_stats,
        &offline_status_updated, &offline_error, &credentials_blob_updated,
        &connectionstate_updated, &scrobble_error, &private_session_mode_changed };

// Wrapper session structure - we use this to hold state
// that we need to keep about the client session connection,
// such as the callbacks and the actual real session structure
struct spw_session {
  sp_session_callbacks     cb;
  TAILQ_ENTRY(spw_session) tailq;
};

// Session structures are dynamically allocated and stored
// as a linked list
TAILQ_HEAD(, spw_session) g_head;

// Useful macros for accessing the session structure
#define SPW_SESSION(sess) ((struct spw_session *)sess)

// This structure allows us to discriminate where
// callback events should be delivered
// Setting a field to NULL means deliver to all
// clients, otherwise we deliver only to a single
// client denoted by the spw_session pointer
typedef struct spw_session_callback_clients_s
{
  struct spw_session *logged_in;
  struct spw_session *logged_out;
  struct spw_session *metadata_updated;
  struct spw_session *connection_error;
  struct spw_session *message_to_user;
  struct spw_session *notify_main_thread;
  struct spw_session *music_delivery;
  struct spw_session *play_token_lost;
  struct spw_session *log_message;
  struct spw_session *end_of_track;
  struct spw_session *streaming_error;
  struct spw_session *userinfo_updated;
  struct spw_session *start_playback;
  struct spw_session *stop_playback;
  struct spw_session *get_audio_buffer_stats;
  struct spw_session *offline_status_updated;
  struct spw_session *offline_error;
  struct spw_session *credentials_blob_updated;
  struct spw_session *connectionstate_updated;
  struct spw_session *scrobble_error;
  struct spw_session *private_session_mode_changed;

} spw_session_callback_clients;

// Initialize as 'all clients' receive callbacks
static spw_session_callback_clients g_callback_clients =
    { NULL };

static void
dump_linked_list (void)
{
  struct spw_session *p;
  int i = 0;
  TAILQ_FOREACH(p, &g_head, tailq)
  {
    DEBUG_FN("Element %p at index %d\n", p, i);
    i++;
  }
}

static struct spw_session *
spw_alloc_session (const sp_session_config *config)
{
  DEBUG_FN("IN\n");

  struct spw_session *spw = (struct spw_session *) malloc (sizeof(struct spw_session));
  if (spw == NULL)
    return NULL;

  spw->cb = *config->callbacks;
  TAILQ_INSERT_TAIL(&g_head, spw, tailq);

  g_nclients++;
  DEBUG_FN("g_nclients = %d\n", g_nclients);

#ifdef WITH_DEBUG
  dump_linked_list();
#endif

  DEBUG_FN("OUT\n");
  return spw;
}

static void
spw_free_session (struct spw_session *spw)
{
  DEBUG_FN("IN\n");
  TAILQ_REMOVE(&g_head, spw, tailq);
  free ((void *) spw);
  g_nclients--;
  DEBUG_FN("g_nclients = %d\n", g_nclients);

#ifdef WITH_DEBUG
  dump_linked_list();
#endif

  DEBUG_FN("OUT\n");
}

/* This code is autogenerated by codegen.py --libspotify */
#include "autogen_libspotify.c"

sp_error sp_session_create(const sp_session_config *config, sp_session **sess)
{
  DEBUG_FN("IN\n");
  sp_error ret = SP_ERROR_OK;

  // Create the real session if no session has
  // yet been created
  if (g_session == NULL)
  {
    sp_session_config local = *config;
    local.callbacks = &g_callbacks;
    TAILQ_INIT(&g_head);
    init___();
    ret = g_libspotify.sp_session_create(&local, &g_session);
    DEBUG_FN("Created new g_session %p\n", g_session);
  }

  // Create a client session if the real session was
  // created successfully
  if (ret == SP_ERROR_OK)
  {
    struct spw_session *spw = spw_alloc_session(config);
    *sess = (sp_session *)spw;
    DEBUG_FN("Created spw %p\n", spw);
  }

  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_release(sp_session *sess)
{
  DEBUG_FN("IN\n");
  sp_error ret = SP_ERROR_OK;

  // Free the spw_session but don't release the real
  // session unless there are no other clients connected
  spw_free_session(SPW_SESSION(sess));
  if (g_nclients == 0)
  {
    sp_error ret = g_libspotify.sp_session_release(g_session);
    g_session = (sp_session *)NULL;
    return ret;
  }

  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_player_load(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");

  // Since we're loading a track we expect music notification events and
  // we must ensure these are only delivered to the originating client
  g_callback_clients.music_delivery = SPW_SESSION(session);
  g_callback_clients.play_token_lost = SPW_SESSION(session);
  g_callback_clients.end_of_track = SPW_SESSION(session);
  g_callback_clients.streaming_error = SPW_SESSION(session);
  g_callback_clients.start_playback = SPW_SESSION(session);
  g_callback_clients.stop_playback = SPW_SESSION(session);
  g_callback_clients.get_audio_buffer_stats = SPW_SESSION(session);

  sp_error ret = g_libspotify.sp_session_player_load(g_session, track);
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_process_events(sp_session *session, int *next_timeout)
{
  pthread_mutex_lock(&g_mutex);
  sp_error ret = g_libspotify.sp_session_process_events(g_session, next_timeout);
  pthread_mutex_unlock(&g_mutex);
  return ret;
}

// Callbacks

#define DISPATCH_CALLBACK(cb_name, ...) \
    struct spw_session *p; \
    TAILQ_FOREACH(p, &g_head, tailq) \
    { \
      if (p->cb.cb_name && \
          (g_callback_clients.cb_name == NULL || g_callback_clients.cb_name == p)) { \
          DEBUG_FN("Calling user callback\n"); \
          p->cb.cb_name((sp_session *)p, ## __VA_ARGS__); \
      } \
    }

#define DISPATCH_CALLBACK_WITH_RETURN(ret, cb_name, ...) \
    struct spw_session *p; \
    TAILQ_FOREACH(p, &g_head, tailq) \
    { \
      if (p->cb.cb_name && \
          (g_callback_clients.cb_name == NULL || g_callback_clients.cb_name == p)) { \
          DEBUG_FN("Calling user callback\n"); \
          ret = p->cb.cb_name((sp_session *)p, ## __VA_ARGS__); \
      } \
    }

static void
logged_in (sp_session *session, sp_error error)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(logged_in, error); DEBUG_FN("OUT\n");
}

static void
logged_out (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(logged_out); DEBUG_FN("OUT\n");
}

static void
metadata_updated (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(metadata_updated); DEBUG_FN("OUT\n");
}

static void
connection_error (sp_session *session, sp_error error)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(connection_error, error); DEBUG_FN("OUT\n");
}

static void
message_to_user (sp_session *session, const char *message)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(message_to_user, message); DEBUG_FN("OUT\n");
}

static void
notify_main_thread (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(notify_main_thread); DEBUG_FN("OUT\n");
}

static int
music_delivery (sp_session *session, const sp_audioformat *format,
                const void *frames, int num_frames)
{
  DEBUG_FN("IN\n");
  int ret = 0;
  DISPATCH_CALLBACK_WITH_RETURN(ret, music_delivery, format, frames, num_frames); DEBUG_FN("OUT\n");
  return ret;
}

static void
play_token_lost (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(play_token_lost); DEBUG_FN("OUT\n");
}

static void
log_message (sp_session *session, const char *data)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(log_message, data); DEBUG_FN("OUT\n");
}

static void
end_of_track (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(end_of_track); DEBUG_FN("OUT\n");
}

static void
streaming_error (sp_session *session, sp_error error)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(streaming_error, error); DEBUG_FN("OUT\n");
}

static void
userinfo_updated (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(userinfo_updated); DEBUG_FN("OUT\n");
}

static void
start_playback (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(start_playback); DEBUG_FN("OUT\n");
}

static void
stop_playback (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(stop_playback); DEBUG_FN("OUT\n");
}

static void
get_audio_buffer_stats (sp_session *session, sp_audio_buffer_stats *stats)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(get_audio_buffer_stats, stats); DEBUG_FN("OUT\n");
}

static void
offline_status_updated (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(offline_status_updated); DEBUG_FN("OUT\n");
}

static void
offline_error (sp_session *session, sp_error error)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(offline_error, error); DEBUG_FN("OUT\n");
}

static void
credentials_blob_updated (sp_session *session, const char *blob)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(credentials_blob_updated, blob); DEBUG_FN("OUT\n");
}

static void
connectionstate_updated (sp_session *session)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(connectionstate_updated); DEBUG_FN("OUT\n");
}

static void
scrobble_error (sp_session *session, sp_error error)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(scrobble_error, error); DEBUG_FN("OUT\n");
}

static void
private_session_mode_changed (sp_session *session, bool is_private)
{
  DEBUG_FN("IN\n");
  DISPATCH_CALLBACK(private_session_mode_changed, is_private); DEBUG_FN("OUT\n");
}

/* This code is autogenerated by codegen.py --api */
#include "autogen_api.c"
