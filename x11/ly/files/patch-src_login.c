--- src/login.c.orig	2019-09-21 16:00:16 UTC
+++ src/login.c
@@ -239,9 +239,15 @@ void env_init(struct passwd* pwd, const char* display_
 
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
@@ -553,7 +559,7 @@ void auth(
 
 		snprintf(display_name, 3, ":%d", display_id);
 		snprintf(tty_id, 3, "%d", config.tty);
-		snprintf(vt, 5, "vt%d", config.tty);
+		snprintf(vt, 5, "vt%d", config.vt);
 
 		// set env
 		env_init(pwd, display_name);
