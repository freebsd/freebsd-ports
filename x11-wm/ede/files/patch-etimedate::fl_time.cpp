--- etimedate/fl_time.cpp.orig	Sat Feb 28 04:50:39 2004
+++ etimedate/fl_time.cpp	Sat Feb 28 04:00:25 2004
@@ -86,7 +86,7 @@
     gettimeofday(&current_tv, 0);
     display_tv.tv_sec = current_tv.tv_sec;
     display_tv.tv_usec = current_tv.tv_usec;
-    display_time_tm = localtime(&current_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&current_tv.tv_sec);
 
     if(type() == FL_TIME_24HOUR) strftime(time_string, 19, "%2H:%2M", display_time_tm);
     else strftime(time_string, 19, "%2I:%2M %p", display_time_tm);
@@ -106,7 +106,7 @@
         gettimeofday(&current_tv, 0);
 
         display_tv.tv_sec = current_tv.tv_sec - different;
-        display_time_tm = localtime(&display_tv.tv_sec);
+        display_time_tm = localtime((time_t*)&display_tv.tv_sec);
 
         if(type() == FL_TIME_24HOUR) strftime(time_string, 19, "%2H:%2M", display_time_tm);
         else strftime(time_string, 19, "%2I:%2M %p", display_time_tm);
@@ -120,7 +120,7 @@
 {
     struct tm *display_time_tm;
 
-    display_time_tm = localtime(&display_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&display_tv.tv_sec);
     return display_time_tm->tm_hour;
 }
 
@@ -129,7 +129,7 @@
 {
     struct tm *display_time_tm;
 
-    display_time_tm = localtime(&display_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&display_tv.tv_sec);
     return display_time_tm->tm_min;
 }
 
@@ -138,7 +138,7 @@
 {
     struct tm *display_time_tm;
 
-    display_time_tm = localtime(&display_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&display_tv.tv_sec);
 
     if(type() == FL_TIME_24HOUR) strftime(time_string, 19, "%2H:%2M", display_time_tm);
     else strftime(time_string, 19, "%2I:%2M %p", display_time_tm);
@@ -151,7 +151,7 @@
 {
     struct tm *display_time_tm;
 
-    display_time_tm = localtime(&display_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&display_tv.tv_sec);
     display_time_tm->tm_hour = value;
     display_tv.tv_sec = mktime(display_time_tm);
 }
@@ -161,7 +161,7 @@
 {
     struct tm *display_time_tm;
 
-    display_time_tm = localtime(&display_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&display_tv.tv_sec);
     if(value < 0)
     {
         display_time_tm->tm_min = 59;
@@ -182,10 +182,17 @@
 void Fl_Time::settime()
 {
     struct tm *display_time_tm;
-    display_time_tm = localtime(&display_tv.tv_sec);
+    display_time_tm = localtime((time_t*)&display_tv.tv_sec);
     //  return display_time_tm->tm_min;
     time_t ct = mktime (display_time_tm);
+#if defined(__FreeBSD__)
+    struct timeval tp;
+    tp.tv_sec=ct;
+    tp.tv_usec=0;
+    if (settimeofday(&tp,0)!=0)
+#else
     if (stime(&ct)!=0)
+#endif
         fl_alert(_("Error setting time. You are probably not superuser!"));
 }
 
