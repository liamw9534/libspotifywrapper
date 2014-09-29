sp_track * sp_playlist_track(sp_playlist *playlist, int index)
{
  return g_libspotify.sp_playlist_track(playlist, index);
}

sp_artistbrowse * sp_artistbrowse_create(sp_session *session, sp_artist *artist, sp_artistbrowse_type type, artistbrowse_complete_cb *callback, void *userdata)
{
  return g_libspotify.sp_artistbrowse_create(g_session, artist, type, callback, userdata);
}

const char * sp_user_canonical_name(sp_user *user)
{
  return g_libspotify.sp_user_canonical_name(user);
}

const char * sp_albumbrowse_review(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_review(alb);
}

sp_error sp_session_set_connection_type(sp_session *session, sp_connection_type type)
{
  return g_libspotify.sp_session_set_connection_type(g_session, type);
}

bool sp_playlist_track_seen(sp_playlist *playlist, int index)
{
  return g_libspotify.sp_playlist_track_seen(playlist, index);
}

sp_error sp_user_release(sp_user *user)
{
  return g_libspotify.sp_user_release(user);
}

bool sp_offline_sync_get_status(sp_session *session, sp_offline_sync_status *status)
{
  return g_libspotify.sp_offline_sync_get_status(g_session, status);
}

int sp_toplistbrowse_backend_request_duration(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_backend_request_duration(tlb);
}

sp_track_offline_status sp_track_offline_get_status(sp_track *track)
{
  return g_libspotify.sp_track_offline_get_status(track);
}

sp_playlistcontainer * sp_session_publishedcontainer_for_user_create(sp_session *session, const char *canonical_username)
{
  return g_libspotify.sp_session_publishedcontainer_for_user_create(g_session, canonical_username);
}

bool sp_search_is_loaded(sp_search *search)
{
  return g_libspotify.sp_search_is_loaded(search);
}

sp_error sp_session_forget_me(sp_session *session)
{
  return g_libspotify.sp_session_forget_me(g_session);
}

sp_artist * sp_link_as_artist(sp_link *link)
{
  return g_libspotify.sp_link_as_artist(link);
}

sp_error sp_session_set_cache_size(sp_session *session, size_t size)
{
  return g_libspotify.sp_session_set_cache_size(g_session, size);
}

int sp_playlist_track_create_time(sp_playlist *playlist, int index)
{
  return g_libspotify.sp_playlist_track_create_time(playlist, index);
}

int sp_search_num_playlists(sp_search *search)
{
  return g_libspotify.sp_search_num_playlists(search);
}

sp_error sp_session_preferred_bitrate(sp_session *session, sp_bitrate bitrate)
{
  return g_libspotify.sp_session_preferred_bitrate(g_session, bitrate);
}

sp_artist * sp_artistbrowse_artist(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_artist(arb);
}

sp_image * sp_image_create(sp_session *session, const byte image_id[20])
{
  return g_libspotify.sp_image_create(g_session, image_id[20]);
}

sp_error sp_playlistcontainer_add_ref(sp_playlistcontainer *pc)
{
  return g_libspotify.sp_playlistcontainer_add_ref(pc);
}

sp_error sp_search_release(sp_search *search)
{
  return g_libspotify.sp_search_release(search);
}

sp_error sp_playlistcontainer_release(sp_playlistcontainer *pc)
{
  return g_libspotify.sp_playlistcontainer_release(pc);
}

sp_albumbrowse * sp_albumbrowse_create(sp_session *session, sp_album *album, albumbrowse_complete_cb *callback, void *userdata)
{
  return g_libspotify.sp_albumbrowse_create(g_session, album, callback, userdata);
}

sp_error sp_playlist_remove_tracks(sp_playlist *playlist, const int *tracks, int num_tracks)
{
  return g_libspotify.sp_playlist_remove_tracks(playlist, tracks, num_tracks);
}

bool sp_playlistcontainer_is_loaded(sp_playlistcontainer *pc)
{
  return g_libspotify.sp_playlistcontainer_is_loaded(pc);
}

