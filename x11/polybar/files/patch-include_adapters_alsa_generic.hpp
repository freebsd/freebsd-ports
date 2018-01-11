--- include/adapters/alsa/generic.hpp.orig	2017-12-03 17:03:49 UTC
+++ include/adapters/alsa/generic.hpp
@@ -4,7 +4,11 @@
 #include <alsa/asoundlib.h>
 #else
 #include <assert.h>
+
+#ifndef __FreeBSD__
 #include <endian.h>
+#endif
+
 #include <errno.h>
 #include <fcntl.h>
 #include <stdarg.h>
