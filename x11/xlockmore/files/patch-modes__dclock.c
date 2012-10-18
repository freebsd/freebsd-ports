--- ./modes/dclock.c.orig	2012-01-23 05:19:21.000000000 -0800
+++ ./modes/dclock.c	2012-10-17 15:20:26.000000000 -0700
@@ -376,11 +376,11 @@
 extern char *message;
 
 static unsigned long
-timeAtLastNewYear(long timeNow)
+timeAtLastNewYear(time_t timeNow)
 {
 	struct tm *t;
 
-	t = localtime((const time_t *) &timeNow);
+	t = localtime(&timeNow);
 	return (unsigned long)(t->tm_year);
 }
 
@@ -420,7 +420,7 @@
 }
 
 static void
-dayhrminsec(long timeCount, int tzoffset, char *string)
+dayhrminsec(time_t timeCount, int tzoffset, char *string)
 {
 	int days, hours, minutes, secs;
 	int bufsize, i;
@@ -675,7 +675,7 @@
 				"%a %b %d %Y", localtime(&(dp->timeold)));
 		}
 	  } else {
-		long timeNow, timeLocal;
+		time_t timeNow, timeLocal;
 		timeNow = seconds();
 		timeLocal = timeNow + dp->tzoffset;
 
@@ -950,7 +950,7 @@
 {
 	Display *display = MI_DISPLAY(mi);
 	dclockstruct *dp;
-	long timeNow, timeLocal;
+	time_t timeNow, timeLocal;
 	int i, j;
 
 	if (dclocks == NULL) {
@@ -1252,7 +1252,7 @@
 			dayhrminsec(MAYAN_TIME_START - timeLocal, dp->tzoffset, dp->strnew[1]);
 			dp->strpta[1] = dp->strnew[1];
 		} else {
-			struct tm *t = localtime((const time_t *) &timeLocal);
+			struct tm *t = localtime(&timeLocal);
 
 			if (dp->time24)
 			  (void) strftime(dp->strnew[0], STRSIZE, "%H:%M:%S", t);
