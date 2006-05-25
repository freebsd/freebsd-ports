--- clients/clock/clock.c.orig	Tue Jun 29 00:11:39 1993
+++ clients/clock/clock.c	Sun Mar 26 16:29:50 2006
@@ -22,6 +22,7 @@
 #include  <stdio.h>
 #include  <pwd.h>
 #include  <math.h>
+#include  <time.h>
 #include  <xview/xview.h>
 #include  <xview/panel.h>
 #include  <xview/canvas.h>
@@ -146,6 +147,10 @@
 static Notify_value analog_timer_expired();
 static Notify_value icon_timer_expired();
 static Notify_value dig_timer_expired();
+static int min (int a, int b);
+static int seconds_on();
+static int date_on();
+static int armwidth();
 
 typedef enum {digital, analog} Face;
 
@@ -488,7 +493,7 @@
 init_images (c, w, h)
 	Clock c; int w, h;
 {
-	int now;
+	time_t now;
 	struct tm *tm;
 
 	/* resize the remote images */
@@ -866,7 +871,7 @@
 paint_date (c) 
 	Clock c;
 {
-	int now;
+	time_t now;
 	struct tm *tm;
 	char buf[25];
 	Frame f;
@@ -910,7 +915,8 @@
 paint_second_hand (c) 
 	Clock c; 
 {
-	int x, y, diameter, radius, now, fromrim, angle, height, width;
+	int x, y, diameter, radius, fromrim, angle, height, width;
+	time_t	now;
 	struct tm *tm;
 	ClockDisplay d;
 	Pixwin *pw;
@@ -993,7 +999,8 @@
 	Pixwin * pw;
 	Rectlist *area;
 {
-	int w, h, x, y, prw, prh, now;
+	int w, h, x, y, prw, prh;
+	time_t now;
 	struct tm *tm;
 	Clock c;
 
@@ -1020,7 +1027,7 @@
 	Pixwin *pw;
 	Rectlist *area;
 {
-	int now;
+	time_t now;
 	Font_string_dims size;
 	struct tm *tm;
 	Clock c;
@@ -1048,7 +1055,8 @@
 icon_timer_expired (me, which)
 {
 	static int	mins, hours;
-	int		now, w, h;
+	time_t		now;
+	int		w, h;
 	struct		tm *tm;
 	Font_string_dims size;
 	Clock		c;
@@ -1077,11 +1085,12 @@
 
 static Notify_value
 analog_timer_expired (me, which)
-	Notify_value	me;
+	Frame	me;
 	int		which;
 {
 	static int	mins, hours;
-	int		now, x, y, w, h, prw, prh;
+	time_t		now;
+	int		x, y, w, h, prw, prh;
 	struct		tm *tm;
 	Clock		c;
 
@@ -1154,7 +1163,8 @@
 	Pixwin *	pw;
 	Rectlist	*area;
 {
-	int		i, now, y_coord, fontHeight, fontWidth;
+	int		i, y_coord, fontHeight, fontWidth;
+	time_t		now;
 	struct tm	*tm;
 	Clock		c;
 	ClockDisplay		d;
@@ -1211,7 +1221,7 @@
 	int		which, invalidate;
 {
 	static int	mins, hours;
-	int		now;
+	time_t		now;
 	struct		tm *tm;
 	Clock		c;
 
@@ -1273,7 +1283,8 @@
 	Panel_item item;
 	Event *event;
 {
-	int w, h, now;
+	int w, h; 
+	time_t now;
 	struct tm *tm;
 	Clock c		= (Clock) xv_get (item, XV_KEY_DATA, key, 0);
 	ClockDisplay d	= c-> display;
@@ -1662,7 +1673,7 @@
 init_clck (argc, argv)
 	int  argc; char **argv;
 {
-	int now;
+	time_t now;
 	struct tm *tm;
 	Menu_item       tmp_item;
 	char    **argscanner = argv;
