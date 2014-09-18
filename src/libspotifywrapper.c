#include <libspotify/api.h>
#include <malloc.h>


#ifdef WITH_DEBUG

#define DEBUG(str, ...) printf(str, ## __VA_ARGS__)
#define DEBUG_FN(str, ...) printf("(%d): %s: " str, __LINE__, __func__, ## __VA_ARGS__)

#else

#define DEBUG(str, ...)    // Do Nothing
#define DEBUG_FN(str, ...) // Do Nothing

#endif

static void logged_in(sp_session *session, sp_error error);
static void logged_out(sp_session *session);
static void metadata_updated(sp_session *session);
static void connection_error(sp_session *session, sp_error error);
static void message_to_user(sp_session *session, const char *message);
static void notify_main_thread(sp_session *session);
static int music_delivery(sp_session *session, const sp_audioformat *format, const void *frames, int num_frames);
static void play_token_lost(sp_session *session);
static void log_message(sp_session *session, const char *data);
static void end_of_track(sp_session *session);
static void streaming_error(sp_session *session, sp_error error);
static void userinfo_updated(sp_session *session);
static void start_playback(sp_session *session);
static void stop_playback(sp_session *session);
static void get_audio_buffer_stats(sp_session *session, sp_audio_buffer_stats *stats);
static void offline_status_updated(sp_session *session);
static void offline_error(sp_session *session, sp_error error);
static void credentials_blob_updated(sp_session *session, const char *blob);
static void connectionstate_updated(sp_session *session);
static void scrobble_error(sp_session *session, sp_error error);
static void private_session_mode_changed(sp_session *session, bool is_private);

static sp_session *g_session = (sp_session *)NULL;
static unsigned int g_logged_in = 0;
static unsigned int g_nclients = 0;

static sp_session_callbacks g_callbacks = {
    &logged_in,
    &logged_out,
	&metadata_updated,
	&connection_error,
	&message_to_user,
	&notify_main_thread,
	&music_delivery,
	&play_token_lost,
	&log_message,
	&end_of_track,
	&streaming_error,
	&userinfo_updated,
	&start_playback,
	&stop_playback,
	&get_audio_buffer_stats,
	&offline_status_updated,
	&offline_error,
	&credentials_blob_updated,
	&connectionstate_updated,
	&scrobble_error,
	&private_session_mode_changed
};

typedef struct spw_session_s
{
	sp_session            *s;
    sp_session_callbacks  cb;
    struct spw_session_s  *next;
    struct spw_session_s  *prev;
} spw_session;

static spw_session *g_head, *g_tail;

#define SPW_SESSION(sess) ((spw_session *)sess)
#define SP_SESSION(sess)  SPW_SESSION(sess)->s

static void dump_linked_list(void)
{
	spw_session *p = g_head;
	DEBUG_FN("g_head = %p g_tail = %p\n", g_head, g_tail);
	unsigned int i = 0;
	while (p)
	{
		DEBUG_FN("Element %p at index %d\n", p, i);
		p = p->next;
		i++;
	}
}

static spw_session *spw_alloc_session(const sp_session_config *config)
{
	DEBUG_FN("IN\n");

	spw_session *spw = (spw_session *)malloc(sizeof(spw_session));
    if (spw == NULL)
    	return NULL;

    spw->cb = *config->callbacks;
    spw->s = g_session;
    if (g_nclients == 0)
    {
    	g_head = g_tail = spw;
    	spw->next = NULL;
    	spw->prev = NULL;
    }
    else
    {
    	spw->next = NULL;
    	spw->prev = g_tail;
    	g_tail->next = spw;
    	g_tail = spw;
    }

    g_nclients++;
	DEBUG_FN("g_nclients = %d\n", g_nclients);

#ifdef WITH_DEBUG
	dump_linked_list();
#endif

	DEBUG_FN("OUT\n");
    return spw;
}

static void spw_free_session(spw_session *spw)
{
	DEBUG_FN("IN\n");
	if (spw->next)
		spw->next->prev = spw->prev;
	if (spw->prev)
		spw->prev->next = spw->next;
	if (spw == g_tail)
		g_tail = spw->prev;
	if (spw == g_head)
		g_head = spw->next;
	free((void *)spw);
	g_nclients--;
	DEBUG_FN("g_nclients = %d\n", g_nclients);

#ifdef WITH_DEBUG
	dump_linked_list();
#endif

	DEBUG_FN("OUT\n");
}

