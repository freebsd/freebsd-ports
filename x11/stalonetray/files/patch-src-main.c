--- src/main.c.orig	Thu Apr  6 14:16:26 2006
+++ src/main.c	Thu Apr  6 14:16:06 2006
@@ -423,16 +423,20 @@
 					unlayout_icon(ti); /* or hide ? */
 					return;
 				}
+#ifdef DEBUG
 				print_icon_data(ti);
+#endif
 				update_positions();
 				tray_set_constraints();
 				DBG(4, "icon position were updated\n");
 			} else {
 				hide_window(ti);
 			}
+#ifdef DEBUG
 			DBG(4, "====================\n");
 			forall_icons(&print_icon_data);
 			DBG(4, "====================\n");
+#endif
 		}
 	}
 }
