--- gettext.c.orig	Sun Sep 29 02:29:20 2002
+++ gettext.c	Sun Sep 29 02:29:47 2002
@@ -17,12 +17,14 @@
 #define bzero(a,b) memset(a,0,b)
 #endif
 
-char *malloc(), *strdup();
 char * dgettext();
 char *_gettext();
 char *in_path();
+#ifndef __FreeBSD__
+char *malloc(), *strdup();
 char *fgets(), *getenv();
 caddr_t mmap(), calloc();
+#endif
 
 #ifdef NOT
 static struct domain_binding *firstbind=0, *lastbind=0;
