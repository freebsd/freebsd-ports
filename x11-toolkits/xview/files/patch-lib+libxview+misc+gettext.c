--- lib/libxview/misc/gettext.c.orig	2012-02-03 16:44:26.083038397 -0800
+++ lib/libxview/misc/gettext.c	2012-02-03 16:47:10.335612397 -0800
@@ -10,10 +10,10 @@
 #include <string.h>
 #include <xview_private/gettext.h>
 
-char * dgettext(char *, char *), *bindtextdomain();
-char *_gettext();
+char * dgettext(char* domain_nane, char* msg_id), *bindtextdomain();
+static char *_gettext();
 char *fgets(), *getenv();
-#if (!defined(__linux__) || !defined(__GLIBC__)) && !defined(__CYGWIN__)
+#if (!defined(__linux__) || !defined(__GLIBC__)) && !defined(__CYGWIN__) && !defined(OS_HAS_MMAP) || !defined(__FreeBSD__)
 caddr_t mmap();
 #endif
 
