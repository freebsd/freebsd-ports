--- src/logging.c
+++ src/logging.c
@@ -131,6 +131,9 @@
 	STRNCPY(ut_id, (pty + 3), sizeof(ut_id));
     else
 #ifndef USE_SYSV_UTMP
+    if (!strncmp(pty, "pts/", 4))
+	STRNCPY(ut_id, (pty + 4), sizeof(ut_id));
+    else
     {
 	print_error("can't parse tty name \"%s\"", pty);
 	ut_id[0] = '\0';	/* entry not made */
