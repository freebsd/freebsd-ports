--- appman.c.orig	Thu Mar 14 08:02:00 1996
+++ appman.c	Fri Oct 25 11:12:39 2002
@@ -1297,7 +1297,7 @@
 #endif
     FILE         *processfp = NULL;    /* file pointer to process */
     String *newargs, args;
-#if !defined(SYSV) && !defined(SVR4_0) && !defined(_POSIX_SOURCE) && !defined(__386BSD__)
+#if !defined(SYSV) && !defined(SVR4_0) && !defined(_POSIX_SOURCE) && !defined(__386BSD__) && !defined(__FreeBSD__)
     union wait       w_stat;   /* I'm not sure about the SYSV bit... */
 #else
     int              w_stat;
@@ -1843,7 +1843,7 @@
   extern String cwd;
 
   int pid;
-#if !defined(SYSV) && !defined(SVR4_0) && !defined(_POSIX_SOURCE)
+#if !defined(SYSV) && !defined(SVR4_0) && !defined(_POSIX_SOURCE) && !defined(__FreeBSD__)
   union wait status;
 #else
   int status;
