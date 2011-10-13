--- src/config.c.orig	2011-07-19 16:52:33.000000000 -0500
+++ src/config.c	2011-10-12 17:05:50.164711868 -0500
@@ -146,7 +146,11 @@ pid_t get_stjerm_pid(void)
     char buffer[100];
     char **list;
     int i = 0;
+#ifdef __FreeBSD__
+    FILE *p = popen("pgrep stjerm", "r");
+#else
     FILE *p = popen("pidof stjerm", "r");
+#endif
     
     if(p == NULL)
     {
@@ -552,7 +556,7 @@ void conf_init(void)
         exit(1);
     }
 
-    signal(SIGUSR1, (__sighandler_t) mainwindow_toggle);
+    signal(SIGUSR1, (sig_t) mainwindow_toggle);
     
     conf_find_position();
 }
