--- vapi/compat.vapi.orig	2014-11-21 08:23:41 UTC
+++ vapi/compat.vapi
@@ -33,8 +33,8 @@ namespace Plank
 	[CCode (cheader_filename = "gtk/gtk.h", cname = "gtk_widget_shape_combine_region")]
 	public void gtk_widget_shape_combine_region (Gtk.Widget widget, Cairo.Region? region);
 #endif
-	[CCode (cheader_filename = "sys/prctl.h", cname = "prctl", sentinel = "")]
-	public int prctl (int option, ...);
+	[CCode (cheader_filename = "unistd.h", cname = "setproctitle", sentinel = "")]
+	public void setproctitle (string fmt, ...); 
 
 	[CCode (cheader_filename = "unistd.h", cname = "getpid")]
 	public int getpid ();
