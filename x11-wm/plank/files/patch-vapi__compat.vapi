--- ./vapi/compat.vapi.orig	2013-11-15 15:13:29.000000000 +0000
+++ ./vapi/compat.vapi	2014-05-23 18:39:55.000000000 +0000
@@ -25,8 +25,8 @@
 	[CCode (cheader_filename = "gtk/gtk.h", cname = "gtk_widget_shape_combine_region")]
 	public void gtk_widget_shape_combine_region (Gtk.Widget widget, Cairo.Region? region);
 #endif
-	[CCode (cheader_filename = "sys/prctl.h", cname = "prctl", sentinel = "")]
-	public int prctl (int option, ...);
+	[CCode (cheader_filename = "unistd.h", cname = "setproctitle", sentinel = "")]
+	public void setproctitle (string fmt, ...);
 }
 
 [CCode (cheader_filename = "glib.h")]
