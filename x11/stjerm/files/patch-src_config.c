--- src/config.c~	2014-01-12 11:31:51.000000000 -0500
+++ src/config.c	2015-03-24 17:32:49.873800297 -0400
@@ -614,7 +614,7 @@ void conf_init(void)
         exit(1);
     }
 
-    signal(SIGUSR1, (__sighandler_t) mainwindow_toggle);
+    signal(SIGUSR1, (sig_t) mainwindow_toggle);
     
     conf_find_position();
 }
