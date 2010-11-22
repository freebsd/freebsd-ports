--- ./panel/misc.c.orig	2010-04-28 04:39:31.000000000 -0700
+++ ./panel/misc.c	2010-11-17 11:06:07.000000000 -0800
@@ -687,7 +687,7 @@
 gdk_color_to_RRGGBB(GdkColor *color)
 {
     static gchar str[10]; // #RRGGBB + \0
-    g_sprintf(str, "#%02x%02x%02x",
+    g_snprintf(str, sizeof(str), "#%02x%02x%02x",
         color->red >> 8, color->green >> 8, color->blue >> 8);
     return str;
 }
