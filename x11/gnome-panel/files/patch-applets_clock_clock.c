--- applets/clock/clock.c.orig	Tue Jan 13 11:55:58 2004
+++ applets/clock/clock.c	Wed Jan 14 15:43:39 2004
@@ -47,7 +47,9 @@
 #include <dirent.h>
 #include <string.h>
 #include <time.h>
+#ifdef HAVE_LANGINFO_H
 #include <langinfo.h>
+#endif
 
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
@@ -539,7 +541,11 @@
 {
         const char *am;
 
+#ifdef HAVE_LANGINFO_H
         am = nl_langinfo (AM_STR);
+#else
+	am = "AM";
+#endif
         return (am[0] == '\0') ? CLOCK_FORMAT_24 : CLOCK_FORMAT_12;
 }
 
