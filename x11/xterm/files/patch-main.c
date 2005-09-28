
$FreeBSD$

--- main.c.orig
+++ main.c
@@ -379,14 +379,6 @@
 #include <util.h>
 #endif
 
-#ifdef __FreeBSD__
-#include <sys/types.h>
-#include <sys/ioctl.h>
-#include <termios.h>
-#include <libutil.h>
-#include <grp.h>
-#endif
-
 #if !defined(UTMP_FILENAME)
 #if defined(UTMP_FILE)
 #define UTMP_FILENAME UTMP_FILE
@@ -472,7 +464,7 @@
 
 static Bool added_utmp_entry = False;
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__)
 static gid_t utmpGid = -1;
 #endif
 
@@ -1606,7 +1598,7 @@
     strcpy(ptydev, PTYDEV);
 #endif
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__)
     get_pty(NULL, NULL);
     seteuid(getuid());
     setuid(getuid());
@@ -1944,7 +1936,7 @@
 	}
 #endif
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__)
 	if (resource.utmpInhibit) {
 	    /* Can totally revoke group privs */
 	    setegid(getgid());
@@ -2354,7 +2346,7 @@
 {
     int result = 1;
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__)
     static int m_tty = -1;
     static int m_pty = -1;
     struct group *ttygrp;
@@ -4061,7 +4053,7 @@
 	    }
 #endif /* USE_LASTLOG */
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__)
 	    /* Switch to real gid after writing utmp entry */
 	    utmpGid = getegid();
 	    if (getgid() != getegid()) {
@@ -4436,7 +4428,7 @@
 	&& (resource.ptyHandshake && added_utmp_entry)
 #endif /* OPT_PTY_HANDSHAKE */
 	) {
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__)
 	if (utmpGid != -1) {
 	    /* Switch back to group utmp */
 	    setegid(utmpGid);
