--- lib/Image.cc.orig  Thu Mar 10 18:39:23 2005
+++ lib/Image.cc       Thu Mar 10 18:40:09 2005
@@ -467,7 +467,7 @@
     if (colors[x] != ~0ul)
       continue;
 
-    int red, green, blue, gray;
+    int red = 0, green = 0, blue = 0, gray = 0;
 
     switch (visual_class) {
     case StaticGray:
