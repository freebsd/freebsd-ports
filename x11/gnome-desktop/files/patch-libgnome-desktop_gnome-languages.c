--- libgnome-desktop/gnome-languages.c.orig	2016-01-08 00:52:40.415603000 +0100
+++ libgnome-desktop/gnome-languages.c	2016-01-08 01:30:53.511431000 +0100
@@ -229,7 +231,7 @@
 {
         char *name;
 
-        g_assert (language[0] != 0);
+        g_assert (language == NULL || language[0] != 0);
         g_assert (territory == NULL || territory[0] != 0);
         g_assert (codeset == NULL || codeset[0] != 0);
         g_assert (modifier == NULL || modifier[0] != 0);
