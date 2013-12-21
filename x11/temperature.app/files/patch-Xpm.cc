--- Xpm.cc.bak	2002-04-06 08:44:36.000000000 +0900
+++ Xpm.cc	2013-12-07 17:25:00.000000000 +0900
@@ -22,12 +22,16 @@
 #include <X11/Xlib.h>
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
-#include <iostream.h>
-#include <stdlib.h>
-#include <string.h>
+#include <iostream>
+#include <cstdlib>
+#include <cstring>
 #include "Temperature.h"
 #include "Xpm.h"
 
+using std::cerr;
+using std::cout;
+using std::endl;
+
 Xpm::Xpm(Display* display, Window root, char** data) 
 {
    int error;
