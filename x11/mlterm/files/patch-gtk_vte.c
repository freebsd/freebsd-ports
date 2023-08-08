--- gtk/vte.c.orig	2023-04-01 13:54:40 UTC
+++ gtk/vte.c
@@ -1327,8 +1327,8 @@ static void init_screen(VteTerminal *terminal, ui_font
 
   PVT(terminal)->screen->xterm_listener.set_window_name = set_window_name;
   PVT(terminal)->screen->xterm_listener.set_icon_name = set_icon_name;
-  PVT(terminal)->xterm_resize = PVT(terminal)->screen->xterm_listener.resize;
-  PVT(terminal)->screen->xterm_listener.resize = xterm_resize;
+  PVT(terminal)->xterm_resize = (void (*)(void *, u_int, u_int, int))PVT(terminal)->screen->xterm_listener.resize;
+  PVT(terminal)->screen->xterm_listener.resize = (void (*)(void *, u_int, u_int, int, int))xterm_resize;
 
   orig_select_in_window = PVT(terminal)->screen->sel_listener.select_in_window;
   PVT(terminal)->screen->sel_listener.select_in_window = select_in_window;
@@ -3369,19 +3369,19 @@ void vte_terminal_set_color_dim_rgba(VteTerminal *term
 
 #if GTK_CHECK_VERSION(2, 99, 0)
 void vte_terminal_set_color_bold_rgba(VteTerminal *terminal, const GdkRGBA *bold) {
-  set_color_bold(terminal, bold, gdk_rgba_to_string2);
+  set_color_bold(terminal, bold, (gchar *(*)(const void *))gdk_rgba_to_string2);
 }
 
 void vte_terminal_set_color_foreground_rgba(VteTerminal *terminal, const GdkRGBA *foreground) {
-  set_color_foreground(terminal, foreground, gdk_rgba_to_string2);
+  set_color_foreground(terminal, foreground, (gchar *(*)(const void *))gdk_rgba_to_string2);
 }
 
 void vte_terminal_set_color_background_rgba(VteTerminal *terminal, const GdkRGBA *background) {
-  set_color_background(terminal, background, gdk_rgba_to_string2);
+  set_color_background(terminal, background, (gchar *(*)(const void *))gdk_rgba_to_string2);
 }
 
 void vte_terminal_set_color_cursor_rgba(VteTerminal *terminal, const GdkRGBA *cursor_background) {
-  set_color_cursor(terminal, cursor_background, gdk_rgba_to_string2);
+  set_color_cursor(terminal, cursor_background, (gchar *(*)(const void *))gdk_rgba_to_string2);
 }
 
 #if VTE_CHECK_VERSION(0, 44, 0)
@@ -3418,7 +3418,7 @@ void vte_terminal_set_color_highlight_foreground_rgba(
 void vte_terminal_set_colors_rgba(VteTerminal *terminal, const GdkRGBA *foreground,
                                   const GdkRGBA *background, const GdkRGBA *palette,
                                   gsize palette_size) {
-  if (set_colors(terminal, palette, palette_size, sizeof(GdkRGBA), gdk_rgba_to_string2) &&
+  if (set_colors(terminal, palette, palette_size, sizeof(GdkRGBA), (gchar *(*)(const char *))gdk_rgba_to_string2) &&
       palette_size > 0) {
     if (foreground == NULL) {
       foreground = &palette[7];
