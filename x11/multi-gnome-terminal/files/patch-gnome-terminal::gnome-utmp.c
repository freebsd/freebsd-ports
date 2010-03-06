--- gnome-terminal/gnome-utmp.c
+++ gnome-terminal/gnome-utmp.c
@@ -33,8 +33,6 @@
 #  endif
 #endif
 
-#include <utmp.h>
-
 #if defined(HAVE_LASTLOG_H)
 #    include <lastlog.h>
 #endif
@@ -45,6 +43,8 @@
 
 #if defined(HAVE_UTMPX_H)
 #    include <utmpx.h>
+#else
+#    include <utmp.h>
 #endif
 
 #if defined(HAVE_TTYENT_H)
