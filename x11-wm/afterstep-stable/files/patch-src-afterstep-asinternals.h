$FreeBSD$

--- src/afterstep/asinternals.h.orig	2014-04-12 12:29:08.000000000 -0700
+++ src/afterstep/asinternals.h	2014-04-12 12:28:35.000000000 -0700
@@ -689,8 +689,8 @@
 
 
 /*************************** misc.c *********************************/
-inline void ungrab_window_buttons( Window w );
-inline void ungrab_window_keys (Window w );
+void ungrab_window_buttons( Window w );
+void ungrab_window_keys (Window w );
 void MyXGrabButton ( unsigned button, unsigned modifiers,
 				Window grab_window, Bool owner_events, unsigned event_mask,
 				int pointer_mode, int keyboard_mode, Window confine_to, Cursor cursor);
