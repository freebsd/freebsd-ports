--- src/logging.c.orig	2004-11-11 00:20:28 UTC
+++ src/logging.c
@@ -114,14 +114,22 @@ rxvt_makeutent(rxvt_t *r, int page, const char *pty, c
     if (!STRNCMP(pty, "/dev/", 5))
 		pty += 5;		/* skip /dev/ prefix */
 
+#ifdef PTYS_ARE_OPENPTY
+    if (!STRNCMP(pty, "pts", 3) || !STRNCMP(pty, "tty", 3)) {
+#else
     if (!STRNCMP(pty, "pty", 3) || !STRNCMP(pty, "tty", 3)) {
+#endif
 		STRNCPY(ut_id, (pty + 3), sizeof(ut_id));
     }
 #ifdef HAVE_UTMP_PID
     else if (sscanf(pty, "pts/%d", &i) == 1)
 		sprintf(ut_id, "vt%02x", (i & 0xff));	/* sysv naming */
 #endif
+#ifdef PTYS_ARE_OPENPTY
+    else if (!STRNCMP(pty, "pts", 3) || !STRNCMP(pty, "tty", 3)) {
+#else
     else if (STRNCMP(pty, "pty", 3) && STRNCMP(pty, "tty", 3)) {
+#endif
 		rxvt_print_error("can't parse tty name \"%s\"", pty);
 		return;
     }
