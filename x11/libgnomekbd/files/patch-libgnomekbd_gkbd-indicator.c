--- libgnomekbd/gkbd-indicator.c	2006/10/28 21:08:20	18
+++ libgnomekbd/gkbd-indicator.c	2007/03/22 22:56:46	67
@@ -269,13 +269,18 @@
 			    (full_layout_name, &layout_name,
 			     &variant_name))
 				/* just in case */
-				layout_name = g_strdup (full_layout_name);
+				layout_name = full_layout_name;
+
+			/* make it freeable */
+			layout_name = g_strdup (layout_name);
 
 			if (globals.short_group_names != NULL) {
 				char *short_group_name =
 				    globals.short_group_names[group];
 				if (short_group_name != NULL
 				    && *short_group_name != '\0') {
+					/* drop the long name */
+					g_free (layout_name);
 					layout_name =
 					    g_strdup (short_group_name);
 				}
