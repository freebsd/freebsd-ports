--- src/login.c.orig	2020-02-03 07:51:05 UTC
+++ src/login.c
@@ -18,7 +18,7 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <unistd.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <xcb/xcb.h>
 
 int get_free_display()
@@ -243,9 +243,15 @@ void env_init(struct passwd* pwd)
 
 void env_xdg(const char* tty_id, const enum display_server display_server)
 {
-	char user[15];
-	snprintf(user, 15, "/run/user/%d", getuid());
-	setenv("XDG_RUNTIME_DIR", user, 0);
+	// The "/run/user/%d" directory is not available on FreeBSD. It is much
+	// better to stick to the defaults and let applications using
+	// XDG_RUNTIME_DIR to fall back to directories inside user's home
+	// directory.
+	/*
+	 * char user[15];
+	 * snprintf(user, 15, "/run/user/%d", getuid());
+	 * setenv("XDG_RUNTIME_DIR", user, 0);
+	 */
 	setenv("XDG_SESSION_CLASS", "user", 0);
 	setenv("XDG_SEAT", "seat0", 0);
 	setenv("XDG_VTNR", tty_id, 0);
@@ -271,8 +277,8 @@ void env_xdg(const char* tty_id, const enum display_se
 	}
 }
 
-void add_utmp_entry(
-	struct utmp *entry,
+void add_utmpx_entry(
+	struct utmpx *entry,
 	char *username,
 	pid_t display_pid
 ) {
@@ -283,24 +289,23 @@ void add_utmp_entry(
 	/* only correct for ptys named /dev/tty[pqr][0-9a-z] */
 	strcpy(entry->ut_id, ttyname(STDIN_FILENO) + strlen("/dev/tty"));
 
-	time((long int *) &entry->ut_time);
+	time((long int *) &entry->ut_tv.tv_sec);
 
-	strncpy(entry->ut_user, username, UT_NAMESIZE);
-	memset(entry->ut_host, 0, UT_HOSTSIZE);
-	entry->ut_addr = 0;
-	setutent();
+	strncpy(entry->ut_user, username, sizeof(entry->ut_user));
+	memset(entry->ut_host, 0, sizeof(entry->ut_host));
+	setutxent();
 
-	pututline(entry);
+	pututxline(entry);
 }
 
-void remove_utmp_entry(struct utmp *entry) {
+void remove_utmpx_entry(struct utmpx *entry) {
 	entry->ut_type = DEAD_PROCESS;
-	memset(entry->ut_line, 0, UT_LINESIZE);
-	entry->ut_time = 0;
-	memset(entry->ut_user, 0, UT_NAMESIZE);
-	setutent();
-	pututline(entry);
-	endutent();
+	memset(entry->ut_line, 0, sizeof(entry->ut_line));
+	entry->ut_tv.tv_sec = 0;
+	memset(entry->ut_user, 0, sizeof(entry->ut_user));
+	setutxent();
+	pututxline(entry);
+	endutxent();
 }
 
 void xauth(const char* display_name, const char* shell, const char* dir)
@@ -581,7 +586,7 @@ void auth(
 		char vt[5];
 
 		snprintf(tty_id, 3, "%d", config.tty);
-		snprintf(vt, 5, "vt%d", config.tty);
+		snprintf(vt, 5, "vt%d", config.vt);
 
 		// set env
 		env_init(pwd);
@@ -636,13 +641,13 @@ void auth(
 	}
 
 	// add utmp audit
-	struct utmp entry;
-	add_utmp_entry(&entry, pwd->pw_name, pid);
+	struct utmpx entry;
+	add_utmpx_entry(&entry, pwd->pw_name, pid);
 
 	// wait for the session to stop
 	int status;
 	waitpid(pid, &status, 0);
-	remove_utmp_entry(&entry);
+	remove_utmpx_entry(&entry);
 
 	reset_terminal(pwd);
 
