--- wibox.c.orig
+++ wibox.c
@@ -101,14 +101,17 @@ wibox_systray_kickout(int phys_screen)
 {
     xcb_screen_t *s = xutil_screen_get(globalconf.connection, phys_screen);
 
-    /* Who! Check that we're not deleting a wibox with a systray, because it
-     * may be its parent. If so, we reparent to root before, otherwise it will
-     * hurt very much. */
-    xcb_reparent_window(globalconf.connection,
-                        globalconf.screens[phys_screen].systray.window,
-                        s->root, -512, -512);
-
-    globalconf.screens[phys_screen].systray.parent = s->root;
+    if(globalconf.screens[phys_screen].systray.parent != s->root)
+    {
+        /* Who! Check that we're not deleting a wibox with a systray, because it
+         * may be its parent. If so, we reparent to root before, otherwise it will
+         * hurt very much. */
+        xcb_reparent_window(globalconf.connection,
+                            globalconf.screens[phys_screen].systray.window,
+                            s->root, -512, -512);
+
+        globalconf.screens[phys_screen].systray.parent = s->root;
+    }
 }
 
 static void
