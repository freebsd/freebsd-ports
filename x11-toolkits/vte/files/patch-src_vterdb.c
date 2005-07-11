--- src/vterdb.c.orig	Sun Jul 10 20:24:32 2005
+++ src/vterdb.c	Sun Jul 10 20:24:47 2005
@@ -40,7 +40,7 @@ _vte_property_get_string(GdkWindow *wind
 			 char **retval)
 {
 	return gdk_property_get(window, atom, GDK_TARGET_STRING,
-				0, INT_MAX,
+				0, INT_MAX - 3,
 				FALSE,
 				type, NULL, size,
 				(guchar**) retval);
