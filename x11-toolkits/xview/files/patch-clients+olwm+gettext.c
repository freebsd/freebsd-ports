--- clients/olwm/gettext.c.orig	Fri Oct 17 11:24:49 2003
+++ clients/olwm/gettext.c	Fri Oct 17 11:30:14 2003
@@ -20,7 +20,10 @@
 char *_gettext();
 char *in_path();
 char *fgets(), *getenv();
-caddr_t mmap(), calloc();
+caddr_t calloc();
+#ifndef __FreeBSD__
+caddr_t mmap();
+#endif
 
 static struct domain_binding *firstbind=0, *lastbind=0;
 
