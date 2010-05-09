--- src/logging.c
+++ src/logging.c
@@ -82,7 +82,8 @@
     else if (sscanf(pty, "pts/%d", &i) == 1)
 	sprintf(ut_id, "vt%02x", (i & 0xff));	/* sysv naming */
 #endif
-    else if (STRNCMP(pty, "pty", 3) && STRNCMP(pty, "tty", 3)) {
+    else if (STRNCMP(pty, "pty", 3) && STRNCMP(pty, "tty", 3) &&
+        STRNCMP(pty, "pts/", 4)) {
 	rxvt_print_error("can't parse tty name \"%s\"", pty);
 	return;
     }
