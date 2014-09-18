lib_LTLIBRARIES=libspotifywrapper.la
nobase_include_HEADERS=libspotify/apiwrapper.h
libspotifywrapper_la_SOURCES=libspotifywrapper.c apiwrapper.h
libspotifywrapper_la_CFLAGS=-fPIC
libspotifywrapper_la_LDFLAGS=-shared -fPIC -lspotify

libspotify/apiwrapper.h:
	mkdir -p libspotify
	cp apiwrapper.h libspotify
