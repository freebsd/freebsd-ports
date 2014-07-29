--- src/Interface.cc.orig	Wed Nov 17 03:25:42 1999
+++ src/Interface.cc	Sun Nov  2 02:38:20 2003
@@ -23,6 +23,7 @@
 
 // SYSTEM INCLUDES //////////////////////////////////
 #include <iostream>                               // standard io interface
+#include <cstring>
 
 
 // PROJECT INCLUDES ////////////////////////////////
@@ -37,6 +38,7 @@
 #include <FL/Fl_Pixmap.H>
 #include <FL/fl_message.H>
 
+using namespace std;
 
 // logo image
 static unsigned char *image_mt[] = {
@@ -130,10 +132,12 @@
 Interface::~Interface()
 {
   delete _WMWindow;
+#if 0 // Uncommented, so we don't segfault with fltk 1.1
   delete _ExitButton;
   delete _StartButton;
   delete _AboutButton;
   delete _ListBrowser;
+#endif
 }
 
 
