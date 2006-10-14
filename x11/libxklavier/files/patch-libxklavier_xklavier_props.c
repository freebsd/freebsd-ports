--- libxklavier/xklavier_props.c.orig	Sun Apr 16 20:51:36 2006
+++ libxklavier/xklavier_props.c	Tue Jun 13 00:11:24 2006
@@ -355,10 +355,8 @@ xkl_config_rec_get_from_root_window_prop
 					       --varlen);
 					var[varlen] = '\0';
 					/* Resize the original layout */
-					((char *)
-					 g_realloc(*layout,
-						   laylen + 1))[laylen] =
-					    '\0';
+					*layout = g_realloc(*layout, laylen + 1);
+					(*layout)[laylen] = '\0';
 				}
 			}
 			layout++;
