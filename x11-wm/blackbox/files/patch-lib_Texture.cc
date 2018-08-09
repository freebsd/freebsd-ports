--- lib/Texture.cc.orig	2005-03-15 07:01:36 UTC
+++ lib/Texture.cc
@@ -28,6 +28,7 @@
 #include "Resource.hh"
 
 #include <algorithm>
+#include <cstdlib>
 
 #include <X11/Xlib.h>
 #include <ctype.h>
@@ -184,7 +185,7 @@ bt::Texture bt::textureResource(const Display &display
 
     const std::string bstr =
       resource.read(name + ".borderWidth", className + ".BorderWidth", "1");
-    unsigned int bw = static_cast<unsigned int>(strtoul(bstr.c_str(), 0, 0));
+    unsigned int bw = static_cast<unsigned int>(std::strtoul(bstr.c_str(), 0, 0));
     texture.setBorderWidth(bw);
   }
 
