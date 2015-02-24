diff --git a/src/key_grabber.c b/src/key_grabber.c
index 8c9e67c..b4ca786 100644
--- src/key_grabber.c
+++ src/key_grabber.c
@@ -190,8 +190,8 @@ void pull (struct tilda_window_ *tw, enum pull_state state)
          * Overriding the user time here seems to work a lot better than calling
          * gtk_window_present_with_time() here, or at the end of the function. I have
          * no idea why, they should do the same thing. */
-        gdk_x11_window_set_user_time (GTK_WIDGET(tw->window)->window,
-                                      tomboy_keybinder_get_current_event_time());
+        /*gdk_x11_window_set_user_time (GTK_WIDGET(tw->window)->window,
+                                      tomboy_keybinder_get_current_event_time());*/
         gtk_window_move (GTK_WINDOW(tw->window), config_getint ("x_pos"), config_getint ("y_pos"));
         gtk_widget_show (GTK_WIDGET(tw->window));
 
