diff --git a/mcwm.c b/mcwm.c
index 0613c9f..04a7a41 100644
--- mcwm.c
+++ mcwm.c
@@ -45,6 +45,10 @@
 
 #include <X11/keysym.h>
 
+#include <xcb/xproto.h>
+#include <xcb/xcb_util.h>
+#include <xcb/xcb_ewmh.h>
+
 #ifdef DEBUG
 #include "events.h"
 #endif
@@ -503,7 +507,7 @@ void setwmdesktop(xcb_drawable_t win, uint32_t ws)
     PDEBUG("Changing _NET_WM_DESKTOP on window %d to %d\n", win, ws);
     
     xcb_change_property(conn, XCB_PROP_MODE_REPLACE, win,
-                        atom_desktop, CARDINAL, 32, 1,
+                        atom_desktop, XCB_ATOM_CARDINAL, 32, 1,
                         &ws);
 }
 
@@ -521,7 +525,7 @@ int32_t getwmdesktop(xcb_drawable_t win)
     uint32_t *wsp;
     uint32_t ws;
     
-    cookie = xcb_get_any_property(conn, false, win, atom_desktop,
+    cookie = xcb_get_property(conn, false, win, atom_desktop,XCB_GET_PROPERTY_TYPE_ANY, 0,
                                   sizeof (int32_t));
 
     reply = xcb_get_property_reply(conn, cookie, NULL);
@@ -1136,8 +1140,8 @@ struct client *setupwin(xcb_window_t win)
     /*
      * Get the window's incremental size step, if any.
      */
-    if (!xcb_get_wm_normal_hints_reply(
-            conn, xcb_get_wm_normal_hints_unchecked(
+    if (!xcb_icccm_get_wm_normal_hints_reply(
+            conn, xcb_icccm_get_wm_normal_hints_unchecked(
                 conn, win), &hints, NULL))
     {
         PDEBUG("Couldn't get size hints.\n");
@@ -1147,25 +1151,25 @@ struct client *setupwin(xcb_window_t win)
      * The user specified the position coordinates. Remember that so
      * we can use geometry later.
      */
-    if (hints.flags & XCB_SIZE_HINT_US_POSITION)
+    if (hints.flags & XCB_ICCCM_SIZE_HINT_US_POSITION)
     {
         client->usercoord = true;
     }
 
-    if (hints.flags & XCB_SIZE_HINT_P_MIN_SIZE)
+    if (hints.flags & XCB_ICCCM_SIZE_HINT_P_MIN_SIZE)
     {
         client->min_width = hints.min_width;
         client->min_height = hints.min_height;
     }
     
-    if (hints.flags & XCB_SIZE_HINT_P_MAX_SIZE)
+    if (hints.flags & XCB_ICCCM_SIZE_HINT_P_MAX_SIZE)
     {
         
         client->max_width = hints.max_width;
         client->max_height = hints.max_height;
     }
     
-    if (hints.flags & XCB_SIZE_HINT_P_RESIZE_INC)
+    if (hints.flags & XCB_ICCCM_SIZE_HINT_P_RESIZE_INC)
     {
         client->width_inc = hints.width_inc;
         client->height_inc = hints.height_inc;
@@ -1174,7 +1178,7 @@ struct client *setupwin(xcb_window_t win)
                client->height_inc);
     }
 
-    if (hints.flags & XCB_SIZE_HINT_BASE_SIZE)
+    if (hints.flags & XCB_ICCCM_SIZE_HINT_BASE_SIZE)
     {
         client->base_width = hints.base_width;
         client->base_height = hints.base_height;
@@ -2823,7 +2827,7 @@ void botright(void)
 void deletewin(void)
 {
     xcb_get_property_cookie_t cookie;
-    xcb_get_wm_protocols_reply_t protocols;
+    xcb_icccm_get_wm_protocols_reply_t protocols;
     bool use_delete = false;
     uint32_t i;
 
@@ -2833,14 +2837,14 @@ void deletewin(void)
     }
 
     /* Check if WM_DELETE is supported.  */
-    cookie = xcb_get_wm_protocols_unchecked(conn, focuswin->id, wm_protocols);
-    if (xcb_get_wm_protocols_reply(conn, cookie, &protocols, NULL) == 1) {
+    cookie = xcb_icccm_get_wm_protocols_unchecked(conn, focuswin->id, wm_protocols);
+    if (xcb_icccm_get_wm_protocols_reply(conn, cookie, &protocols, NULL) == 1) {
         for (i = 0; i < protocols.atoms_len; i++)
             if (protocols.atoms[i] == wm_delete_window)
                  use_delete = true;
     }
 
-    xcb_get_wm_protocols_reply_wipe(&protocols);
+    xcb_icccm_get_wm_protocols_reply_wipe(&protocols);
 
     if (use_delete)
     {
@@ -4082,9 +4086,50 @@ int main(int argc, char **argv)
     conf.fixedcol = getcolor(fixedcol);
     
     /* Get some atoms. */
-    atom_desktop = xcb_atom_get(conn, "_NET_WM_DESKTOP");
-    wm_delete_window = xcb_atom_get(conn, "WM_DELETE_WINDOW");
-    wm_protocols = xcb_atom_get(conn, "WM_PROTOCOLS");
+//    atom_desktop = xcb_atom_get(conn, "_NET_WM_DESKTOP");
+//    wm_delete_window = xcb_atom_get(conn, "WM_DELETE_WINDOW");
+//    wm_protocols = xcb_atom_get(conn, "WM_PROTOCOLS");
+
+    char  *atom_name;
+    xcb_intern_atom_cookie_t cookie_desktop;
+    xcb_intern_atom_cookie_t cookie_delete_window;
+    xcb_intern_atom_cookie_t cookie_protocols;
+    xcb_intern_atom_reply_t *rep;
+
+    atom_name = "_NET_WM_DESKTOP";
+    cookie_desktop = xcb_intern_atom (conn,
+                                      0,
+                                      strlen (atom_name),
+                                      atom_name);
+    rep = xcb_intern_atom_reply (conn,
+                                  cookie_desktop,
+                                  NULL);
+    atom_desktop = rep->atom;
+    free (rep);
+
+
+    atom_name = "WM_DELETE_WINDOW";
+    cookie_delete_window = xcb_intern_atom (conn,
+                                      0,
+                                      strlen (atom_name),
+                                      atom_name);
+    rep = xcb_intern_atom_reply (conn,
+                                  cookie_delete_window,
+                                  NULL);
+    wm_delete_window = rep->atom;
+    free (rep);
+
+    atom_name = "WM_PROTOCOLS";
+    cookie_protocols = xcb_intern_atom (conn,
+                                      0,
+                                      strlen (atom_name),
+                                      atom_name);
+    rep = xcb_intern_atom_reply (conn,
+                                  cookie_protocols,
+                                  NULL);
+    wm_protocols = rep->atom;
+    free (rep);
+
 
     /* Check for RANDR extension and configure. */
     randrbase = setuprandr();
