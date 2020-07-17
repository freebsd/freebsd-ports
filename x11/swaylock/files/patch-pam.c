pam_unix(8) requires root priveleges to access master.passwd(5)

--- pam.c.orig	2019-01-29 19:48:00 UTC
+++ pam.c
@@ -12,12 +12,14 @@
 static char *pw_buf = NULL;
 
 void initialize_pw_backend(int argc, char **argv) {
+#ifdef __linux__
 	if (getuid() != geteuid() || getgid() != getegid()) {
 		swaylock_log(LOG_ERROR,
 			"swaylock is setuid, but was compiled with the PAM"
 			" backend. Run 'chmod a-s %s' to fix. Aborting.", argv[0]);
 		exit(EXIT_FAILURE);
 	}
+#endif
 	if (!spawn_comm_child()) {
 		exit(EXIT_FAILURE);
 	}
