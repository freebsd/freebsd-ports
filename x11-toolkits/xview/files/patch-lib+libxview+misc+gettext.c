--- lib/libxview/misc/gettext.c.orig	Sat Aug  6 21:47:27 2005
+++ lib/libxview/misc/gettext.c	Sat Aug  6 21:51:07 2005
@@ -10,10 +10,12 @@
 #include <xview_private/gettext.h>
 
 char *strdup();
-char * dgettext(), *bindtextdomain();
+char * dgettext(char* domain_nane, char* msg_id), *bindtextdomain();
 char *_gettext();
 char *fgets(), *getenv();
+#ifndef OS_HAS_MMAP
 caddr_t mmap();
+#endif
 
 static struct domain_binding *firstbind=0, *lastbind=0;
 
