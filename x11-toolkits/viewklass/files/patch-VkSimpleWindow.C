--- ./VkSimpleWindow.C.orig	Wed Jul 23 02:18:56 2003
+++ ./VkSimpleWindow.C	Wed Jul 23 02:20:37 2003
@@ -44,6 +44,10 @@
 #include <X11/Xutil.h>
 #include <X11/Xmu/Editres.h>
 
+using std::cerr;
+using std::endl;
+using std::exception;
+
 static char* rcsid
 #ifdef __GNUC__
 __attribute__ ((unused))
