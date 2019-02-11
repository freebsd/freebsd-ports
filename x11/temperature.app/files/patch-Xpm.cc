--- Xpm.cc.orig	2010-02-07 06:48:35 UTC
+++ Xpm.cc
@@ -23,10 +23,14 @@
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
 #include <iostream>
-#include <stdlib.h>
-#include <string.h>
+#include <cstdlib>
+#include <cstring>
 #include "Temperature.h"
 #include "Xpm.h"
+
+using std::cerr;
+using std::cout;
+using std::endl;
 
 Xpm::Xpm(Display* display, Window root, char** data) 
 {
