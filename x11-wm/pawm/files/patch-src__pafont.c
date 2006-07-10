--- src/pafont.c.orig	Thu Jun 29 20:30:15 2006
+++ src/pafont.c	Fri Jun 30 23:49:19 2006
@@ -44,7 +44,7 @@
 }
 
 
-PAFont pafont_create(Display *dpy, const char* id)
+PAFont pafont_create(Display *dpy, Visual *visual, const char* id)
 {
 	PAFont xlfdfont;
 	char fontname[20];
