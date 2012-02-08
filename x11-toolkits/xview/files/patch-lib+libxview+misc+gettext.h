--- lib/libxview/misc/gettext.h.orig	2005-03-28 06:41:36.000000000 -0800
+++ lib/libxview/misc/gettext.h	2012-02-02 20:37:56.819985942 -0800
@@ -2,7 +2,11 @@
 
 #define DEFAULT_DOMAIN	"default"
 #if !defined(__linux__) && !defined(__CYGWIN__)
+#ifdef __FreeBSD__
+#define DEFAULT_BINDING "/usr/local/lib/X11//locale\n"
+#else
 #define DEFAULT_BINDING "/usr/lib/locale\n"
+#endif
 #else
 #define DEFAULT_BINDING "/usr/openwin/lib/locale\n"
 #endif
