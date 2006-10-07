--- lib/libxview/misc/gettext.c.orig	Thu Oct  5 18:45:03 2006
+++ lib/libxview/misc/gettext.c	Thu Oct  5 18:50:03 2006
@@ -10,10 +10,12 @@
 #include <xview_private/gettext.h>
 
 char *strdup();
-char * dgettext(), *bindtextdomain();
-char *_gettext();
+char * dgettext(char* domain_nane, char* msg_id), *bindtextdomain();
+static char *_gettext();
 char *fgets(), *getenv();
+#ifndef OS_HAS_MMAP
 caddr_t mmap();
+#endif
 
 static struct domain_binding *firstbind=0, *lastbind=0;
 
