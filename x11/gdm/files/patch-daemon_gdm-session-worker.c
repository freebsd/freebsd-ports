--- daemon/gdm-session-worker.c.orig        2008-07-30 19:15:47.000000000 -0400
+++ daemon/gdm-session-worker.c        2008-08-25 12:50:00.000000000 -0400
@@ -332,7 +332,7 @@ gdm_session_execute (const char *file,
                          * what to search if PATH is unset. POSIX may, dunno.
                          */
 
-                        path = "/bin:/usr/bin:.";
+                        path = "/bin:/usr/bin:/usr/local/bin:.";
                 }
 
                 len = strlen (file) + 1;
