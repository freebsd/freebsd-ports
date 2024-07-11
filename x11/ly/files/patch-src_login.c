--- src/login.c.orig	2023-06-15 07:30:09 UTC
+++ src/login.c
@@ -19,9 +19,13 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <unistd.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <xcb/xcb.h>
 
+#include <sys/param.h>
+#include <sys/types.h>
+#include <login_cap.h>
+
 int get_free_display()
 {
 	char xlock[1024];
@@ -214,13 +218,13 @@
 	// clean env
 	environ[0] = NULL;
 	
-	setenv("TERM", term ? term : "linux", 1);
+	setenv("TERM", term ? term : "xterm", 1);
 	setenv("HOME", pwd->pw_dir, 1);
 	setenv("PWD", pwd->pw_dir, 1);
 	setenv("SHELL", pwd->pw_shell, 1);
 	setenv("USER", pwd->pw_name, 1);
 	setenv("LOGNAME", pwd->pw_name, 1);
-	setenv("LANG", lang ? lang : "C", 1);
+	setenv("LANG", lang ? lang : "C.UTF-8", 1);
 
 	// Set PATH if specified in the configuration
 	if (strlen(config.path))
@@ -259,9 +263,15 @@
 
 void env_xdg(const char* tty_id, const char* desktop_name)
 {
+	// The "/run/user/%d" directory is not available on FreeBSD. It is much
+	// better to stick to the defaults and let applications using
+	// XDG_RUNTIME_DIR to fall back to directories inside user's home
+	// directory.
+	/*
     char user[20];
     snprintf(user, 20, "/run/user/%d", getuid());
     setenv("XDG_RUNTIME_DIR", user, 0);
+    */
     setenv("XDG_SESSION_CLASS", "user", 0);
     setenv("XDG_SESSION_ID", "1", 0);
     setenv("XDG_SESSION_DESKTOP", desktop_name, 0);
@@ -269,8 +279,8 @@
     setenv("XDG_VTNR", tty_id, 0);
 }
 
-void add_utmp_entry(
-	struct utmp *entry,
+void add_utmpx_entry(
+	struct utmpx *entry,
 	char *username,
 	pid_t display_pid
 ) {
@@ -281,24 +291,23 @@
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
 
 void xauth(const char* display_name, const char* shell, char* pwd)
@@ -598,6 +607,16 @@
 			exit(EXIT_FAILURE);
 		}
 
+		ok = setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL);
+
+		if (ok != 0)
+		{
+			dgn_throw(DGN_USER_UID);
+			exit(EXIT_FAILURE);
+		}
+
+		/* This is done by setusercontext() on FreeBSD. */
+#if 0
 		ok = setgid(pwd->pw_gid);
 
 		if (ok != 0)
@@ -613,10 +632,11 @@
 			dgn_throw(DGN_USER_UID);
 			exit(EXIT_FAILURE);
 		}
+#endif
 
 		// get a display
 		char vt[5];
-		snprintf(vt, 5, "vt%d", config.tty);
++		snprintf(vt, 5, "vt%d", config.vt);
 
 		// set env (this clears the environment)
 		env_init(pwd);
@@ -671,13 +691,13 @@
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
 
