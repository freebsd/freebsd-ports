--- src/actions.c.orig
+++ src/actions.c
@@ -78,6 +78,16 @@
 #define SHADE_STEPS	shadePars[(int)wPreferences.shade_speed].steps
 #define SHADE_DELAY	shadePars[(int)wPreferences.shade_speed].delay
 
+static int
+compareTimes(Time t1, Time t2)
+{
+	Time diff;
+
+	if (t1 == t2)
+		return 0;
+	diff = t1 - t2;
+	return (diff < 60000) ? 1 : -1;
+}
 
 /*
  *----------------------------------------------------------------------
@@ -99,11 +109,11 @@
 
     WWindow *old_focused;
     WWindow *focused=scr->focused_window;
-    int timestamp=LastTimestamp;
+    Time timestamp=LastTimestamp;
     WApplication *oapp=NULL, *napp=NULL;
     int wasfocused;
 
-    if (scr->flags.ignore_focus_events || LastFocusChange > timestamp)
+    if (scr->flags.ignore_focus_events || compareTimes(LastFocusChange, timestamp) > 0)
         return;
 
     if (!old_scr)


