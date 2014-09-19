libspotifywrapper
=================

A wrapper to libspotify allowing multiple threads in the same process to access it concurrently.

Dependencies
------------

This software depends on libspotify which must be installed beforehand.

Build & Installation
--------------------

Run the following commands::

  ./bootstrap
  ./configure
  make
  sudo make install

The installation files will be installed to the same location as libspotify.
