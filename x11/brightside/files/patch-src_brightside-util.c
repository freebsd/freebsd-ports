--- src/brightside-util.c.orig	Fri Jul  2 01:20:22 2004
+++ src/brightside-util.c	Fri Jul  2 01:20:33 2004
@@ -64,9 +64,9 @@
 void
 execute (char *cmd, gboolean sync, gint *child_pid)
 {
+	gboolean retval;
 	g_assert (!sync || child_pid == NULL);
 
-	gboolean retval;
 
 	if (cmd == NULL)
 		return;
