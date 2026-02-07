--- include/greet.h.orig	2022-12-03 21:38:28 UTC
+++ include/greet.h
@@ -45,7 +45,7 @@ from The Open Group.
 # define GETPWNAM_ARGS /*unknown*/
 #endif
 
-#if defined(__FreeBSD__) || defined(__bsdi__) || defined(__osf__)
+#if defined(__bsdi__) || defined(__osf__)
 # define SETGRENT_TYPE int
 #else
 # define SETGRENT_TYPE void
