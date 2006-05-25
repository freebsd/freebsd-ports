--- lib/libxview/textsw/txt_search.c.orig	Sun Mar 26 01:12:40 2006
+++ lib/libxview/textsw/txt_search.c	Sun Mar 26 01:13:17 2006
@@ -79,7 +79,7 @@
     if (direction == EV_FIND_DEFAULT)
 	first = last_plus_one;
 
-    STRNCPY(buf, (CHAR *) panel_get(search_panel_items[(int) FIND_STRING_ITEM],
+    (STRNCPY) (buf, (CHAR *) panel_get(search_panel_items[(int) FIND_STRING_ITEM],
 #ifdef OW_I18N
 				PANEL_VALUE_WCS, NULL),
 #else
