sp_track * sp_playlist_track(sp_playlist *playlist, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_playlist_track(playlist, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artistbrowse * sp_artistbrowse_create(sp_session *session, sp_artist *artist, sp_artistbrowse_type type, artistbrowse_complete_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artistbrowse * ret;
  ret = g_libspotify.sp_artistbrowse_create(g_session, artist, type, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_user_canonical_name(sp_user *user)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_user_canonical_name(user);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_albumbrowse_review(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_albumbrowse_review(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_connection_type(sp_session *session, sp_connection_type type)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_connection_type(g_session, type);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlist_track_seen(sp_playlist *playlist, int index)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlist_track_seen(playlist, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_user_release(sp_user *user)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_user_release(user);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_offline_sync_get_status(sp_session *session, sp_offline_sync_status *status)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_offline_sync_get_status(g_session, status);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_toplistbrowse_backend_request_duration(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_toplistbrowse_backend_request_duration(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track_offline_status sp_track_offline_get_status(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track_offline_status ret;
  ret = g_libspotify.sp_track_offline_get_status(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlistcontainer * sp_session_publishedcontainer_for_user_create(sp_session *session, const char *canonical_username)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlistcontainer * ret;
  ret = g_libspotify.sp_session_publishedcontainer_for_user_create(g_session, canonical_username);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_search_is_loaded(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_search_is_loaded(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_forget_me(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_forget_me(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_link_as_artist(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_link_as_artist(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_cache_size(sp_session *session, size_t size)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_cache_size(g_session, size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_playlist_track_create_time(sp_playlist *playlist, int index)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_playlist_track_create_time(playlist, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_num_playlists(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_num_playlists(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_preferred_bitrate(sp_session *session, sp_bitrate bitrate)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_preferred_bitrate(g_session, bitrate);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_artistbrowse_artist(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_artistbrowse_artist(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_image * sp_image_create(sp_session *session, const byte image_id[20])
{
  DEBUG_FN("IN\n");
  lock();
  sp_image * ret;
  ret = g_libspotify.sp_image_create(g_session, image_id[20]);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_add_ref(sp_playlistcontainer *pc)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_add_ref(pc);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_search_release(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_search_release(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_release(sp_playlistcontainer *pc)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_release(pc);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_albumbrowse * sp_albumbrowse_create(sp_session *session, sp_album *album, albumbrowse_complete_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_albumbrowse * ret;
  ret = g_libspotify.sp_albumbrowse_create(g_session, album, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_remove_tracks(sp_playlist *playlist, const int *tracks, int num_tracks)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_remove_tracks(playlist, tracks, num_tracks);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlistcontainer_is_loaded(sp_playlistcontainer *pc)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlistcontainer_is_loaded(pc);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_is_scrobbling_possible(sp_session *session, sp_social_provider provider, bool* out)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_is_scrobbling_possible(g_session, provider, out);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_artistbrowse_error(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_artistbrowse_error(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_toplistbrowse_is_loaded(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_toplistbrowse_is_loaded(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_image_remove_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_image_remove_load_callback(image, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_link_as_string(sp_link *link, char *buffer, int buffer_size)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_link_as_string(link, buffer, buffer_size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_add_tracks(sp_playlist *playlist, sp_track *const*tracks, int num_tracks, int position, sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_add_tracks(playlist, tracks, num_tracks, position, g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlist_is_in_ram(sp_session *session, sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlist_is_in_ram(g_session, playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_artistbrowse_biography(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_artistbrowse_biography(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char* sp_error_message(sp_error error)
{
  DEBUG_FN("IN\n");
  lock();
  const char* ret;
  ret = g_libspotify.sp_error_message(error);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state state)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_scrobbling(g_session, provider, state);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_playlist_get_description(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_playlist_get_description(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_album_name(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_album_name(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_total_albums(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_total_albums(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_albumbrowse_artist(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_albumbrowse_artist(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_session_starred_for_user_create(sp_session *session, const char *canonical_username)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_session_starred_for_user_create(g_session, canonical_username);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_albumbrowse_num_copyrights(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_albumbrowse_num_copyrights(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_artistbrowse_portrait(sp_artistbrowse *arb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_artistbrowse_portrait(arb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_link_add_ref(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_link_add_ref(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_toplistbrowse_error(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_toplistbrowse_error(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_track_error(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_track_error(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_add_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_add_callbacks(playlist, callbacks, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_search_playlist_uri(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_search_playlist_uri(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_session_starred_create(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_session_starred_create(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_user_is_loaded(sp_user *user)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_user_is_loaded(user);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track_availability sp_track_get_availability(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track_availability ret;
  ret = g_libspotify.sp_track_get_availability(g_session, track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_player_unload(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_player_unload(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_search * sp_search_create(sp_session *session, const char *query, int track_offset, int track_count, int album_offset, int album_count, int artist_offset, int artist_count, int playlist_offset, int playlist_count, sp_search_type search_type, search_complete_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_search * ret;
  ret = g_libspotify.sp_search_create(g_session, query, track_offset, track_count, album_offset, album_count, artist_offset, artist_count, playlist_offset, playlist_count, search_type, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_session_user_name(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_session_user_name(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_set_autolink_tracks(sp_playlist *playlist, bool link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_set_autolink_tracks(playlist, link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_search(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_search(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_preferred_offline_bitrate(sp_session *session, sp_bitrate bitrate, bool allow_resync)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_preferred_offline_bitrate(g_session, bitrate, allow_resync);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_playlist_folder_name(sp_playlistcontainer *pc, int index, char *buffer, int buffer_size)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_playlist_folder_name(pc, index, buffer, buffer_size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_album * sp_albumbrowse_album(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_album * ret;
  ret = g_libspotify.sp_albumbrowse_album(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_toplistbrowse_track(sp_toplistbrowse *tlb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_toplistbrowse_track(tlb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_session_get_volume_normalization(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_session_get_volume_normalization(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_num_tracks(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_num_tracks(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_playlistcontainer_get_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist, sp_track **tracks, int num_tracks)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_playlistcontainer_get_unseen_tracks(pc, playlist, tracks, num_tracks);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const byte * sp_artistbrowse_portrait(sp_artistbrowse *arb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  const byte * ret;
  ret = g_libspotify.sp_artistbrowse_portrait(arb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_total_tracks(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_total_tracks(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_artistbrowse_add_ref(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_artistbrowse_add_ref(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_search_add_ref(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_search_add_ref(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_search_error(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_search_error(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_toplistbrowse_release(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_toplistbrowse_release(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_toplistbrowse_artist(sp_toplistbrowse *tlb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_toplistbrowse_artist(tlb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_image_add_ref(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_image_add_ref(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_update_subscribers(sp_session *session, sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_update_subscribers(g_session, playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist_type sp_playlistcontainer_playlist_type(sp_playlistcontainer *pc, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist_type ret;
  ret = g_libspotify.sp_playlistcontainer_playlist_type(pc, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_toplistbrowse_num_albums(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_toplistbrowse_num_albums(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_flush_caches(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_flush_caches(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_track_set_seen(sp_playlist *playlist, int index, bool seen)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_track_set_seen(playlist, index, seen);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_image_error(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_image_error(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_image_release(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_image_release(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_playlist_create(sp_session *session, sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_playlist_create(g_session, link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist_offline_status sp_playlist_get_offline_status(sp_session *session, sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist_offline_status ret;
  ret = g_libspotify.sp_playlist_get_offline_status(g_session, playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_artistbrowse_num_portraits(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_artistbrowse_num_portraits(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_search_playlist(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_search_playlist(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_track_popularity(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_track_popularity(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_inbox_release(sp_inbox *inbox)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_inbox_release(inbox);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_user * sp_session_user(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_user * ret;
  ret = g_libspotify.sp_session_user(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_albumbrowse_error(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_albumbrowse_error(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_inbox_error(sp_inbox *inbox)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_inbox_error(inbox);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_artistbrowse_track(sp_artistbrowse *arb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_artistbrowse_track(arb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_albumbrowse_add_ref(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_albumbrowse_add_ref(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_user * sp_playlistcontainer_owner(sp_playlistcontainer *pc)
{
  DEBUG_FN("IN\n");
  lock();
  sp_user * ret;
  ret = g_libspotify.sp_playlistcontainer_owner(pc);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_album_is_available(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_album_is_available(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_toplistbrowse_num_artists(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_toplistbrowse_num_artists(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

void * sp_session_userdata(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  void * ret;
  ret = g_libspotify.sp_session_userdata(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_albumbrowse_release(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_albumbrowse_release(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_toplistbrowse_num_tracks(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_toplistbrowse_num_tracks(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_user * sp_playlist_owner(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_user * ret;
  ret = g_libspotify.sp_playlist_owner(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_inbox * sp_inbox_post_tracks(sp_session *session, const char *user, sp_track * const *tracks, int num_tracks, const char *message, inboxpost_complete_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_inbox * ret;
  ret = g_libspotify.sp_inbox_post_tracks(g_session, user, tracks, num_tracks, message, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_uint64 sp_playlistcontainer_playlist_folder_id(sp_playlistcontainer *pc, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_uint64 ret;
  ret = g_libspotify.sp_playlistcontainer_playlist_folder_id(pc, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_track_add_ref(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_track_add_ref(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_user(sp_user *user)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_user(user);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlist_is_collaborative(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlist_is_collaborative(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_imageformat sp_image_format(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  sp_imageformat ret;
  ret = g_libspotify.sp_image_format(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_num_artists(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_num_artists(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const void * sp_image_data(sp_image *image, size_t *data_size)
{
  DEBUG_FN("IN\n");
  lock();
  const void * ret;
  ret = g_libspotify.sp_image_data(image, data_size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_localtrack_create(const char *artist, const char *title, const char *album, int length)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_localtrack_create(artist, title, album, length);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_albumbrowse_copyright(sp_albumbrowse *alb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_albumbrowse_copyright(alb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_album * sp_search_album(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_album * ret;
  ret = g_libspotify.sp_search_album(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_connection_rules(sp_session *session, sp_connection_rules rules)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_connection_rules(g_session, rules);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_offline_num_playlists(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_offline_num_playlists(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_album * sp_track_album(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_album * ret;
  ret = g_libspotify.sp_track_album(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_track_name(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_track_name(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_total_playlists(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_total_playlists(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_reorder_tracks(sp_playlist *playlist, const int *tracks, int num_tracks, int new_position)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_reorder_tracks(playlist, tracks, num_tracks, new_position);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_volume_normalization(sp_session *session, bool on)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_volume_normalization(g_session, on);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_track_set_starred(sp_session *session, sp_track *const*tracks, int num_tracks, bool star)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_track_set_starred(g_session, tracks, num_tracks, star);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_artist_is_loaded(sp_artist *artist)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_artist_is_loaded(artist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_albumbrowse_track(sp_albumbrowse *alb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_albumbrowse_track(alb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_link_as_track_and_offset(sp_link *link, int *offset)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_link_as_track_and_offset(link, offset);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_artistbrowse_similar_artist(sp_artistbrowse *arb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_artistbrowse_similar_artist(arb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_connectionstate sp_session_connectionstate(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_connectionstate ret;
  ret = g_libspotify.sp_session_connectionstate(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_playlist_get_offline_download_completed(sp_session *session, sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_playlist_get_offline_download_completed(g_session, playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_remove_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_remove_callbacks(playlist, callbacks, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_image_is_loaded(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_image_is_loaded(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_remove_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_remove_callbacks(pc, callbacks, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_albumbrowse_backend_request_duration(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_albumbrowse_backend_request_duration(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_subscribers_free(sp_subscribers *subscribers)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_subscribers_free(subscribers);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_search_playlist_image_uri(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_search_playlist_image_uri(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_track_artist(sp_track *track, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_track_artist(track, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_session_is_private_session(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_session_is_private_session(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_albumbrowse_num_tracks(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_albumbrowse_num_tracks(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_session_remembered_user(sp_session *session, char *buffer, size_t buffer_size)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_session_remembered_user(g_session, buffer, buffer_size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

unsigned int sp_playlist_num_subscribers(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  unsigned int ret;
  ret = g_libspotify.sp_playlist_num_subscribers(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_user_display_name(sp_user *user)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_user_display_name(user);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_toplistbrowse_add_ref(sp_toplistbrowse *tlb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_toplistbrowse_add_ref(tlb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlist_is_loaded(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlist_is_loaded(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlist_get_image(sp_playlist *playlist, byte image[20])
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlist_get_image(playlist, image[20]);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_image * sp_image_create_from_link(sp_session *session, sp_link *l)
{
  DEBUG_FN("IN\n");
  lock();
  sp_image * ret;
  ret = g_libspotify.sp_image_create_from_link(g_session, l);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_album_year(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_album_year(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_search_track(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_search_track(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_albumbrowse_is_loaded(sp_albumbrowse *alb)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_albumbrowse_is_loaded(alb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_artist_portrait(sp_artist *artist, sp_image_size size)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_artist_portrait(artist, size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_album_artist(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_album_artist(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_offline_tracks_to_sync(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_offline_tracks_to_sync(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_player_prefetch(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_player_prefetch(g_session, track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_rename(sp_playlist *playlist, const char *new_name)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_rename(playlist, new_name);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_artist_release(sp_artist *artist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_artist_release(artist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_artist_name(sp_artist *artist)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_artist_name(artist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_playlist_has_pending_changes(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_playlist_has_pending_changes(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_track_is_local(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_track_is_local(g_session, track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_album_is_loaded(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_album_is_loaded(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_album_cover(sp_album *album, sp_image_size size)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_album_cover(album, size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_search_did_you_mean(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_search_did_you_mean(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const byte * sp_artist_portrait(sp_artist *artist, sp_image_size size)
{
  DEBUG_FN("IN\n");
  lock();
  const byte * ret;
  ret = g_libspotify.sp_artist_portrait(artist, size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_is_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state* state)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_is_scrobbling(g_session, provider, state);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_album * sp_toplistbrowse_album(sp_toplistbrowse *tlb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_album * ret;
  ret = g_libspotify.sp_toplistbrowse_album(tlb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_linktype sp_link_type(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_linktype ret;
  ret = g_libspotify.sp_link_type(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_num_albums(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_num_albums(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_build_id(void)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_build_id();
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_playlist(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_playlist(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_subscribers * sp_playlist_subscribers(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_subscribers * ret;
  ret = g_libspotify.sp_playlist_subscribers(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_playlistcontainer_playlist(sp_playlistcontainer *pc, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_playlistcontainer_playlist(pc, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_social_credentials(sp_session *session, sp_social_provider provider, const char* username, const char* password)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_social_credentials(g_session, provider, username, password);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_playlist_track_message(sp_playlist *playlist, int index)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_playlist_track_message(playlist, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_user * sp_link_as_user(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_user * ret;
  ret = g_libspotify.sp_link_as_user(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_artist * sp_search_artist(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_artist * ret;
  ret = g_libspotify.sp_search_artist(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_player_seek(sp_session *session, int offset)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_player_seek(g_session, offset);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_track_disc(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_track_disc(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_album_release(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_album_release(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_move_playlist(sp_playlistcontainer *pc, int index, int new_position, bool dry_run)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_move_playlist(pc, index, new_position, dry_run);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_playlistcontainer_num_playlists(sp_playlistcontainer *pc)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_playlistcontainer_num_playlists(pc);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_toplistbrowse * sp_toplistbrowse_create(sp_session *session, sp_toplisttype type, sp_toplistregion region, const char *username, toplistbrowse_complete_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_toplistbrowse * ret;
  ret = g_libspotify.sp_toplistbrowse_create(g_session, type, region, username, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_user * sp_playlist_track_creator(sp_playlist *playlist, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_user * ret;
  ret = g_libspotify.sp_playlist_track_creator(playlist, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_artistbrowse_is_loaded(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_artistbrowse_is_loaded(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_set_collaborative(sp_playlist *playlist, bool collaborative)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_set_collaborative(playlist, collaborative);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_track_duration(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_track_duration(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_playlist_num_tracks(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_playlist_num_tracks(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_artistbrowse_tophit_track(sp_artistbrowse *arb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_artistbrowse_tophit_track(arb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_artistbrowse_num_tracks(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_artistbrowse_num_tracks(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_add_ref(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_add_ref(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_release(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_release(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_set_offline_mode(sp_session *session, sp_playlist *playlist, bool offline)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_set_offline_mode(g_session, playlist, offline);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_add_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_add_callbacks(pc, callbacks, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_playlist_name(sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_playlist_name(playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlist_set_in_ram(sp_session *session, sp_playlist *playlist, bool in_ram)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlist_set_in_ram(g_session, playlist, in_ram);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_link_as_track(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_link_as_track(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_offline_time_left(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_offline_time_left(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_set_private_session(sp_session *session, bool enabled)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_set_private_session(g_session, enabled);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_session_user_country(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_session_user_country(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_track_is_autolinked(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_track_is_autolinked(g_session, track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_search_total_artists(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_search_total_artists(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_inbox_add_ref(sp_inbox *inbox)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_inbox_add_ref(inbox);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_track(sp_track *track, int offset)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_track(track, offset);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_album_add_ref(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_album_add_ref(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_player_play(sp_session *session, bool play)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_player_play(g_session, play);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_link_release(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_link_release(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const byte * sp_album_cover(sp_album *album, sp_image_size size)
{
  DEBUG_FN("IN\n");
  lock();
  const byte * ret;
  ret = g_libspotify.sp_album_cover(album, size);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_remove_playlist(sp_playlistcontainer *pc, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_remove_playlist(pc, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const byte * sp_image_image_id(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  const byte * ret;
  ret = g_libspotify.sp_image_image_id(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_playlistcontainer_add_folder(sp_playlistcontainer *pc, int index, const char *name)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_playlistcontainer_add_folder(pc, index, name);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_artistbrowse_num_tophit_tracks(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_artistbrowse_num_tophit_tracks(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_playlistcontainer_add_playlist(sp_playlistcontainer *pc, sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_playlistcontainer_add_playlist(pc, link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_string(const char *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_string(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_artist_add_ref(sp_artist *artist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_artist_add_ref(artist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_album * sp_link_as_album(sp_link *link)
{
  DEBUG_FN("IN\n");
  lock();
  sp_album * ret;
  ret = g_libspotify.sp_link_as_album(link);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_artist(sp_artist *artist)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_artist(artist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_artistbrowse_backend_request_duration(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_artistbrowse_backend_request_duration(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_image(sp_image *image)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_image(image);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_artistbrowse_num_albums(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_artistbrowse_num_albums(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_track_num_artists(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_track_num_artists(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_session_inbox_create(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_session_inbox_create(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_albumtype sp_album_type(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  sp_albumtype ret;
  ret = g_libspotify.sp_album_type(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_track_index(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_track_index(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_track_is_loaded(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_track_is_loaded(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_track * sp_track_get_playable(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_track * ret;
  ret = g_libspotify.sp_track_get_playable(g_session, track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_session_relogin(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_session_relogin(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_artistbrowse_num_similar_artists(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_artistbrowse_num_similar_artists(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlist * sp_playlistcontainer_add_new_playlist(sp_playlistcontainer *pc, const char *name)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlist * ret;
  ret = g_libspotify.sp_playlistcontainer_add_new_playlist(pc, name);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_image_add_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_image_add_load_callback(image, callback, userdata);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_track_is_placeholder(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_track_is_placeholder(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_search_query(sp_search *search)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_search_query(search);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_album * sp_artistbrowse_album(sp_artistbrowse *arb, int index)
{
  DEBUG_FN("IN\n");
  lock();
  sp_album * ret;
  ret = g_libspotify.sp_artistbrowse_album(arb, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

const char * sp_search_playlist_name(sp_search *search, int index)
{
  DEBUG_FN("IN\n");
  lock();
  const char * ret;
  ret = g_libspotify.sp_search_playlist_name(search, index);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_link * sp_link_create_from_album(sp_album *album)
{
  DEBUG_FN("IN\n");
  lock();
  sp_link * ret;
  ret = g_libspotify.sp_link_create_from_album(album);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_track_release(sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_track_release(track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_playlistcontainer * sp_session_playlistcontainer(sp_session *session)
{
  DEBUG_FN("IN\n");
  lock();
  sp_playlistcontainer * ret;
  ret = g_libspotify.sp_session_playlistcontainer(g_session);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_artistbrowse_release(sp_artistbrowse *arb)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_artistbrowse_release(arb);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

int sp_playlistcontainer_clear_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist)
{
  DEBUG_FN("IN\n");
  lock();
  int ret;
  ret = g_libspotify.sp_playlistcontainer_clear_unseen_tracks(pc, playlist);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

sp_error sp_user_add_ref(sp_user *user)
{
  DEBUG_FN("IN\n");
  lock();
  sp_error ret;
  ret = g_libspotify.sp_user_add_ref(user);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

bool sp_track_is_starred(sp_session *session, sp_track *track)
{
  DEBUG_FN("IN\n");
  lock();
  bool ret;
  ret = g_libspotify.sp_track_is_starred(g_session, track);
  unlock();
  DEBUG_FN("OUT\n");
  return ret;
}

