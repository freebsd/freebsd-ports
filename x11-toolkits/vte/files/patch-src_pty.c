--- src/pty.c.orig	Tue Feb 13 16:24:15 2007
+++ src/pty.c	Tue Feb 13 16:29:15 2007
@@ -271,6 +271,7 @@ _vte_pty_run_on_pty (struct vte_pty_chil
 		     GPid *pid, GError **error)
 {
 	gboolean ret = TRUE;
+	extern char **environ;
 	GError *local_error = NULL;
 
 	if (command != NULL) {
