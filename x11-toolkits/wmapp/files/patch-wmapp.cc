--- wmapp.cc.orig	Wed Jul 23 03:26:58 2003
+++ wmapp.cc	Wed Jul 23 03:28:59 2003
@@ -4,11 +4,9 @@
 
 using std::string;
 
-namespace Unix {
-  extern "C" {
-#   include <unistd.h> // for usleep()
-  }
-};
+extern "C" {
+# include <unistd.h> // for usleep()
+}
 
 // All the xpms we need:
 namespace Xpms {
@@ -254,7 +252,7 @@
 
   while (true) {
     // sleep for the specified time in milliseconds
-    Unix::usleep(1000 * current()->updatefreq());
+    usleep(1000 * current()->updatefreq());
     // execute any timed functions which need it
     current()->run_timed_functions();
 
