--- libzvt/gnome-utmp.c
+++ libzvt/gnome-utmp.c
@@ -33,7 +33,9 @@
 #  endif
 #endif
 
-#include <utmp.h>
+#if defined(HAVE_UTMP_H)
+#    include <utmp.h>
+#endif
 
 #if defined(HAVE_LASTLOG_H)
 #    include <lastlog.h>
