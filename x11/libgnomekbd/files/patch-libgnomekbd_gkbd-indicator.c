--- libgnomekbd/gkbd-indicator.c.orig	Wed Mar 21 17:11:21 2007
+++ libgnomekbd/gkbd-indicator.c	Wed Mar 21 17:11:23 2007
@@ -265,11 +265,14 @@ gkbd_indicator_prepare_drawing (GkbdIndi
 						       layouts_variants,
 						       group);
 			char *variant_name;
+			char *layout_name_ptr;
 			if (!gkbd_keyboard_config_split_items
-			    (full_layout_name, &layout_name,
+			    (full_layout_name, &layout_name_ptr,
 			     &variant_name))
 				/* just in case */
 				layout_name = g_strdup (full_layout_name);
+			else
+				layout_name = g_strdup (layout_name_ptr);
 
 			if (globals.short_group_names != NULL) {
 				char *short_group_name =
