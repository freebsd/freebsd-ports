--- src/utilities/color.vala.orig	2018-01-12 22:06:16.414101000 +0100
+++ src/utilities/color.vala	2018-01-12 22:12:55.215652000 +0100
@@ -41,7 +41,7 @@
     /////////////////////////////////////////////////////////////////////
 
     public Color() {
-        Color.from_rgb(1.0f, 1.0f, 1.0f);
+        this.from_rgb(1.0f, 1.0f, 1.0f);
     }
 
     /////////////////////////////////////////////////////////////////////
@@ -49,7 +49,7 @@
     /////////////////////////////////////////////////////////////////////
 
     public Color.from_rgb(float red, float green, float blue) {
-        Color.from_rgba(red, green, blue, 1.0f);
+        this.from_rgba(red, green, blue, 1.0f);
     }
 
     /////////////////////////////////////////////////////////////////////
@@ -68,7 +68,7 @@
     /////////////////////////////////////////////////////////////////////
 
     public Color.from_gdk(Gdk.RGBA color) {
-        Color.from_rgba(
+        this.from_rgba(
             (float)color.red,
             (float)color.green,
             (float)color.blue,
@@ -83,7 +83,7 @@
     public Color.from_string(string hex_string) {
         var color = Gdk.RGBA();
         color.parse(hex_string);
-        Color.from_gdk(color);
+        this.from_gdk(color);
     }
 
     /////////////////////////////////////////////////////////////////////
@@ -121,7 +121,7 @@
             }
         }
 
-        Color.from_rgb((float)(rtotal/total), (float)(gtotal/total), (float)(btotal/total));
+        this.from_rgb((float)(rtotal/total), (float)(gtotal/total), (float)(btotal/total));
 
         if (s > 0.15f) s = 0.65f;
 
