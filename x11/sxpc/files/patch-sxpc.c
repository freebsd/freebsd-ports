--- sxpc.c.orig	Mon Oct 21 18:22:21 2002
+++ sxpc.c	Mon Oct 21 18:24:45 2002
@@ -70,6 +70,8 @@
 #undef SO_LINGER
 #endif
 
+#define SYSV	/* path of least resistance... */
+
 char tfile[512];
 int compression=0; /* -1 uncompress, 0 no compression, 1 compress */
 struct sockaddr_in servaddr; 
@@ -925,7 +927,7 @@
     }
 
 #ifdef DOFORK
-#if defined(_POSIX_SOURCE) || defined(_IBMR2) || defined(__hpux) || defined(hpux) || defined(FreeBSD)
+#if defined(_POSIX_SOURCE) || defined(_IBMR2) || defined(__hpux) || defined(hpux) || defined(__FreeBSD__)
     setpgid(0, 0);
 #else
     setpgrp(getpid());
