--- clients/olwm/gettext.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/gettext.c	2012-02-07 19:03:56.561212174 -0800
@@ -19,14 +19,14 @@
 #define bzero(a,b) memset(a,0,b)
 #endif
 
-#if !defined(__linux__) || !defined(__GLIBC__)
+#if !defined(__linux__) && !defined(__GLIBC__) && !defined(__FreeBSD__)
 char *malloc(), *strdup();
 #endif
-char * dgettext(char *, char *);
+char * dgettext(char *domain_name, char *msg_id);
 char *_gettext();
 char *in_path();
 char *fgets(), *getenv();
-#if !defined(__linux__) || !defined(__GLIBC__)
+#if !defined(__linux__) && !defined(__GLIBC__) && !defined(__FreeBSD__)
 caddr_t mmap(), calloc();
 #endif
 
