--- slock.c.orig	2016-02-17 12:36:44.640577000 -0800
+++ slock.c	2016-02-17 12:48:20.966625000 -0800
@@ -23,6 +23,10 @@
 #include <bsd_auth.h>
 #endif
 
+#if HAVE_PAM
+#include <security/pam_appl.h>
+#endif
+
 enum {
 	INIT,
 	INPUT,
@@ -85,7 +89,7 @@
 }
 #endif
 
-#ifndef HAVE_BSD_AUTH
+#if !defined(HAVE_BSD_AUTH) && !defined(HAVE_PAM)
 /* only run as root */
 static const char *
 getpw(void)
@@ -119,8 +123,41 @@
 }
 #endif
 
+#ifdef HAVE_PAM
+static int
+slock_conv (int nof_msg, const struct pam_message **msg, struct pam_response **resp, void *data) {
+	struct pam_response *r = calloc (nof_msg, sizeof **resp);
+	if (r == NULL) {
+		die("slock: malloc: %s", strerror(errno));
+	}
+
+	while (nof_msg--) {
+		r[nof_msg].resp_retcode = 0;
+		r[nof_msg].resp = strdup (data);
+	}
+
+	*resp = r;
+
+	return PAM_SUCCESS;
+}
+
+static int
+auth_pam (const char *user, char *pass) {
+	static struct pam_conv conv = {slock_conv, NULL};
+	pam_handle_t *ph;
+
+	conv.appdata_ptr = pass;
+
+	if (pam_start("slock", user, &conv, &ph) != PAM_SUCCESS) {
+		die("slock: pam_start");
+	}
+
+	return (pam_authenticate(ph, 0) == PAM_SUCCESS);
+}
+#endif
+
 static void
-#ifdef HAVE_BSD_AUTH
+#if defined(HAVE_BSD_AUTH) || defined(HAVE_PAM)
 readpw(Display *dpy)
 #else
 readpw(Display *dpy, const char *pws)
@@ -159,8 +196,10 @@
 			switch (ksym) {
 			case XK_Return:
 				passwd[len] = 0;
-#ifdef HAVE_BSD_AUTH
+#if defined (HAVE_BSD_AUTH)
 				running = !auth_userokay(getlogin(), NULL, "auth-xlock", passwd);
+#elif defined (HAVE_PAM)
+				running = !auth_pam(getlogin(), passwd);
 #else
 				running = !!strcmp(crypt(passwd, pws), pws);
 #endif
@@ -289,7 +328,7 @@
 
 int
 main(int argc, char **argv) {
-#ifndef HAVE_BSD_AUTH
+#if !defined(HAVE_BSD_AUTH) && !defined(HAVE_PAM)
 	const char *pws;
 #endif
 	Display *dpy;
@@ -308,7 +347,7 @@
 	if (!getpwuid(getuid()))
 		die("slock: no passwd entry for you\n");
 
-#ifndef HAVE_BSD_AUTH
+#if !defined(HAVE_BSD_AUTH) && !defined(HAVE_PAM)
 	pws = getpw();
 #endif
 
@@ -341,7 +380,7 @@
 	}
 
 	/* Everything is now blank. Now wait for the correct password. */
-#ifdef HAVE_BSD_AUTH
+#if defined(HAVE_BSD_AUTH) || defined(HAVE_PAM)
 	readpw(dpy);
 #else
 	readpw(dpy, pws);
