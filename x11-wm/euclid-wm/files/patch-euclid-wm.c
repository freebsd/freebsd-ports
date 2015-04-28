--- euclid-wm.c.orig	2013-12-16 15:18:31 UTC
+++ euclid-wm.c
@@ -93,9 +93,9 @@ Thus the one or more of the following no
 
 
 //this is a hack
-FILE *popen(char *, char *);
+FILE *popen(const char *,const char *);
 int pclose (FILE *);
-char *tempnam(char *,char*);
+char *tempnam(const char *,const char*);
 
 
 #define BINDINGS 65 
