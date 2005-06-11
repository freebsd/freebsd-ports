--- gui/gdmlogin.c.orig	Sat Jun 11 16:05:12 2005
+++ gui/gdmlogin.c	Sat Jun 11 16:05:19 2005
@@ -342,11 +342,11 @@ back_prog_get_path (void)
 static void 
 back_prog_launch_after_timeout ()
 {
+	int timeout;
 	g_assert (back_prog_timeout_event_id == -1);
 	g_assert (back_prog_watcher_event_id == -1);
 	g_assert (back_prog_pid == -1);
 	
-	int timeout;
 	
 	/* No program to run. */
 	if (! back_prog_get_path ())
