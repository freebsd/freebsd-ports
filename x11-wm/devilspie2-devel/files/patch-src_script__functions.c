--- src/script_functions.c.orig	2026-11-04 04:33:55 UTC
+++ src/script_functions.c
@@ -100,24 +100,24 @@ static guint32 current_time(void)
  */
 static guint32 current_time(void)
 {
-	WnckWindow *window;
-	gulong wnd;
-	Display *dpy;
-	Atom prop;
-	XEvent xevent;
+    WnckWindow *window = get_current_window();
+    if (!window) {
+        return GDK_CURRENT_TIME;
+    }
 
-	window = get_current_window();
-	if (!window)
-		return GDK_CURRENT_TIME;
+    GdkWindow *gdk_window = gdk_x11_window_foreign_new_for_display(
+        gdk_display_get_default(),
+        wnck_window_get_xid(window)
+    );
 
-	dpy = gdk_x11_get_default_xdisplay();
-	wnd = wnck_window_get_xid(window);
-	prop = my_wnck_atom_get("WM_NAME");
-	XChangeProperty(dpy, wnd, prop, XA_STRING, 8, PropModeAppend, NULL, 0);
+    if (!gdk_window) {
+        return GDK_CURRENT_TIME;
+    }
 
-	/* Wait for the event to succeed */
-	XIfEvent(dpy, &xevent, current_time_cb, GUINT_TO_POINTER(wnd));
-	return xevent.xproperty.time;
+    guint32 timestamp = gdk_x11_get_server_time(gdk_window);
+    g_object_unref(gdk_window);
+
+    return timestamp;
 }
 
 
@@ -800,19 +800,16 @@ int c_unminimize(lua_State *lua)
  */
 int c_unminimize(lua_State *lua)
 {
-	if (!check_param_count(lua, "unminimize", 0)) {
-		return 0;
-	}
-
-	if (!devilspie2_emulate) {
-		WnckWindow *window = get_current_window();
-
-		if (window && TRUE == wnck_window_is_minimized(window)) {
-			wnck_window_unminimize (window, current_time());
-		}
-	}
-
-	return 0;
+    if (!check_param_count(lua, "unminimize", 0)) { return 0; }
+    if (!devilspie2_emulate) {
+        WnckWindow *window = get_current_window();
+        if (window && TRUE == wnck_window_is_minimized(window)) {
+            devilspie2_error_trap_push();
+            wnck_window_unminimize(window, current_time());
+            devilspie2_error_trap_pop();
+        }
+    }
+    return 0;
 }
 
 
