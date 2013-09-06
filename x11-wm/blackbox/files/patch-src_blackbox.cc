--- src/blackbox.cc.orig	2013-08-31 16:03:04.354825567 +0200
+++ src/blackbox.cc	2013-08-31 16:12:46.759944855 +0200
@@ -27,6 +27,8 @@
 #include "Slit.hh"
 #include "Window.hh"
 
+#include <cstdlib>
+
 #include <Pen.hh>
 #include <PixmapCache.hh>
 #include <Util.hh>
@@ -36,6 +38,7 @@
 #include <sys/stat.h>
 #include <assert.h>
 #include <signal.h>
+#include <stdlib.h>
 #include <unistd.h>
 
 // #define FOCUS_DEBUG
@@ -422,7 +425,7 @@
   if (managed == 0) {
     fprintf(stderr, "%s: no managable screens found, exiting...\n",
             applicationName().c_str());
-    ::exit(3);
+    std::exit(3);
   }
 
   screen_list_count = managed;
