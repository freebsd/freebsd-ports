--- src/kgx-window.c.orig	2022-07-14 22:37:21 UTC
+++ src/kgx-window.c
@@ -83,7 +83,6 @@ kgx_window_constructed (GObject *object)
 kgx_window_constructed (GObject *object)
 {
   KgxWindow          *self = KGX_WINDOW (object);
-  g_autoptr (GError)  error = NULL;
   GtkApplication     *application = NULL;
   HdyStyleManager    *style_manager;
 
