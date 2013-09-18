--- clients/clock/clock.c.orig	2005-03-28 06:39:35.000000000 -0800
+++ clients/clock/clock.c	2013-09-17 22:46:52.832852384 -0700
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
@@ -535,7 +539,7 @@
 
 	if (initializing) {
 		initializing = 0;
-		return;
+		return 0;
 	}
 	c	= (Clock) xv_get (canvas, XV_KEY_DATA, key, 0);
 	cwidth	= (int) xv_get (canvas, XV_WIDTH, 0);
@@ -744,7 +748,7 @@
         pw      = c->pw;
         w       = d->hands.width;
         angle1  = d->hands.angle1;
-        if (angle1==-1) return;
+        if (angle1==-1) return 0;
         angle2  = d->hands.angle2;
 
         fromrim = (FROMRIM*w)/128;
@@ -1043,7 +1047,7 @@
 	Pixwin *pw;
 	Rectlist *area;
 {
-	int now;
+	time_t now;
 	Font_string_dims size;
 	struct tm *tm;
 	Clock c;
@@ -1386,12 +1390,12 @@
 			}
 			backup_values(o);
 			xv_set(o->frame, XV_SHOW, FALSE, 0);
-			return;
+			return 0;
 		}
 		backup_values(o);
 		clock_repaint_proc (c->canvas, c->pw, NULL); 
 		xv_set(o->frame, XV_SHOW, FALSE, 0);
-		return;
+		return 0;
 	}
 	clock_repaint_proc (c->canvas, c->pw, NULL); 
 	backup_values(o);
@@ -1862,7 +1866,7 @@
 {
 	int i, spacing, startAt, fontWidth, windowWidth;
 
-	if (c==NULL) return;
+	if (c==NULL) return 0;
 	fontWidth	= c-> display-> fontWidth;
 	windowWidth	= (int) xv_get (c->canvas, XV_WIDTH, 0);
 	spacing		= (1.0/8.0) * fontWidth;
@@ -1879,7 +1883,7 @@
 	int i, width, height,  nbnds = 1, npts[1], npts2[1];
 	ClockDisplay d;
 
-	if (c==NULL) return;
+	if (c==NULL) return 0;
 	npts[0]		= 4;
 	npts2[0]	= 6;
 	d		= c-> display;
