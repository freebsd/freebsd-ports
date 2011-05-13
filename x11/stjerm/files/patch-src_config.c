--- src/config.c.orig	2011-03-25 16:35:40.389707429 -0500
+++ src/config.c	2011-03-25 16:41:20.529584111 -0500
@@ -546,7 +546,7 @@ void conf_init(void)
         exit(1);
     }
 
-    signal(SIGUSR1, (__sighandler_t) mainwindow_toggle);
+    signal(SIGUSR1, (sig_t) mainwindow_toggle);
     
     conf_find_position();
 }
