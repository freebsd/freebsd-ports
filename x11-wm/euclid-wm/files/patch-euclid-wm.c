--- euclid-wm.c.orig	2015-09-06 19:45:03 UTC
+++ euclid-wm.c
@@ -93,9 +93,11 @@ Thus the one or more of the following no
 
 
 //this is a hack
-FILE *popen(char *, char *);
+//FILE *popen(char *, char *);
+FILE *popen(const char *, const char *);
 int pclose (FILE *);
-char *tempnam(char *,char*);
+//char *tempnam(char *,char*);
+char *tempnam(const char *, const char *);
 
 //determines size of a static array (won't work with pointers)
 #define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))
