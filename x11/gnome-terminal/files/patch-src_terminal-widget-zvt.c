--- src/terminal-widget-zvt.c.orig	Wed Feb 12 18:06:32 2003
+++ src/terminal-widget-zvt.c	Wed Feb 12 18:05:20 2003
@@ -1132,8 +1132,8 @@
 terminal_widget_set_pango_font (GtkWidget                  *widget,
                                 const PangoFontDescription *font_desc)
 {
-  g_return_if_fail (font_desc != NULL);
-  zvt_term_set_pango_font (ZVT_TERM (widget), font_desc);
+  /*g_return_if_fail (font_desc != NULL);
+  zvt_term_set_pango_font (ZVT_TERM (widget), font_desc);*/
 }
 
 gboolean
