Use "daylight" from "night_color_data.h" instead of <time.h>

In file included from base/options.cpp:15:
In file included from render/platform.h:10:
render/post/night_color_manager.h:478:28: error: use of undeclared identifier 'daylight'
        const bool isDay = daylight;
                           ^

--- render/post/night_color_manager.h.orig	2023-02-17 14:50:58 UTC
+++ render/post/night_color_manager.h
@@ -475,7 +475,7 @@ class night_color_manager (private)
         slow_update_timer = nullptr;
 
         const QDateTime now = QDateTime::currentDateTime();
-        const bool isDay = daylight;
+        const bool isDay = data.daylight;
         const int targetTemp = isDay ? data.temperature.day_target : data.temperature.night_target;
 
         // We've reached the target color temperature or the transition time is zero.
