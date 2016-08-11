--- common/src/Locale.cc.orig	2016-05-11 16:14:20 UTC
+++ common/src/Locale.cc
@@ -258,22 +258,8 @@ Locale::get_week_start()
 
 #ifdef PLATFORM_OS_UNIX
   union { unsigned int word; char *string; } langinfo;
-  gint week_1stday = 0;
-  gint first_weekday = 1;
-  guint week_origin;
-  
-  langinfo.string = nl_langinfo(_NL_TIME_FIRST_WEEKDAY);
-  first_weekday = langinfo.string[0];
-  langinfo.string = nl_langinfo(_NL_TIME_WEEK_1STDAY);
-  week_origin = langinfo.word;
-  if (week_origin == 19971130) /* Sunday */
-    week_1stday = 0;
-  else if (week_origin == 19971201) /* Monday */
-    week_1stday = 1;
-  else
-    g_warning ("Unknown value of _NL_TIME_WEEK_1STDAY.\n");
-
-  week_start = (week_1stday + first_weekday - 1) % 7;
+  langinfo.string = nl_langinfo(DAY_1);
+  week_start = langinfo.string[0];
 #endif
 
   return week_start;