sp_error sp_session_is_scrobbling_possible(sp_session *session, sp_social_provider provider, bool* out)
{
  return g_libspotify.sp_session_is_scrobbling_possible(g_session, provider, out);
}

sp_error sp_artistbrowse_error(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_error(arb);
}

bool sp_toplistbrowse_is_loaded(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_is_loaded(tlb);
}

sp_error sp_image_remove_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata)
{
  return g_libspotify.sp_image_remove_load_callback(image, callback, userdata);
}

int sp_link_as_string(sp_link *link, char *buffer, int buffer_size)
{
  return g_libspotify.sp_link_as_string(link, buffer, buffer_size);
}

sp_error sp_playlist_add_tracks(sp_playlist *playlist, sp_track *const*tracks, int num_tracks, int position, sp_session *session)
{
  return g_libspotify.sp_playlist_add_tracks(playlist, tracks, num_tracks, position, g_session);
}

bool sp_playlist_is_in_ram(sp_session *session, sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_is_in_ram(g_session, playlist);
}

const char * sp_artistbrowse_biography(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_biography(arb);
}

const char* sp_error_message(sp_error error)
{
  return g_libspotify.sp_error_message(error);
}

sp_error sp_session_set_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state state)
{
  return g_libspotify.sp_session_set_scrobbling(g_session, provider, state);
}

const char * sp_playlist_get_description(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_get_description(playlist);
}

const char * sp_album_name(sp_album *album)
{
  return g_libspotify.sp_album_name(album);
}

int sp_search_total_albums(sp_search *search)
{
  return g_libspotify.sp_search_total_albums(search);
}

sp_artist * sp_albumbrowse_artist(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_artist(alb);
}

sp_playlist * sp_session_starred_for_user_create(sp_session *session, const char *canonical_username)
{
  return g_libspotify.sp_session_starred_for_user_create(g_session, canonical_username);
}

int sp_albumbrowse_num_copyrights(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_num_copyrights(alb);
}

sp_link * sp_link_create_from_artistbrowse_portrait(sp_artistbrowse *arb, int index)
{
  return g_libspotify.sp_link_create_from_artistbrowse_portrait(arb, index);
}

sp_error sp_link_add_ref(sp_link *link)
{
  return g_libspotify.sp_link_add_ref(link);
}

sp_error sp_toplistbrowse_error(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_error(tlb);
}

sp_error sp_track_error(sp_track *track)
{
  return g_libspotify.sp_track_error(track);
}

sp_error sp_playlist_add_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata)
{
  return g_libspotify.sp_playlist_add_callbacks(playlist, callbacks, userdata);
}

const char * sp_search_playlist_uri(sp_search *search, int index)
{
  return g_libspotify.sp_search_playlist_uri(search, index);
}

sp_playlist * sp_session_starred_create(sp_session *session)
{
  return g_libspotify.sp_session_starred_create(g_session);
}

bool sp_user_is_loaded(sp_user *user)
{
  return g_libspotify.sp_user_is_loaded(user);
}

sp_track_availability sp_track_get_availability(sp_session *session, sp_track *track)
{
  return g_libspotify.sp_track_get_availability(g_session, track);
}

sp_error sp_session_player_unload(sp_session *session)
{
  return g_libspotify.sp_session_player_unload(g_session);
}

sp_search * sp_search_create(sp_session *session, const char *query, int track_offset, int track_count, int album_offset, int album_count, int artist_offset, int artist_count, int playlist_offset, int playlist_count, sp_search_type search_type, search_complete_cb *callback, void *userdata)
{
  return g_libspotify.sp_search_create(g_session, query, track_offset, track_count, album_offset, album_count, artist_offset, artist_count, playlist_offset, playlist_count, search_type, callback, userdata);
}

const char * sp_session_user_name(sp_session *session)
{
  return g_libspotify.sp_session_user_name(g_session);
}

