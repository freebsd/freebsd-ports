--- src/appearance.c.orig	2008-01-11 21:22:11.000000000 +0300
+++ src/appearance.c	2011-12-14 22:55:38.000000000 +0400
@@ -266,7 +287,7 @@
     RrFontWeight weight = RR_FONTWEIGHT_NORMAL;
     RrFontSlant slant = RR_FONTSLANT_NORMAL;
 
-    if (mapping) return;
+    if (mapping) return NULL;
 
     font = g_strdup(gtk_font_button_get_font_name(w));
     while ((c = strrchr(font, ' '))) {
