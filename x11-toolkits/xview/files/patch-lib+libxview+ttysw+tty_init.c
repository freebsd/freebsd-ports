--- lib/libxview/ttysw/tty_init.c.orig	2012-02-07 17:09:17.565198180 -0800
+++ lib/libxview/ttysw/tty_init.c	2012-02-07 17:16:27.392427537 -0800
@@ -14,6 +14,7 @@
  * Ttysw initialization, destruction and error procedures
  */
 
+#include <sys/param.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -36,7 +37,11 @@
 #endif
 
 #ifndef SVR4
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 #else
  /* #include <sys/sigaction.h> */  /* vmh - 7/16/90 The compiler chokes
   * on the redefinition of sigaction, and on siginfo_t. Removing this
@@ -94,7 +99,9 @@
 #define jcsetpgrp(p)	setpgrp((p),(p))
 #endif
 
-#ifndef __CYGWIN__
+#if (defined(BSD) && (BSD >= 199306))
+extern off_t  lseek();
+#elif !defined(__CYGWIN__)
 extern long     lseek();
 #endif
 char           *textsw_checkpoint_undo();
@@ -120,6 +127,7 @@
 
 extern int      ttysel_use_seln_service;
 
+static int	ttyinit();
 
 struct ttysw_createoptions {
     int             becomeconsole;	/* be the console */
@@ -574,6 +582,9 @@
     (void) dup2(ttysw->ttysw_tty, 2);
     (void) close(ttysw->ttysw_tty);
 
+#if (defined(BSD) && (BSD >= 199103))
+    (void) ioctl(0, TIOCSCTTY, NULL);
+#endif
     if (*argv == (char *) NULL || strcmp("-c", *argv) == 0) {
 	/* Process arg list */
 	int             argc;
@@ -600,17 +611,27 @@
  * ttcompat seems to leave things in a funny state and assumes
  * (seemingly) that login will fix things up.  Do it here.
  */
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+    if (tcgetattr (0, &tp) == -1)
+        perror("tcgetattr");
+#else
     if (ioctl (0, TCGETS, &tp) == -1)
         perror("ioctl TCGETS");
+#endif
     else {
         tp.c_lflag |= ECHO;
         tp.c_oflag |= ONLCR;
         tp.c_iflag |= ICRNL;
     }
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+    if (tcsetattr (0, TCSANOW, &tp) == -1)
+        perror("tcsetattr");
+#else
     if (ioctl (0, TCSETS, &tp) == -1)
         perror("ioctl TCSETS");
+#endif
 #endif /* BSD_TTY_COMPAT */
 #endif /* SVR4 */
 
     /* restore various signals to their defaults */
     signal (SIGINT, SIG_DFL);
@@ -801,7 +822,9 @@
 
 #ifdef SB_NO_DROPS /* defined as result of including new bufmod.h */
 
+#if !defined(__FreeBSD_version)
     if(ioctl(pty, I_PUSH, "bufmod") == -1) { /* some buffering ... */
+#endif
       
       /* we can't push bufmod... this means we're probably 
 	 running on a generic SVR4 system - we can ignore this
@@ -925,13 +948,16 @@
 
 #endif
 
+#ifndef __FreeBSD_version
     if (ioctl(pty, I_PUSH, "pckt") == -1) { /* must use getmsg for read */
         perror("push pckt");
 	return XV_ERROR;
     }
+#endif
 
     if ((tty = open(ptsname(pty),O_RDWR))<0)
         return XV_ERROR;
+#ifndef __FreeBSD_version
     if (ioctl(tty, I_PUSH, "ptem") == -1) {
         perror("push ptem");
 	return XV_ERROR;
@@ -940,12 +966,15 @@
         perror("push ldterm");
 	return XV_ERROR;
     }
+#endif
 #ifdef BSD_TTY_COMPAT
+#ifndef __FreeBSD_version
     if (ioctl(tty, I_PUSH, "ttcompat") == -1) { /* for csh */
         perror("push ttcompat");
 	return XV_ERROR;
     }
 #endif
+#endif
  
 #endif
 #endif
@@ -998,7 +1027,7 @@
  */
 
 #ifndef SVR4
-#if !defined __linux__ && !defined __CYGWIN__
+#if !defined __linux__ && !defined __CYGWIN__ && !(defined(__FreeBSD_version) && __FreeBSD_version > 900007)
 /*
  * Make entry in /etc/utmp for ttyfd. Note: this is dubious usage of
  * /etc/utmp but many programs (e.g. sccs) look there when determining who is
@@ -1013,13 +1042,17 @@
     /*
      * Update /etc/utmp
      */
-#ifndef SVR4
+#if !defined(SVR4) && !(defined(__FreeBSD_version) && __FreeBSD_version > 900007)
     struct utmp     utmp;
 #else
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
@@ -1035,8 +1068,13 @@
 	}
 	username = passwdent->pw_name;
     }
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+    utmp.ut_user[0] = '\0';	/* Set incase *username is 0 */
+    (void) strncpy(utmp.ut_user, username, sizeof(utmp.ut_user));
+#else
     utmp.ut_name[0] = '\0';	/* Set incase *username is 0 */
     (void) strncpy(utmp.ut_name, username, sizeof(utmp.ut_name));