sp_error sp_playlist_set_autolink_tracks(sp_playlist *playlist, bool link)
{
  return g_libspotify.sp_playlist_set_autolink_tracks(playlist, link);
}

sp_link * sp_link_create_from_search(sp_search *search)
{
  return g_libspotify.sp_link_create_from_search(search);
}

sp_error sp_session_preferred_offline_bitrate(sp_session *session, sp_bitrate bitrate, bool allow_resync)
{
  return g_libspotify.sp_session_preferred_offline_bitrate(g_session, bitrate, allow_resync);
}

sp_error sp_playlistcontainer_playlist_folder_name(sp_playlistcontainer *pc, int index, char *buffer, int buffer_size)
{
  return g_libspotify.sp_playlistcontainer_playlist_folder_name(pc, index, buffer, buffer_size);
}

sp_album * sp_albumbrowse_album(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_album(alb);
}

sp_track * sp_toplistbrowse_track(sp_toplistbrowse *tlb, int index)
{
  return g_libspotify.sp_toplistbrowse_track(tlb, index);
}

bool sp_session_get_volume_normalization(sp_session *session)
{
  return g_libspotify.sp_session_get_volume_normalization(g_session);
}

int sp_search_num_tracks(sp_search *search)
{
  return g_libspotify.sp_search_num_tracks(search);
}

int sp_playlistcontainer_get_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist, sp_track **tracks, int num_tracks)
{
  return g_libspotify.sp_playlistcontainer_get_unseen_tracks(pc, playlist, tracks, num_tracks);
}

const byte * sp_artistbrowse_portrait(sp_artistbrowse *arb, int index)
{
  return g_libspotify.sp_artistbrowse_portrait(arb, index);
}

int sp_search_total_tracks(sp_search *search)
{
  return g_libspotify.sp_search_total_tracks(search);
}

sp_error sp_artistbrowse_add_ref(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_add_ref(arb);
}

sp_error sp_search_add_ref(sp_search *search)
{
  return g_libspotify.sp_search_add_ref(search);
}

sp_error sp_search_error(sp_search *search)
{
  return g_libspotify.sp_search_error(search);
}

sp_error sp_toplistbrowse_release(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_release(tlb);
}

sp_artist * sp_toplistbrowse_artist(sp_toplistbrowse *tlb, int index)
{
  return g_libspotify.sp_toplistbrowse_artist(tlb, index);
}

sp_error sp_image_add_ref(sp_image *image)
{
  return g_libspotify.sp_image_add_ref(image);
}

sp_error sp_playlist_update_subscribers(sp_session *session, sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_update_subscribers(g_session, playlist);
}

sp_playlist_type sp_playlistcontainer_playlist_type(sp_playlistcontainer *pc, int index)
{
  return g_libspotify.sp_playlistcontainer_playlist_type(pc, index);
}

int sp_toplistbrowse_num_albums(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_num_albums(tlb);
}

sp_error sp_session_flush_caches(sp_session *session)
{
  return g_libspotify.sp_session_flush_caches(g_session);
}

sp_error sp_playlist_track_set_seen(sp_playlist *playlist, int index, bool seen)
{
  return g_libspotify.sp_playlist_track_set_seen(playlist, index, seen);
}

sp_error sp_image_error(sp_image *image)
{
  return g_libspotify.sp_image_error(image);
}

sp_error sp_image_release(sp_image *image)
{
  return g_libspotify.sp_image_release(image);
}

sp_playlist * sp_playlist_create(sp_session *session, sp_link *link)
{
  return g_libspotify.sp_playlist_create(g_session, link);
}

sp_playlist_offline_status sp_playlist_get_offline_status(sp_session *session, sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_get_offline_status(g_session, playlist);
}

int sp_artistbrowse_num_portraits(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_num_portraits(arb);
}

sp_playlist * sp_search_playlist(sp_search *search, int index)
{
  return g_libspotify.sp_search_playlist(search, index);
}

int sp_track_popularity(sp_track *track)
{
  return g_libspotify.sp_track_popularity(track);
}

