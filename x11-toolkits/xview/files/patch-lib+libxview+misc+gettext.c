--- lib/libxview/misc/gettext.c.orig	Sun Jul 28 17:07:43 2002
+++ lib/libxview/misc/gettext.c	Sun Jul 28 17:08:14 2002
@@ -13,7 +13,9 @@
 char * dgettext(), *bindtextdomain();
 char *_gettext();
 char *fgets(), *getenv();
+#ifndef OS_HAS_MMAP
 caddr_t mmap();
+#endif
 
 static struct domain_binding *firstbind=0, *lastbind=0;
 
