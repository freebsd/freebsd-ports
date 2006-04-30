--- applets/clock/clock.c.orig	Mon Oct 24 02:25:11 2005
+++ applets/clock/clock.c	Tue Nov 22 02:47:05 2005
@@ -47,7 +47,9 @@
 #include <dirent.h>
 #include <string.h>
 #include <time.h>
+#ifdef HAVE_LANGINFO_H
 #include <langinfo.h>
+#endif
 
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
@@ -545,7 +547,11 @@ clock_locale_format (void)
 {
         const char *am;
 
+#ifdef HAVE_LANGINFO_H
         am = nl_langinfo (AM_STR);
+#else
+	am = "AM";
+#endif
         return (am[0] == '\0') ? CLOCK_FORMAT_24 : CLOCK_FORMAT_12;
 }
 