sp_error sp_inbox_release(sp_inbox *inbox)
{
  return g_libspotify.sp_inbox_release(inbox);
}

sp_user * sp_session_user(sp_session *session)
{
  return g_libspotify.sp_session_user(g_session);
}

sp_error sp_albumbrowse_error(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_error(alb);
}

sp_error sp_inbox_error(sp_inbox *inbox)
{
  return g_libspotify.sp_inbox_error(inbox);
}

sp_track * sp_artistbrowse_track(sp_artistbrowse *arb, int index)
{
  return g_libspotify.sp_artistbrowse_track(arb, index);
}

sp_error sp_albumbrowse_add_ref(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_add_ref(alb);
}

sp_user * sp_playlistcontainer_owner(sp_playlistcontainer *pc)
{
  return g_libspotify.sp_playlistcontainer_owner(pc);
}

bool sp_album_is_available(sp_album *album)
{
  return g_libspotify.sp_album_is_available(album);
}

int sp_toplistbrowse_num_artists(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_num_artists(tlb);
}

void * sp_session_userdata(sp_session *session)
{
  return g_libspotify.sp_session_userdata(g_session);
}

sp_error sp_albumbrowse_release(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_release(alb);
}

int sp_toplistbrowse_num_tracks(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_num_tracks(tlb);
}

sp_user * sp_playlist_owner(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_owner(playlist);
}

sp_inbox * sp_inbox_post_tracks(sp_session *session, const char *user, sp_track * const *tracks, int num_tracks, const char *message, inboxpost_complete_cb *callback, void *userdata)
{
  return g_libspotify.sp_inbox_post_tracks(g_session, user, tracks, num_tracks, message, callback, userdata);
}

sp_uint64 sp_playlistcontainer_playlist_folder_id(sp_playlistcontainer *pc, int index)
{
  return g_libspotify.sp_playlistcontainer_playlist_folder_id(pc, index);
}

sp_error sp_track_add_ref(sp_track *track)
{
  return g_libspotify.sp_track_add_ref(track);
}

sp_link * sp_link_create_from_user(sp_user *user)
{
  return g_libspotify.sp_link_create_from_user(user);
}

bool sp_playlist_is_collaborative(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_is_collaborative(playlist);
}

sp_imageformat sp_image_format(sp_image *image)
{
  return g_libspotify.sp_image_format(image);
}

int sp_search_num_artists(sp_search *search)
{
  return g_libspotify.sp_search_num_artists(search);
}

const void * sp_image_data(sp_image *image, size_t *data_size)
{
  return g_libspotify.sp_image_data(image, data_size);
}

sp_track * sp_localtrack_create(const char *artist, const char *title, const char *album, int length)
{
  return g_libspotify.sp_localtrack_create(artist, title, album, length);
}

const char * sp_albumbrowse_copyright(sp_albumbrowse *alb, int index)
{
  return g_libspotify.sp_albumbrowse_copyright(alb, index);
}

sp_album * sp_search_album(sp_search *search, int index)
{
  return g_libspotify.sp_search_album(search, index);
}

sp_error sp_session_set_connection_rules(sp_session *session, sp_connection_rules rules)
{
  return g_libspotify.sp_session_set_connection_rules(g_session, rules);
}

int sp_offline_num_playlists(sp_session *session)
{
  return g_libspotify.sp_offline_num_playlists(g_session);
}

sp_album * sp_track_album(sp_track *track)
{
  return g_libspotify.sp_track_album(track);
}

const char * sp_track_name(sp_track *track)
{
  return g_libspotify.sp_track_name(track);
}

int sp_search_total_playlists(sp_search *search)
{
  return g_libspotify.sp_search_total_playlists(search);
}

sp_error sp_playlist_reorder_tracks(sp_playlist *playlist, const int *tracks, int num_tracks, int new_position)
{
  return g_libspotify.sp_playlist_reorder_tracks(playlist, tracks, num_tracks, new_position);
}

