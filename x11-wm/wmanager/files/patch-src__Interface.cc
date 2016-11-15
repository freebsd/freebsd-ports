--- src/Interface.cc.orig	1999-11-16 18:25:42 UTC
+++ src/Interface.cc
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
@@ -130,10 +132,12 @@ Interface::Interface()
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
 
 
