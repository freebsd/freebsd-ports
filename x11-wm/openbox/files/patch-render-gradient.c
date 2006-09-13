--- render/gradient.c.orig	Sat Aug 26 22:15:51 2006
+++ render/gradient.c	Tue Sep 12 21:14:46 2006
@@ -371,6 +371,9 @@
     RrPixel32 current;
     RrColor *primary_light, *secondary_light;
 
+    VARS(y1);
+    VARS(y3);
+
     r = sf->primary->r;
     r += r >> 2;
     g = sf->primary->g;
@@ -393,10 +396,8 @@
     if (b > 0xFF) b = 0xFF;
     secondary_light = RrColorNew(a->inst, r, g, b);
 
-    VARS(y1);
     SETUP(y1, primary_light, sf->primary, (h / 2) -1);
   
-    VARS(y3);
     SETUP(y3, sf->secondary, secondary_light,  (h / 2) -1);
 
     for (y1 = h - 1; y1 > (h / 2) -1; --y1) {  /* 0 -> h-1 */