sp_error sp_session_set_volume_normalization(sp_session *session, bool on)
{
  return g_libspotify.sp_session_set_volume_normalization(g_session, on);
}

sp_error sp_track_set_starred(sp_session *session, sp_track *const*tracks, int num_tracks, bool star)
{
  return g_libspotify.sp_track_set_starred(g_session, tracks, num_tracks, star);
}

bool sp_artist_is_loaded(sp_artist *artist)
{
  return g_libspotify.sp_artist_is_loaded(artist);
}

sp_track * sp_albumbrowse_track(sp_albumbrowse *alb, int index)
{
  return g_libspotify.sp_albumbrowse_track(alb, index);
}

sp_track * sp_link_as_track_and_offset(sp_link *link, int *offset)
{
  return g_libspotify.sp_link_as_track_and_offset(link, offset);
}

sp_artist * sp_artistbrowse_similar_artist(sp_artistbrowse *arb, int index)
{
  return g_libspotify.sp_artistbrowse_similar_artist(arb, index);
}

sp_connectionstate sp_session_connectionstate(sp_session *session)
{
  return g_libspotify.sp_session_connectionstate(g_session);
}

int sp_playlist_get_offline_download_completed(sp_session *session, sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_get_offline_download_completed(g_session, playlist);
}

sp_error sp_playlist_remove_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata)
{
  return g_libspotify.sp_playlist_remove_callbacks(playlist, callbacks, userdata);
}

bool sp_image_is_loaded(sp_image *image)
{
  return g_libspotify.sp_image_is_loaded(image);
}

sp_error sp_playlistcontainer_remove_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata)
{
  return g_libspotify.sp_playlistcontainer_remove_callbacks(pc, callbacks, userdata);
}

int sp_albumbrowse_backend_request_duration(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_backend_request_duration(alb);
}

sp_error sp_playlist_subscribers_free(sp_subscribers *subscribers)
{
  return g_libspotify.sp_playlist_subscribers_free(subscribers);
}

const char * sp_search_playlist_image_uri(sp_search *search, int index)
{
  return g_libspotify.sp_search_playlist_image_uri(search, index);
}

sp_artist * sp_track_artist(sp_track *track, int index)
{
  return g_libspotify.sp_track_artist(track, index);
}

bool sp_session_is_private_session(sp_session *session)
{
  return g_libspotify.sp_session_is_private_session(g_session);
}

int sp_albumbrowse_num_tracks(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_num_tracks(alb);
}

int sp_session_remembered_user(sp_session *session, char *buffer, size_t buffer_size)
{
  return g_libspotify.sp_session_remembered_user(g_session, buffer, buffer_size);
}

unsigned int sp_playlist_num_subscribers(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_num_subscribers(playlist);
}

const char * sp_user_display_name(sp_user *user)
{
  return g_libspotify.sp_user_display_name(user);
}

sp_error sp_toplistbrowse_add_ref(sp_toplistbrowse *tlb)
{
  return g_libspotify.sp_toplistbrowse_add_ref(tlb);
}

bool sp_playlist_is_loaded(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_is_loaded(playlist);
}

bool sp_playlist_get_image(sp_playlist *playlist, byte image[20])
{
  return g_libspotify.sp_playlist_get_image(playlist, image[20]);
}

sp_image * sp_image_create_from_link(sp_session *session, sp_link *l)
{
  return g_libspotify.sp_image_create_from_link(g_session, l);
}

int sp_album_year(sp_album *album)
{
  return g_libspotify.sp_album_year(album);
}

sp_track * sp_search_track(sp_search *search, int index)
{
  return g_libspotify.sp_search_track(search, index);
}

bool sp_albumbrowse_is_loaded(sp_albumbrowse *alb)
{
  return g_libspotify.sp_albumbrowse_is_loaded(alb);
}

sp_link * sp_link_create_from_artist_portrait(sp_artist *artist, sp_image_size size)
{
  return g_libspotify.sp_link_create_from_artist_portrait(artist, size);
}

sp_artist * sp_album_artist(sp_album *album)
{
  return g_libspotify.sp_album_artist(album);
}

