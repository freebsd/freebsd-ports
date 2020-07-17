pam_unix(8) requires root priveleges to access master.passwd(5)
but don't keep root for non-authentication activities.

--- pam.c.orig	2019-01-29 19:48:00 UTC
+++ pam.c
@@ -12,15 +12,40 @@
 static char *pw_buf = NULL;
 
 void initialize_pw_backend(int argc, char **argv) {
+#ifdef __linux__
 	if (getuid() != geteuid() || getgid() != getegid()) {
 		swaylock_log(LOG_ERROR,
 			"swaylock is setuid, but was compiled with the PAM"
 			" backend. Run 'chmod a-s %s' to fix. Aborting.", argv[0]);
 		exit(EXIT_FAILURE);
 	}
+#else
+	if (geteuid() != 0) {
+		swaylock_log(LOG_ERROR,
+				"swaylock needs to be setuid for pam_unix(8) to read /etc/master.passwd");
+		exit(EXIT_FAILURE);
+	}
+#endif
+
 	if (!spawn_comm_child()) {
 		exit(EXIT_FAILURE);
 	}
+
+#ifndef __linux__
+	if (setgid(getgid()) != 0) {
+		swaylock_log_errno(LOG_ERROR, "Unable to drop root");
+		exit(EXIT_FAILURE);
+	}
+	if (setuid(getuid()) != 0) {
+		swaylock_log_errno(LOG_ERROR, "Unable to drop root");
+		exit(EXIT_FAILURE);
+	}
+	if (setuid(0) != -1) {
+		swaylock_log_errno(LOG_ERROR, "Unable to drop root (we shouldn't be "
+			"able to restore it after setuid)");
+		exit(EXIT_FAILURE);
+	}
+#endif
 }
 
 static int handle_conversation(int num_msg, const struct pam_message **msg,
