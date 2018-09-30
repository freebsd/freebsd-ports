# fix on 104-i386 with clang 3.4

--- src/app/app.cc.orig	2018-06-07 17:57:35.192459000 +0200
+++ src/app/app.cc	2018-06-07 17:58:50.068954000 +0200
@@ -306,7 +306,7 @@
                 else
                         alpha = get_alpha();
 
-                GdkRGBA color{bg_color};
+                GdkRGBA color = bg_color;
                 color.alpha = alpha;
                 return color;
         }