SP_LIBEXPORT(sp_error) spw_session_create(const sp_session_config *config, sp_session **sess)
{
	DEBUG_FN("IN\n");
	sp_error ret = SP_ERROR_OK;

	if (g_session == NULL)
	{
		sp_session_config local = *config;
		local.callbacks = &g_callbacks;
		ret = sp_session_create(&local, &g_session);
		DEBUG_FN("Created new g_session %p\n", g_session);
	}

	if (ret == SP_ERROR_OK)
	{
		spw_session *spw = spw_alloc_session(config);
		*sess = (sp_session *)spw;
		DEBUG_FN("Created spw %p\n", spw);
	}

	DEBUG_FN("OUT\n");
	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_release(sp_session *sess)
{
	DEBUG_FN("IN\n");
	sp_error ret = SP_ERROR_OK;

	spw_free_session(SPW_SESSION(sess));
	if (g_nclients == 0)
	{
		ret = sp_session_release(g_session);
		g_session = (sp_session *)NULL;
	}

	DEBUG_FN("OUT\n");
	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_login(sp_session *session, const char *username, const char *password, bool remember_me, const char *blob)
{
	DEBUG_FN("IN\n");
	sp_error ret = SP_ERROR_OK;

	//if (g_logged_in == 0)
	ret = sp_session_login(SP_SESSION(session), username, password, remember_me, blob);
	//else if (SPW_SESSION(session)->cb.logged_in)
	//	SPW_SESSION(session)->cb.logged_in(session, SP_ERROR_OK);

	//if (ret == SP_ERROR_OK)
	//	g_logged_in = 1;
	DEBUG_FN("OUT\n");
	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_relogin(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_relogin(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(int) spw_session_remembered_user(sp_session *session, char *buffer, size_t buffer_size)
{
	DEBUG_FN("IN\n");
	int ret = sp_session_remembered_user(SP_SESSION(session), buffer, buffer_size);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(const char *) spw_session_user_name(sp_session *session)
{
	DEBUG_FN("IN\n");
	const char *ret = sp_session_user_name(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_forget_me(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_forget_me(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_user *) spw_session_user(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_user *ret = sp_session_user(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_logout(sp_session *session)
{
	DEBUG_FN("IN\n");
	//if (g_logged_in > 0)
	//	g_logged_in--;
	sp_error ret = SP_ERROR_OK;
	//if (g_logged_in == 0)
	ret = sp_session_logout(SP_SESSION(session));
	//else if (SPW_SESSION(session)->cb.logged_out)
	//	SPW_SESSION(session)->cb.logged_out(session);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_flush_caches(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_flush_caches(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_connectionstate) spw_session_connectionstate(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_connectionstate ret = sp_session_connectionstate(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(void *) spw_session_userdata(sp_session *session)
{
	DEBUG_FN("IN\n");
	void *ret = sp_session_userdata(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_cache_size(sp_session *session, size_t size)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_cache_size(SP_SESSION(session), size);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_process_events(sp_session *session, int *next_timeout)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_process_events(SP_SESSION(session), next_timeout);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_player_load(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_player_load(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_player_seek(sp_session *session, int offset)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_player_seek(SP_SESSION(session), offset);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_player_play(sp_session *session, bool play)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_player_play(SP_SESSION(session), play);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_player_unload(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_player_unload(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_player_prefetch(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_player_prefetch(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlistcontainer *) spw_session_playlistcontainer(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_playlistcontainer *ret = sp_session_playlistcontainer(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlist *) spw_session_inbox_create(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_playlist *ret = sp_session_inbox_create(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlist *) spw_session_starred_create(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_playlist *ret = sp_session_starred_create(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlist *) spw_session_starred_for_user_create(sp_session *session, const char *canonical_username)
{
	DEBUG_FN("IN\n");
	sp_playlist *ret = sp_session_starred_for_user_create(SP_SESSION(session), canonical_username);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlistcontainer *) spw_session_publishedcontainer_for_user_create(sp_session *session, const char *canonical_username)
{
	DEBUG_FN("IN\n");
	sp_playlistcontainer *ret = sp_session_publishedcontainer_for_user_create(SP_SESSION(session), canonical_username);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_preferred_bitrate(sp_session *session, sp_bitrate bitrate)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_preferred_bitrate(SP_SESSION(session), bitrate);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_preferred_offline_bitrate(sp_session *session, sp_bitrate bitrate, bool allow_resync)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_preferred_offline_bitrate(SP_SESSION(session), bitrate, allow_resync);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_session_get_volume_normalization(sp_session *session)
{
	DEBUG_FN("IN\n");
	bool ret = sp_session_get_volume_normalization(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_volume_normalization(sp_session *session, bool on)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_volume_normalization(SP_SESSION(session), on);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_private_session(sp_session *session, bool enabled)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_private_session(SP_SESSION(session), enabled);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_session_is_private_session(sp_session *session)
{
	DEBUG_FN("IN\n");
	bool ret = sp_session_is_private_session(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state state)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_scrobbling(SP_SESSION(session), provider, state);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_is_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state* state)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_is_scrobbling(SP_SESSION(session), provider, state);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_is_scrobbling_possible(sp_session *session, sp_social_provider provider, bool* out)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_is_scrobbling_possible(SP_SESSION(session), provider, out);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_social_credentials(sp_session *session, sp_social_provider provider, const char* username, const char* password)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_social_credentials(SP_SESSION(session), provider, username, password);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_connection_type(sp_session *session, sp_connection_type type)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_connection_type(SP_SESSION(session), type);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_session_set_connection_rules(sp_session *session, sp_connection_rules rules)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_session_set_connection_rules(SP_SESSION(session), rules);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(int) spw_offline_tracks_to_sync(sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_offline_tracks_to_sync(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(int) spw_offline_num_playlists(sp_session *session)
{
	DEBUG_FN("IN\n");
	int ret = sp_offline_num_playlists(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_offline_sync_get_status(sp_session *session, sp_offline_sync_status *status)
{
	DEBUG_FN("IN\n");
	bool ret = sp_offline_sync_get_status(SP_SESSION(session), status);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(int) spw_offline_time_left(sp_session *session)
{
	DEBUG_FN("IN\n");
	int ret = sp_offline_time_left(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(int) spw_session_user_country(sp_session *session)
{
	DEBUG_FN("IN\n");
	int ret = sp_session_user_country(SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_track_availability) spw_track_get_availability(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	sp_track_availability ret = sp_track_get_availability(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_track_is_local(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	bool ret = sp_track_is_local(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_track_is_autolinked(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	bool ret = sp_track_is_autolinked(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_track *) spw_track_get_playable(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	sp_track *ret = sp_track_get_playable(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_track_is_starred(sp_session *session, sp_track *track)
{
	DEBUG_FN("IN\n");
	bool ret = sp_track_is_starred(SP_SESSION(session), track);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_track_set_starred(sp_session *session, sp_track *const*tracks, int num_tracks, bool star)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_track_set_starred(SP_SESSION(session), tracks, num_tracks, star);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_albumbrowse *) spw_albumbrowse_create(sp_session *session, sp_album *album, albumbrowse_complete_cb *callback, void *userdata)
{
	DEBUG_FN("IN\n");
	sp_albumbrowse *ret = sp_albumbrowse_create(SP_SESSION(session), album, callback, userdata);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_artistbrowse *) spw_artistbrowse_create(sp_session *session, sp_artist *artist, sp_artistbrowse_type type, artistbrowse_complete_cb *callback, void *userdata)
{
	DEBUG_FN("IN\n");
	sp_artistbrowse *ret = sp_artistbrowse_create(SP_SESSION(session), artist, type, callback, userdata);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_image *) spw_image_create(sp_session *session, const byte image_id[20])
{
	DEBUG_FN("IN\n");
	sp_image *ret = sp_image_create(SP_SESSION(session), image_id);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_image *) spw_image_create_from_link(sp_session *session, sp_link *l)
{
	DEBUG_FN("IN\n");
	sp_image *ret = sp_image_create_from_link(SP_SESSION(session), l);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_search *) spw_search_create(sp_session *session, const char *query, int track_offset, int track_count, int album_offset, int album_count, int artist_offset, int artist_count, int playlist_offset, int playlist_count, sp_search_type search_type, search_complete_cb *callback, void *userdata)
{
	DEBUG_FN("IN\n");
	sp_search *ret = sp_search_create(SP_SESSION(session), query, track_offset, track_count, album_offset, album_count, artist_offset, artist_count, playlist_offset, playlist_count, search_type, callback, userdata);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_playlist_add_tracks(sp_playlist *playlist, sp_track *const*tracks, int num_tracks, int position, sp_session *session)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_playlist_add_tracks(playlist, tracks, num_tracks, position, SP_SESSION(session));
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_playlist_update_subscribers(sp_session *session, sp_playlist *playlist)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_playlist_update_subscribers(SP_SESSION(session), playlist);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(bool) spw_playlist_is_in_ram(sp_session *session, sp_playlist *playlist)
{
	DEBUG_FN("IN\n");
	bool ret = sp_playlist_is_in_ram(SP_SESSION(session), playlist);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_playlist_set_in_ram(sp_session *session, sp_playlist *playlist, bool in_ram)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_playlist_set_in_ram(SP_SESSION(session), playlist, in_ram);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlist *) spw_playlist_create(sp_session *session, sp_link *link)
{
	DEBUG_FN("IN\n");
	sp_playlist *ret = sp_playlist_create(SP_SESSION(session), link);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_error) spw_playlist_set_offline_mode(sp_session *session, sp_playlist *playlist, bool offline)
{
	DEBUG_FN("IN\n");
	sp_error ret = sp_playlist_set_offline_mode(SP_SESSION(session), playlist, offline);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_playlist_offline_status) spw_playlist_get_offline_status(sp_session *session, sp_playlist *playlist)
{
	DEBUG_FN("IN\n");
	sp_playlist_offline_status ret = sp_playlist_get_offline_status(SP_SESSION(session), playlist);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(int) spw_playlist_get_offline_download_completed(sp_session *session, sp_playlist *playlist)
{
	DEBUG_FN("IN\n");
	int ret = sp_playlist_get_offline_download_completed(SP_SESSION(session), playlist);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_toplistbrowse *) spw_toplistbrowse_create(sp_session *session, sp_toplisttype type, sp_toplistregion region, const char *username, toplistbrowse_complete_cb *callback, void *userdata)
{
	DEBUG_FN("IN\n");
	sp_toplistbrowse *ret = sp_toplistbrowse_create(SP_SESSION(session), type, region, username, callback, userdata);
	DEBUG_FN("OUT\n");

	return ret;
}

SP_LIBEXPORT(sp_inbox *) spw_inbox_post_tracks(sp_session *session, const char *user, sp_track * const *tracks, int num_tracks, const char *message, inboxpost_complete_cb *callback, void *userdata)
{
	DEBUG_FN("IN\n");
	sp_inbox *ret = sp_inbox_post_tracks(SP_SESSION(session), user, tracks, num_tracks, message, callback, userdata);
	DEBUG_FN("OUT\n");

	return ret;
}

// Callbacks

#define DISPATCH_CALLBACK(cb_name, ...) \
	spw_session *p = g_head; \
	while (p) \
	{ \
		if (p->cb.cb_name) { \
			DEBUG_FN("Calling user callback\n"); \
			p->cb.cb_name((sp_session *)p, ## __VA_ARGS__); \
		} \
		p = p->next; \
	}

#define DISPATCH_CALLBACK_WITH_RETURN(ret, cb_name, ...) \
	spw_session *p = g_head; \
	while (p) \
	{ \
		if (p->cb.cb_name) { \
			DEBUG_FN("Calling user callback\n"); \
			ret = p->cb.cb_name((sp_session *)p, ## __VA_ARGS__); \
		} \
		p = p->next; \
	}


static void logged_in(sp_session *session, sp_error error)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(logged_in, error);
	DEBUG_FN("OUT\n");
}

static void logged_out(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(logged_out);
	DEBUG_FN("OUT\n");
}

static void metadata_updated(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(metadata_updated);
	DEBUG_FN("OUT\n");
}

static void connection_error(sp_session *session, sp_error error)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(connection_error, error);
	DEBUG_FN("OUT\n");
}

static void message_to_user(sp_session *session, const char *message)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(message_to_user, message);
	DEBUG_FN("OUT\n");
}

static void notify_main_thread(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(notify_main_thread);
	DEBUG_FN("OUT\n");
}

static int music_delivery(sp_session *session, const sp_audioformat *format, const void *frames, int num_frames)
{
	DEBUG_FN("IN\n");
	int ret = 0;
	DISPATCH_CALLBACK_WITH_RETURN(ret, music_delivery, format, frames, num_frames);
	DEBUG_FN("OUT\n");
	return ret;
}

static void play_token_lost(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(play_token_lost);
	DEBUG_FN("OUT\n");
}

static void log_message(sp_session *session, const char *data)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(log_message, data);
	DEBUG_FN("OUT\n");
}

static void end_of_track(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(end_of_track);
	DEBUG_FN("OUT\n");
}

static void streaming_error(sp_session *session, sp_error error)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(streaming_error, error);
	DEBUG_FN("OUT\n");
}

static void userinfo_updated(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(userinfo_updated);
	DEBUG_FN("OUT\n");
}

static void start_playback(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(start_playback);
	DEBUG_FN("OUT\n");
}

static void stop_playback(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(stop_playback);
	DEBUG_FN("OUT\n");
}

static void get_audio_buffer_stats(sp_session *session, sp_audio_buffer_stats *stats)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(get_audio_buffer_stats, stats);
	DEBUG_FN("OUT\n");
}

static void offline_status_updated(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(offline_status_updated);
	DEBUG_FN("OUT\n");
}

static void offline_error(sp_session *session, sp_error error)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(offline_error, error);
	DEBUG_FN("OUT\n");
}

static void credentials_blob_updated(sp_session *session, const char *blob)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(credentials_blob_updated, blob);
	DEBUG_FN("OUT\n");
}

static void connectionstate_updated(sp_session *session)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(connectionstate_updated);
	DEBUG_FN("OUT\n");
}

static void scrobble_error(sp_session *session, sp_error error)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(scrobble_error, error);
	DEBUG_FN("OUT\n");
}

static void private_session_mode_changed(sp_session *session, bool is_private)
{
	DEBUG_FN("IN\n");
	DISPATCH_CALLBACK(private_session_mode_changed, is_private);
	DEBUG_FN("OUT\n");
}
