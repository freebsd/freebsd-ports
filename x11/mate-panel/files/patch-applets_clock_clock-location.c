--- applets/clock/clock-location.c.orig	2022-01-26 15:27:16 UTC
+++ applets/clock/clock-location.c
@@ -451,19 +451,27 @@ clock_location_get_offset (ClockLocation *loc)
 
         unsetenv ("TZ");
         tm = localtime (&t);
+#ifdef __FreeBSD__
+        sys_timezone = -tm->tm_gmtoff;
+#else        
         sys_timezone = timezone;
 
         if (tm->tm_isdst > 0) {
                 sys_timezone -= 3600;
         }
+#endif
 
         setenv ("TZ", priv->timezone, 1);
         tm = localtime (&t);
+#ifdef __FreeBSD__
+        local_timezone = -tm->tm_gmtoff;
+#else        
         local_timezone = timezone;
 
         if (tm->tm_isdst > 0) {
                 local_timezone -= 3600;
         }
+#endif
 
         offset = local_timezone - sys_timezone;
 
