Revert commit, because default size is not anymore enabled.

--- terminal/terminal-screen.c.orig	2016-10-25 16:07:56 UTC
+++ terminal/terminal-screen.c
@@ -1673,47 +1673,31 @@ terminal_screen_get_geometry (TerminalSc
  *
  * I don't like this way, but its required to work-around a Gtk+
  * bug (maybe also caused by a Vte bug, not sure).
- *
- * Code borrowed from gnome-terminal (terminal_window_update_geometry).
  **/
 void
 terminal_screen_set_window_geometry_hints (TerminalScreen *screen,
                                            GtkWindow      *window)
 {
   GdkGeometry    hints;
-  GtkRequisition vbox_request;
-  GtkAllocation  toplevel_allocation, vbox_allocation;
   glong          char_width, char_height;
-  glong          grid_width, grid_height;
-  glong          chrome_width, chrome_height;
-  gint           csd_width, csd_height;
+  gint           xpad, ypad;
 
   terminal_return_if_fail (TERMINAL_IS_SCREEN (screen));
   terminal_return_if_fail (VTE_IS_TERMINAL (screen->terminal));
   terminal_return_if_fail (gtk_widget_get_realized (screen));
   terminal_return_if_fail (gtk_widget_get_realized (window));
 
-  terminal_screen_get_geometry (screen, &char_width, &char_height, NULL, NULL);
-  terminal_screen_get_size (screen, &grid_width, &grid_height);
-
-  gtk_widget_get_preferred_size (TERMINAL_WINDOW (window)->vbox, NULL, &vbox_request);
-  chrome_width = vbox_request.width - (char_width * grid_width);
-  chrome_height = vbox_request.height - (char_height * grid_height);
-
-  gtk_widget_get_allocation (TERMINAL_WINDOW (window)->vbox, &vbox_allocation);
-  gtk_widget_get_allocation (GTK_WIDGET (window), &toplevel_allocation);
-  csd_width = toplevel_allocation.width - vbox_allocation.width;
-  csd_height = toplevel_allocation.height - vbox_allocation.height;
+  terminal_screen_get_geometry (screen, &char_width, &char_height, &xpad, &ypad);
 
-  hints.base_width = chrome_width + csd_width;
-  hints.base_height = chrome_height + csd_height;
+  hints.base_width = xpad;
+  hints.base_height = ypad;
   hints.width_inc = char_width;
   hints.height_inc = char_height;
   hints.min_width = hints.base_width + hints.width_inc * 4;
   hints.min_height = hints.base_height + hints.height_inc * 2;
 
-  gtk_window_set_geometry_hints (window,
-                                 NULL,
+  gtk_window_set_geometry_hints (GTK_WINDOW (window),
+                                 screen->terminal,
                                  &hints,
                                  GDK_HINT_RESIZE_INC
                                  | GDK_HINT_MIN_SIZE