int sp_offline_tracks_to_sync(sp_session *session)
{
  return g_libspotify.sp_offline_tracks_to_sync(g_session);
}

sp_error sp_session_player_prefetch(sp_session *session, sp_track *track)
{
  return g_libspotify.sp_session_player_prefetch(g_session, track);
}

sp_error sp_playlist_rename(sp_playlist *playlist, const char *new_name)
{
  return g_libspotify.sp_playlist_rename(playlist, new_name);
}

sp_error sp_artist_release(sp_artist *artist)
{
  return g_libspotify.sp_artist_release(artist);
}

const char * sp_artist_name(sp_artist *artist)
{
  return g_libspotify.sp_artist_name(artist);
}

bool sp_playlist_has_pending_changes(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_has_pending_changes(playlist);
}

bool sp_track_is_local(sp_session *session, sp_track *track)
{
  return g_libspotify.sp_track_is_local(g_session, track);
}

bool sp_album_is_loaded(sp_album *album)
{
  return g_libspotify.sp_album_is_loaded(album);
}

sp_link * sp_link_create_from_album_cover(sp_album *album, sp_image_size size)
{
  return g_libspotify.sp_link_create_from_album_cover(album, size);
}

const char * sp_search_did_you_mean(sp_search *search)
{
  return g_libspotify.sp_search_did_you_mean(search);
}

const byte * sp_artist_portrait(sp_artist *artist, sp_image_size size)
{
  return g_libspotify.sp_artist_portrait(artist, size);
}

sp_error sp_session_is_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state* state)
{
  return g_libspotify.sp_session_is_scrobbling(g_session, provider, state);
}

sp_album * sp_toplistbrowse_album(sp_toplistbrowse *tlb, int index)
{
  return g_libspotify.sp_toplistbrowse_album(tlb, index);
}

sp_linktype sp_link_type(sp_link *link)
{
  return g_libspotify.sp_link_type(link);
}

int sp_search_num_albums(sp_search *search)
{
  return g_libspotify.sp_search_num_albums(search);
}

const char * sp_build_id(void)
{
  return g_libspotify.sp_build_id();
}

sp_link * sp_link_create_from_playlist(sp_playlist *playlist)
{
  return g_libspotify.sp_link_create_from_playlist(playlist);
}

sp_subscribers * sp_playlist_subscribers(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_subscribers(playlist);
}

sp_playlist * sp_playlistcontainer_playlist(sp_playlistcontainer *pc, int index)
{
  return g_libspotify.sp_playlistcontainer_playlist(pc, index);
}

sp_error sp_session_set_social_credentials(sp_session *session, sp_social_provider provider, const char* username, const char* password)
{
  return g_libspotify.sp_session_set_social_credentials(g_session, provider, username, password);
}

const char * sp_playlist_track_message(sp_playlist *playlist, int index)
{
  return g_libspotify.sp_playlist_track_message(playlist, index);
}

sp_user * sp_link_as_user(sp_link *link)
{
  return g_libspotify.sp_link_as_user(link);
}

sp_artist * sp_search_artist(sp_search *search, int index)
{
  return g_libspotify.sp_search_artist(search, index);
}

sp_error sp_session_player_seek(sp_session *session, int offset)
{
  return g_libspotify.sp_session_player_seek(g_session, offset);
}

int sp_track_disc(sp_track *track)
{
  return g_libspotify.sp_track_disc(track);
}

sp_error sp_album_release(sp_album *album)
{
  return g_libspotify.sp_album_release(album);
}

sp_error sp_playlistcontainer_move_playlist(sp_playlistcontainer *pc, int index, int new_position, bool dry_run)
{
  return g_libspotify.sp_playlistcontainer_move_playlist(pc, index, new_position, dry_run);
}

int sp_playlistcontainer_num_playlists(sp_playlistcontainer *pc)
{
  return g_libspotify.sp_playlistcontainer_num_playlists(pc);
}

