--- xwatchwin.c.orig	Tue Nov 28 16:26:07 1995
+++ xwatchwin.c	Sun Sep  3 12:07:17 2000
@@ -77,19 +77,20 @@
 
 /* --------------------------------------------------------------------- */
 
-void
+int
 main(int argc, char **argv)
 {
     Window          watchWin;
     int             i, strPos, optIndex;
     extern char    *optarg;
     extern int      optind;
-    int             windowID, updateTime = DEFSLEEPTIME;
+    long int        windowID;
+    int             updateTime = DEFSLEEPTIME;
     Bool            windowIDSet = False, updateTimeSet = False;
     int             optionsNeeded = 3, numoferrs = 0;
 
     /* get arguments */
-    while ((optIndex = getopt(argc, argv, "u:w:v")) >= 0) {
+    while ((optIndex = getopt(argc, argv, "u:w:v")) != -1) {
 	switch (optIndex) {
 	case 'u':
 	    updateTime = atoi(optarg);
@@ -170,12 +171,15 @@
 	fprintf(stderr, "Could not find the window you specified.\n");
 	exit(1);
     }
+
+    exit(0);
 }
 
 /* --------------------------------------------------------------------- */
 
 /* Takes two strings, removes spaces from the second,... */
 /* ...and compares them..  Returns 1 if equal, 0 if not. */
+int
 WinNamesEqual(char *str1, char *str2)
 {
     char            tempStr[STRINGLENGTH], *tempStrPtr;
