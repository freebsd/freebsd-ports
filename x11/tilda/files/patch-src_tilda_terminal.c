--- src/tilda_terminal.c.orig	2022-10-30 15:03:03 UTC
+++ src/tilda_terminal.c
@@ -530,7 +530,7 @@
          */
         flags |= G_SPAWN_FILE_AND_ARGV_ZERO;
     } else {
-        argv = malloc(1 * sizeof(void *));
+        argv = malloc(2 * sizeof(void *));
         argv[0] = default_command;
         argv[1] = NULL;
     }