sp_toplistbrowse * sp_toplistbrowse_create(sp_session *session, sp_toplisttype type, sp_toplistregion region, const char *username, toplistbrowse_complete_cb *callback, void *userdata)
{
  return g_libspotify.sp_toplistbrowse_create(g_session, type, region, username, callback, userdata);
}

sp_user * sp_playlist_track_creator(sp_playlist *playlist, int index)
{
  return g_libspotify.sp_playlist_track_creator(playlist, index);
}

bool sp_artistbrowse_is_loaded(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_is_loaded(arb);
}

sp_error sp_playlist_set_collaborative(sp_playlist *playlist, bool collaborative)
{
  return g_libspotify.sp_playlist_set_collaborative(playlist, collaborative);
}

int sp_track_duration(sp_track *track)
{
  return g_libspotify.sp_track_duration(track);
}

int sp_playlist_num_tracks(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_num_tracks(playlist);
}

sp_track * sp_artistbrowse_tophit_track(sp_artistbrowse *arb, int index)
{
  return g_libspotify.sp_artistbrowse_tophit_track(arb, index);
}

int sp_artistbrowse_num_tracks(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_num_tracks(arb);
}

sp_error sp_playlist_add_ref(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_add_ref(playlist);
}

sp_error sp_playlist_release(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_release(playlist);
}

sp_error sp_playlist_set_offline_mode(sp_session *session, sp_playlist *playlist, bool offline)
{
  return g_libspotify.sp_playlist_set_offline_mode(g_session, playlist, offline);
}

sp_error sp_playlistcontainer_add_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata)
{
  return g_libspotify.sp_playlistcontainer_add_callbacks(pc, callbacks, userdata);
}

const char * sp_playlist_name(sp_playlist *playlist)
{
  return g_libspotify.sp_playlist_name(playlist);
}

sp_error sp_playlist_set_in_ram(sp_session *session, sp_playlist *playlist, bool in_ram)
{
  return g_libspotify.sp_playlist_set_in_ram(g_session, playlist, in_ram);
}

sp_track * sp_link_as_track(sp_link *link)
{
  return g_libspotify.sp_link_as_track(link);
}

int sp_offline_time_left(sp_session *session)
{
  return g_libspotify.sp_offline_time_left(g_session);
}

sp_error sp_session_set_private_session(sp_session *session, bool enabled)
{
  return g_libspotify.sp_session_set_private_session(g_session, enabled);
}

int sp_session_user_country(sp_session *session)
{
  return g_libspotify.sp_session_user_country(g_session);
}

bool sp_track_is_autolinked(sp_session *session, sp_track *track)
{
  return g_libspotify.sp_track_is_autolinked(g_session, track);
}

int sp_search_total_artists(sp_search *search)
{
  return g_libspotify.sp_search_total_artists(search);
}

sp_error sp_inbox_add_ref(sp_inbox *inbox)
{
  return g_libspotify.sp_inbox_add_ref(inbox);
}

sp_link * sp_link_create_from_track(sp_track *track, int offset)
{
  return g_libspotify.sp_link_create_from_track(track, offset);
}

sp_error sp_album_add_ref(sp_album *album)
{
  return g_libspotify.sp_album_add_ref(album);
}

sp_error sp_session_player_play(sp_session *session, bool play)
{
  return g_libspotify.sp_session_player_play(g_session, play);
}

sp_error sp_link_release(sp_link *link)
{
  return g_libspotify.sp_link_release(link);
}

const byte * sp_album_cover(sp_album *album, sp_image_size size)
{
  return g_libspotify.sp_album_cover(album, size);
}

sp_error sp_playlistcontainer_remove_playlist(sp_playlistcontainer *pc, int index)
{
  return g_libspotify.sp_playlistcontainer_remove_playlist(pc, index);
}

const byte * sp_image_image_id(sp_image *image)
{
  return g_libspotify.sp_image_image_id(image);
}

sp_error sp_playlistcontainer_add_folder(sp_playlistcontainer *pc, int index, const char *name)
{
  return g_libspotify.sp_playlistcontainer_add_folder(pc, index, name);
}

