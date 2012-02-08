--- clients/clock/clock.c.orig	2005-03-28 06:39:35.000000000 -0800
+++ clients/clock/clock.c	2012-02-02 15:08:00.272944648 -0800
@@ -147,6 +147,10 @@
 static Notify_value analog_timer_expired();
 static Notify_value icon_timer_expired();
 static Notify_value dig_timer_expired();
+static int min (int a, int b);
+static int seconds_on();
+static int date_on();
+static int armwidth();
 
 typedef enum {digital, analog} Face;
 
@@ -489,7 +493,7 @@
 init_images (c, w, h)
 	Clock c; int w, h;
 {
-	int now;
+	time_t now;
 	struct tm *tm;
 
 	/* resize the remote images */
@@ -1043,7 +1047,7 @@
 	Pixwin *pw;
 	Rectlist *area;
 {
-	int now;
+	time_t now;
 	Font_string_dims size;
 	struct tm *tm;
 	Clock c;
