--- src/process.c.orig	2018-08-30 00:28:55 UTC
+++ src/process.c
@@ -73,6 +73,8 @@ static GHashTable *processes = NULL;
 static pid_t signal_pid;
 static int signal_pipe[2];
 
+extern char **environ;
+
 Process *
 process_get_current (void)
 {
