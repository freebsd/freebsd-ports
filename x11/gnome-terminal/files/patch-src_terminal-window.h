--- src/terminal-window.h.orig	Mon Jul 10 20:32:21 2006
+++ src/terminal-window.h	Wed Oct 18 15:32:15 2006
@@ -77,15 +77,6 @@
 int    terminal_window_get_screen_count (TerminalWindow *window);
 
 void terminal_window_update_icon      (TerminalWindow *window);
-void terminal_window_update_geometry  (TerminalWindow *window);
-void terminal_window_set_size         (TerminalWindow *window,
-                                       TerminalScreen *screen,
-                                       gboolean        even_if_mapped);
-void terminal_window_set_size_force_grid (TerminalWindow *window,
-                                          TerminalScreen *screen,
-                                          gboolean        even_if_mapped,
-                                          int             force_grid_width,
-                                          int             force_grid_height);
 
 void     terminal_window_set_fullscreen (TerminalWindow *window,
                                          gboolean        setting);
