--- awesome.c.orig	2009-02-05 16:39:52.000000000 +0200
+++ awesome.c	2009-02-17 22:02:32.000000000 +0200
@@ -58,7 +58,7 @@
 {
     client_t *c;
     xembed_window_t *em;
-    int screen_nbr;
+    int screen_nbr, nscreens;
 
     a_dbus_cleanup();
     luaA_cs_cleanup();
@@ -71,8 +71,10 @@
     }
 
     /* do this only for real screen */
+	const xcb_setup_t *setup = xcb_get_setup(globalconf.connection);
+	nscreens = setup ? xcb_setup_roots_length(setup) : -1;
     for(screen_nbr = 0;
-        screen_nbr < xcb_setup_roots_length(xcb_get_setup(globalconf.connection));
+        screen_nbr < nscreens;
         screen_nbr++)
         systray_cleanup(screen_nbr);
 
