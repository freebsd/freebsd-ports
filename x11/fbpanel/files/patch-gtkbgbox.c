--- gtkbgbox.c~	Sat Dec 18 17:46:25 2004
+++ gtkbgbox.c	Sat Dec 18 17:46:40 2004
@@ -310,10 +310,9 @@
 static void
 gtk_bgbox_set_bg_root(GtkWidget *widget, GtkBgboxPrivate *priv)
 {
-    priv = GTK_BGBOX_GET_PRIVATE (widget);
     GdkRectangle rect;
+    priv = GTK_BGBOX_GET_PRIVATE (widget);
     
-    ENTER;
     priv->pixmap = fb_bg_get_xroot_pix_for_win(priv->bg, widget);
     if (!priv->pixmap || priv->pixmap ==  GDK_NO_BG) {
         priv->bg_type = BG_NONE;