int sp_artistbrowse_num_tophit_tracks(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_num_tophit_tracks(arb);
}

sp_playlist * sp_playlistcontainer_add_playlist(sp_playlistcontainer *pc, sp_link *link)
{
  return g_libspotify.sp_playlistcontainer_add_playlist(pc, link);
}

sp_link * sp_link_create_from_string(const char *link)
{
  return g_libspotify.sp_link_create_from_string(link);
}

sp_error sp_artist_add_ref(sp_artist *artist)
{
  return g_libspotify.sp_artist_add_ref(artist);
}

sp_album * sp_link_as_album(sp_link *link)
{
  return g_libspotify.sp_link_as_album(link);
}

sp_link * sp_link_create_from_artist(sp_artist *artist)
{
  return g_libspotify.sp_link_create_from_artist(artist);
}

int sp_artistbrowse_backend_request_duration(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_backend_request_duration(arb);
}

sp_link * sp_link_create_from_image(sp_image *image)
{
  return g_libspotify.sp_link_create_from_image(image);
}

int sp_artistbrowse_num_albums(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_num_albums(arb);
}

int sp_track_num_artists(sp_track *track)
{
  return g_libspotify.sp_track_num_artists(track);
}

sp_playlist * sp_session_inbox_create(sp_session *session)
{
  return g_libspotify.sp_session_inbox_create(g_session);
}

sp_albumtype sp_album_type(sp_album *album)
{
  return g_libspotify.sp_album_type(album);
}

int sp_track_index(sp_track *track)
{
  return g_libspotify.sp_track_index(track);
}

bool sp_track_is_loaded(sp_track *track)
{
  return g_libspotify.sp_track_is_loaded(track);
}

sp_track * sp_track_get_playable(sp_session *session, sp_track *track)
{
  return g_libspotify.sp_track_get_playable(g_session, track);
}

sp_error sp_session_relogin(sp_session *session)
{
  return g_libspotify.sp_session_relogin(g_session);
}

int sp_artistbrowse_num_similar_artists(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_num_similar_artists(arb);
}

sp_playlist * sp_playlistcontainer_add_new_playlist(sp_playlistcontainer *pc, const char *name)
{
  return g_libspotify.sp_playlistcontainer_add_new_playlist(pc, name);
}

sp_error sp_image_add_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata)
{
  return g_libspotify.sp_image_add_load_callback(image, callback, userdata);
}

bool sp_track_is_placeholder(sp_track *track)
{
  return g_libspotify.sp_track_is_placeholder(track);
}

const char * sp_search_query(sp_search *search)
{
  return g_libspotify.sp_search_query(search);
}

sp_album * sp_artistbrowse_album(sp_artistbrowse *arb, int index)
{
  return g_libspotify.sp_artistbrowse_album(arb, index);
}

const char * sp_search_playlist_name(sp_search *search, int index)
{
  return g_libspotify.sp_search_playlist_name(search, index);
}

sp_link * sp_link_create_from_album(sp_album *album)
{
  return g_libspotify.sp_link_create_from_album(album);
}

sp_error sp_track_release(sp_track *track)
{
  return g_libspotify.sp_track_release(track);
}

sp_playlistcontainer * sp_session_playlistcontainer(sp_session *session)
{
  return g_libspotify.sp_session_playlistcontainer(g_session);
}

sp_error sp_artistbrowse_release(sp_artistbrowse *arb)
{
  return g_libspotify.sp_artistbrowse_release(arb);
}

int sp_playlistcontainer_clear_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist)
{
  return g_libspotify.sp_playlistcontainer_clear_unseen_tracks(pc, playlist);
}

sp_error sp_user_add_ref(sp_user *user)
{
  return g_libspotify.sp_user_add_ref(user);
}

bool sp_track_is_starred(sp_session *session, sp_track *track)
{
  return g_libspotify.sp_track_is_starred(g_session, track);
}

