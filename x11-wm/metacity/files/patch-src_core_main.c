--- src/core/main.c.orig	2008-10-08 00:10:39.000000000 -0400
+++ src/core/main.c	2008-10-08 00:18:44.000000000 -0400
@@ -312,6 +312,23 @@ void meta_select_display (gchar *display
   /* DO NOT FREE envVar, putenv() sucks */
   putenv (envVar);
 }
+
+static
+void meta_finalize (void)
+{
+  meta_display_close (meta_get_display (),
+                      CurrentTime); /* I doubt correct timestamps matter here */
+
+  meta_session_shutdown ();
+}
+
+static
+void sigterm_handler (int signum)
+{
+	meta_finalize ();
+
+	exit (meta_exit_code);
+}
     
 /**
  * This is where the story begins. It parses commandline options and
@@ -352,6 +369,11 @@ main (int argc, char **argv)
                 g_strerror (errno));
 #endif
 
+  act.sa_handler = &sigterm_handler;
+  if (sigaction (SIGTERM, &act, NULL) < 0)
+    g_printerr ("Failed to register SIGTERM handler: %s\n",
+		g_strerror (errno));
+
   if (g_getenv ("METACITY_VERBOSE"))
     meta_set_verbose (TRUE);
   if (g_getenv ("METACITY_DEBUG"))
@@ -478,11 +500,8 @@ main (int argc, char **argv)
   
   g_main_loop_run (meta_main_loop);
 
-  meta_display_close (meta_get_display (),
-                      CurrentTime); /* I doubt correct timestamps matter here */
+  meta_finalize ();
 
-  meta_session_shutdown ();
-  
   if (meta_restart_after_quit)
     {
       GError *err;
