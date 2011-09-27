--- lib/libxview/ttysw/tty_init.c.orig	1993-06-28 22:17:19.000000000 -0700
+++ lib/libxview/ttysw/tty_init.c	2011-09-26 12:14:34.093549504 -0700
@@ -14,6 +14,7 @@
  * Ttysw initialization, destruction and error procedures
  */
 
+#include <sys/param.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -23,10 +24,17 @@
 
 #include <xview_private/portable.h>	/* for XV* defines and termios */
 
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+#define SVR4
+#define XV_USE_SVR4_PTYS
+#endif
+
 #ifdef	XV_USE_SVR4_PTYS
+#if !(defined(__FreeBSD_version) && __FreeBSD_version > 900007)
 #include <sys/stream.h>
 #include <sys/stropts.h>
 #include <sys/bufmod.h>
+#endif
 #endif	/* XV_USE_SVR4_PTYS */
 
 #ifndef SVR4
@@ -82,7 +90,11 @@
 
 extern char    *strncpy();
 extern char    *strcpy();
+#if (defined(BSD) && (BSD >= 199306))
+extern off_t	lseek();
+#else
 extern long     lseek();
+#endif
 char           *textsw_checkpoint_undo();
 
 /* static */ void ttysw_parseargs();
@@ -106,6 +118,7 @@
 
 extern int      ttysel_use_seln_service;
 
+static int	ttyinit();
 
 struct ttysw_createoptions {
     int             becomeconsole;	/* be the console */
@@ -403,14 +416,22 @@
     int             fdflags;
 
 #ifdef SVR4
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+    if ((fdflags = fcntl(fd, F_GETFL, 0)) == -1)
+#else
     if ((fdflags = xv_fcntl(fd, F_GETFL, 0)) == -1)
+#endif
 #else
     if ((fdflags = fcntl(fd, F_GETFL, 0)) == -1)
 #endif
 	return (-1);
     fdflags |= FNDELAY;
 #ifdef SVR4
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+    if (fcntl(fd, F_SETFL, fdflags) == -1)
+#else
     if (xv_fcntl(fd, F_SETFL, fdflags) == -1)
+#endif
 #else
     if (fcntl(fd, F_SETFL, fdflags) == -1)
 #endif
@@ -518,6 +539,9 @@
     (void) dup2(ttysw->ttysw_tty, 2);
     (void) close(ttysw->ttysw_tty);
 
+#if (defined(BSD) && (BSD >= 199103))
+    (void) ioctl(0, TIOCSCTTY, NULL);
+#endif
     if (*argv == (char *) NULL || strcmp("-c", *argv) == 0) {
 	/* Process arg list */
 	int             argc;
@@ -544,15 +568,25 @@
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
 
@@ -739,7 +773,9 @@
 
 #ifdef SB_NO_DROPS /* defined as result of including new bufmod.h */
 
+#if !defined(__FreeBSD_version)
     if(ioctl(pty, I_PUSH, "bufmod") == -1) { /* some buffering ... */
+#endif
       
       /* we can't push bufmod... this means we're probably 
 	 running on a generic SVR4 system - we can ignore this
@@ -864,13 +900,16 @@
 #endif SB_NO_DROPS
 
 
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
@@ -879,12 +918,15 @@
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
  
 #endif /* SVR4 */
 
@@ -955,7 +997,11 @@
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
@@ -1007,13 +1053,22 @@
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
