--- lib/Texture.cc.orig	2013-08-31 15:55:19.995853042 +0200
+++ lib/Texture.cc	2013-08-31 15:55:47.288909835 +0200
@@ -28,6 +28,7 @@
 #include "Resource.hh"
 
 #include <algorithm>
+#include <cstdlib>
 
 #include <X11/Xlib.h>
 #include <ctype.h>
@@ -184,7 +185,7 @@
 
     const std::string bstr =
       resource.read(name + ".borderWidth", className + ".BorderWidth", "1");
-    unsigned int bw = static_cast<unsigned int>(strtoul(bstr.c_str(), 0, 0));
+    unsigned int bw = static_cast<unsigned int>(std::strtoul(bstr.c_str(), 0, 0));
     texture.setBorderWidth(bw);
   }
 
