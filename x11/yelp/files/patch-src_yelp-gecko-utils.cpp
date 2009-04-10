--- src/yelp-gecko-utils.cpp.orig	2009-03-29 23:21:59.000000000 -0400
+++ src/yelp-gecko-utils.cpp	2009-03-29 23:25:48.000000000 -0400
@@ -28,8 +28,10 @@
 #include <nsStringAPI.h>
 
 #ifdef HAVE_GECKO_1_9
+#ifdef XPCOM_GLUE
 #include <gtkmozembed_glue.cpp>
 #endif
+#endif
 
 #include <gtkmozembed.h>
 #include <gtkmozembed_internal.h>
