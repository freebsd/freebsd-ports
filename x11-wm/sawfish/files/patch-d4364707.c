diff --git a/src/flippers.c b/src/flippers.c
index c18efcf3..1b248e68 100644
--- src/flippers.c
+++ src/flippers.c
@@ -22,10 +22,6 @@
 
 static Window edge_left, edge_right, edge_top, edge_bottom;
 
-DEFSYM(left, "left");
-DEFSYM(right, "right");
-DEFSYM(top, "top");
-DEFSYM(bottom, "bottom");
 DEFSYM(enter_flipper_hook, "enter-flipper-hook");
 DEFSYM(leave_flipper_hook, "leave-flipper-hook");
 
@@ -155,10 +151,6 @@ flippers_init (void)
 
     rep_pop_structure (tem);
 
-    rep_INTERN (left);
-    rep_INTERN (right);
-    rep_INTERN (top);
-    rep_INTERN (bottom);
     rep_INTERN_SPECIAL (enter_flipper_hook);
     rep_INTERN_SPECIAL (leave_flipper_hook);
     Fset(Qenter_flipper_hook, Qnil);
diff --git a/src/functions.c b/src/functions.c
index ff797529..7b191151 100644
--- src/functions.c
+++ src/functions.c
@@ -65,7 +65,6 @@ static int xinerama_heads;
 # endif
 #endif
 
-DEFSYM(root, "root");
 DEFSYM(after_restacking_hook, "after-restacking-hook");
 DEFSYM(position, "position");
 DEFSYM(spacing, "spacing");
@@ -1406,7 +1405,6 @@ functions_init (void)
     rep_ADD_SUBR(Ssend_client_message);
     rep_pop_structure (tem);
 
-    rep_INTERN(root);
     rep_INTERN_SPECIAL(after_restacking_hook);
     Fset(Qafter_restacking_hook, Qnil);
     rep_INTERN(position);
diff --git a/src/sawfish_subrs.h b/src/sawfish_subrs.h
index 8b1e7a2c..e2256249 100644
--- src/sawfish_subrs.h
+++ src/sawfish_subrs.h
@@ -79,7 +79,7 @@ extern void (*event_handlers[LASTEvent])(XEvent *ev);
 extern Time last_event_time;
 extern XEvent *current_x_event;
 extern repv Qvisibility_notify_hook, Qdestroy_notify_hook, Qmap_notify_hook,
-    Qunmap_notify_hook, Qreparent_notify_hook, Qenter_notify_hook,
+    Qunmap_notify_hook, Qreparent_notify_hook, Qenter_notify_hook, Qroot,
     Qleave_notify_hook, Qfocus_in_hook, Qfocus_out_hook, Qclient_message_hook,
     Qwindow_moved_hook, Qwindow_resized_hook, Qrandr_change_notify_hook;
 extern repv Qiconify_window, Quniconify_window;
@@ -158,7 +158,7 @@ extern void frames_init (void);
 extern void frames_kill (void);
 
 /* from functions.c */
-extern repv Qroot, Qafter_restacking_hook, Qposition, Qspacing;
+extern repv Qafter_restacking_hook, Qposition, Qspacing;
 extern repv Fdelete_window (repv win);
 extern repv Fdestroy_window (repv win);
 extern repv Frestack_windows (repv list);
diff --git a/src/windows.c b/src/windows.c
index eef835bd..c1cf652f 100644
--- src/windows.c
+++ src/windows.c
@@ -75,7 +75,6 @@ DEFSYM(north_west, "north-west");
 DEFSYM(north, "north");
 DEFSYM(north_east, "north-east");
 DEFSYM(west, "west");
-DEFSYM(center, "center");
 DEFSYM(east, "east");
 DEFSYM(south_west, "south-west");
 DEFSYM(south, "south");
@@ -1845,7 +1844,6 @@ windows_init (void)
     rep_INTERN(north);
     rep_INTERN(north_east);
     rep_INTERN(west);
-    rep_INTERN(center);
     rep_INTERN(east);
     rep_INTERN(south_west);
     rep_INTERN(south);
