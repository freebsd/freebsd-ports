
$FreeBSD$

--- applets/gen_util/clock.c	2002/05/14 14:08:16	1.1
+++ applets/gen_util/clock.c	2002/05/14 14:12:56
@@ -14,7 +14,9 @@
 #include <dirent.h>
 #include <string.h>
 #include <time.h>
+#ifdef HAVE_LANGINFO_H
 #include <langinfo.h>
+#endif
 
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
@@ -684,7 +686,11 @@
 	cd->hourformat = panel_applet_gconf_get_int (applet, KEY_HOUR_FORMAT, &error);
 	if (error || (cd->hourformat != 12 && cd->hourformat != 24)) {
 		/* if value is not valid, set it according to locale */
+#ifdef HAVE_LANGINFO_H
 		const char *am = nl_langinfo (AM_STR);
+#else
+		const char *am = "AM";
+#endif
 		cd->hourformat = (am[0] == '\0') ? 24 : 12;
 
 		if (error)
