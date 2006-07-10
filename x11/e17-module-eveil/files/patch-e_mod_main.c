--- e_mod_main.c.orig	Sun Jul  9 16:54:17 2006
+++ e_mod_main.c	Sun Jul  9 16:54:39 2006
@@ -633,7 +633,6 @@
 static double
 _epoch_find_date(char *date, int hour, int minute)
 {
-   extern long timezone;
    extern int daylight;
    struct tm ts;
    time_t t;
@@ -663,7 +662,6 @@
 static double
 _epoch_find_next(int day_monday, int day_tuesday, int day_wenesday, int day_thursday, int day_friday, int day_saturday, int day_sunday, int hour, int minute)
 {
-   extern long timezone;
    extern int daylight;
    int day_week[7];
    struct tm ts;
