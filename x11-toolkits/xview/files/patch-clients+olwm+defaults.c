--- ./clients/olwm/defaults.c.orig	Tue Jun 29 07:11:43 1993
+++ ./clients/olwm/defaults.c	Sat Apr  1 18:26:06 2000
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
@@ -80,7 +80,11 @@ GetUserDefaults(dpy)
 	if (homedir != NULL) {
 	    (void) strcpy(filename, homedir);
 	    (void) strcat(filename, "/.Xdefaults-");
+#ifdef BSD4_4
+	    if (0 == gethostname(hostname, sizeof(hostname))) {
+#else
 	    if (0 == gethostname(hostname, sizeof(hostname), &namelen)) {
+#endif
 		(void) strcat(filename, hostname);
 		fileDB = XrmGetFileDatabase(filename);
 	    }
