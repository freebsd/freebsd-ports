--- src/main.c.orig	Thu Jul 13 19:06:09 2006
+++ src/main.c	Thu Jul 13 19:07:23 2006
@@ -131,7 +131,9 @@
 			tray_data.xsh.width, tray_data.xsh.height,
 			tray_data.xsh.x, tray_data.xsh.y));
 
+#ifdef DEBUG
 	forall_icons(&print_icon_data);	
+#endif
 	DBG(3, ("===================================\n"));
 	trace_mode = 0;
 }
@@ -455,16 +457,20 @@
 					unlayout_icon(ti); /* or hide ? */
 					return;
 				}
+#ifdef DEBUG
 				print_icon_data(ti);
+#endif
 				update_positions();
 				tray_set_constraints();
 				DBG(4, ("icon position were updated\n"));
 			} else {
 				hide_window(ti);
 			}
+#ifdef DEBUG
 			DBG(4, ("====================\n"));
 			forall_icons(&print_icon_data);
 			DBG(4, ("====================\n"));
+#endif
 		}
 	}
 }
