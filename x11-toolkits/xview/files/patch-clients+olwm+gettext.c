--- clients/olwm/gettext.c.orig	Thu Aug 11 13:59:59 2005
+++ clients/olwm/gettext.c	Thu Aug 11 14:05:12 2005
@@ -16,11 +16,13 @@
 #endif
 
 char *malloc(), *strdup();
-char * dgettext();
+char * dgettext(char *domain_name, char *msg_id);
 char *_gettext();
 char *in_path();
 char *fgets(), *getenv();
+#ifndef __FreeBSD__
 caddr_t mmap(), calloc();
+#endif
 
 static struct domain_binding *firstbind=0, *lastbind=0;
 
