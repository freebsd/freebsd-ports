--- clients/olwm/defaults.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/defaults.c	2012-02-02 15:14:16.298703787 -0800
@@ -25,9 +25,9 @@
 #include <X11/Xutil.h>
 #include <X11/Xatom.h>
 #include <X11/Xresource.h>
-#ifdef OW_I18N_L4
+/* #ifdef OW_I18N_L4 */
 #include <sys/param.h>
-#endif
+/* #endif */
 
 #include "i18n.h"
 #include "ollocale.h"
@@ -82,7 +82,7 @@
 	if (homedir != NULL) {
 	    (void) strcpy(filename, homedir);
 	    (void) strcat(filename, "/.Xdefaults-");
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(BSD4_4)
 	    if (0 == gethostname(hostname, sizeof(hostname), &namelen)) {
 #else
 	    if (0 == gethostname(hostname, sizeof(hostname))) {