+#endif
     /*
      * Get line (tty) name
      */
@@ -1051,7 +1089,7 @@
     /*
      * Get start time
      */
-#ifndef SVR4
+#if !defined(SVR4) && !(defined(__FreeBSD_version) && __FreeBSD_version > 900007)
     (void) time((time_t *) (&utmp.ut_time));
 #else
     (void) time((time_t *) (&utmp.ut_tv));
@@ -1071,13 +1109,24 @@
 		XV_MSG("Add tty[qrs][0-f] to /etc/ttys file.\n"));
 	return (0);
     }
+#if !(defined(BSD) && (BSD >= 199103))
     if ((f = open("/etc/utmp", 1)) >= 0) {
+#else
+#if defined(__FreeBSD_version) && __FreeBSD_version < 900007
+    if ((f = open(_PATH_UTMP, 1)) >= 0) {
+#endif
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
@@ -1093,7 +1142,11 @@
     /*
      * Update /etc/utmp
      */
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+    struct utmpx    utmp;
+#else
     struct utmp     utmp;
+#endif
     struct passwd  *passwdent;
     int             f;
     char           *ttyn;
@@ -1117,8 +1170,13 @@
       if (!(*username))
         utmp.ut_type = DEAD_PROCESS; /* "" as username, logging out */
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+    utmp.ut_id[0] = '\0';	/* Set incase *username is 0 */
+    (void) strncpy(utmp.ut_id, username, sizeof(utmp.ut_id));
+#else
     utmp.ut_name[0] = '\0';	/* Set incase *username is 0 */
     (void) strncpy(utmp.ut_name, username, sizeof(utmp.ut_name));
+#endif
     /*
      * Get line (tty) name
      */
@@ -1135,14 +1193,32 @@
     /*
      * Get start time
      */
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+    {
+      struct timeval tv;
+
+      if (gettimeofday(&tv, NULL))
+	return errno;
+      utmp.ut_tv.tv_sec = tv.tv_sec;
+      utmp.ut_tv.tv_usec = tv.tv_usec;
+    }
+#else
     (void) time((time_t *) (&utmp.ut_time));
+#endif
     /*
      * Put utmp in /etc/utmp
      */
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+    setutxent();
+    (void)getutxline(&utmp);
+    pututxline(&utmp);
+    endutxent();
+#else
     setutent();
     (void)getutline(&utmp);
     pututline(&utmp);
     endutent();
+#endif
     return 1;        /* Return dummy value for ttyslot number */
 }
 #endif
