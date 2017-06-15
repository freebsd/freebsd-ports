--- afterstep/alpha_header.h.orig	1996-08-22 20:48:18 UTC
+++ afterstep/alpha_header.h
@@ -7,11 +7,6 @@
 
 extern int select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
 
-/* string manipulation */
-#ifdef __GNUC__
-extern size_t strlen(char *);
-#endif
-
 /* Commented out 08/22/96 -- Thanks to Pierre Wendling 
 extern int bzero(char *, int);
 extern int gethostname (char *, int);
