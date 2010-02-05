--- zvt/gnome-utmp.c.orig	2010-02-05 12:06:29.000000000 +0100
+++ zvt/gnome-utmp.c	2010-02-05 12:07:29.000000000 +0100
@@ -33,8 +33,6 @@
 #  endif
 #endif
 
-#include <utmp.h>
-
 #if defined(HAVE_LASTLOG_H)
 #    include <lastlog.h>
 #endif
