--- lib/libxview/ttysw/tty_init.c.orig	Tue Jun 29 00:17:19 1993
+++ lib/libxview/ttysw/tty_init.c	Fri Oct 17 09:40:42 2003
@@ -14,6 +14,7 @@
  * Ttysw initialization, destruction and error procedures
  */
 
+#include <sys/param.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -82,7 +83,11 @@
 
 extern char    *strncpy();
 extern char    *strcpy();
+#if (defined(BSD) && (BSD >= 199306))
+extern off_t	lseek();
+#else
 extern long     lseek();
+#endif
 char           *textsw_checkpoint_undo();
 
 /* static */ void ttysw_parseargs();
@@ -106,6 +111,7 @@
 
 extern int      ttysel_use_seln_service;
 
+static int	ttyinit();
 
 struct ttysw_createoptions {
     int             becomeconsole;	/* be the console */
@@ -518,6 +524,9 @@
     (void) dup2(ttysw->ttysw_tty, 2);
     (void) close(ttysw->ttysw_tty);
 
+#if (defined(BSD) && (BSD >= 199103))
+    (void) ioctl(0, TIOCSCTTY, NULL);
+#endif
     if (*argv == (char *) NULL || strcmp("-c", *argv) == 0) {
 	/* Process arg list */
 	int             argc;
@@ -955,7 +964,11 @@
     struct utmpx     utmp;
 #endif
     struct passwd  *passwdent;
+#if !(defined(BSD) && (BSD >= 199103))
     extern struct passwd *getpwuid();
+#else
+    struct passwd *getpwuid __P((uid_t));
+#endif
     int             f;
     char           *ttyn;
     extern char    *ttyname();
@@ -1007,13 +1020,22 @@
 		XV_MSG("Add tty[qrs][0-f] to /etc/ttys file.\n"));
 	return (0);
     }
+#if !(defined(BSD) && (BSD >= 199103))
     if ((f = open("/etc/utmp", 1)) >= 0) {
+#else
+    if ((f = open(_PATH_UTMP, 1)) >= 0) {
+#endif
 	(void) lseek(f, (long) (ttyslotuse * sizeof(utmp)), 0);
 	(void) write(f, (char *) &utmp, sizeof(utmp));
 	(void) close(f);
     } else {
 	(void) fprintf(stderr, 
+#if !(defined(BSD) && (BSD >= 199103))
 	XV_MSG("make sure that you can write /etc/utmp!\n"));
+#else
+	XV_MSG("make sure that you can write "));
+	    (void) fprintf(stderr, "%s!\n", _PATH_UTMP);
+#endif
 	return (0);
     }
     return (ttyslotuse);
