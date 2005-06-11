--- gui/gdmchooser.c.orig	Sat Jun 11 16:04:13 2005
+++ gui/gdmchooser.c	Sat Jun 11 16:04:35 2005
@@ -2030,6 +2030,7 @@ main (int argc, char *argv[])
     int nextopt;
     const char *gdm_version;
     int i;
+    guint sid;
 
     stored_argv = g_new0 (char *, argc + 1);
     for (i = 0; i < argc; i++)
@@ -2124,7 +2125,7 @@ main (int argc, char *argv[])
     gdm_chooser_xdmcp_init (hosts);
     poptFreeContext (ctx);
 
-    guint sid = g_signal_lookup ("event",
+    sid = g_signal_lookup ("event",
 				 GTK_TYPE_WIDGET);
     g_signal_add_emission_hook (sid,
 				0 /* detail */,
