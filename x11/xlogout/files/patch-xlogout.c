--- xlogout.c.orig	2009-03-27 18:58:31.000000000 +0100
+++ xlogout.c	2009-03-27 18:59:16.000000000 +0100
@@ -27,6 +27,7 @@
 /* An example of popup dialog boxes using X11R4 and the Athena widget set */
 
 #include <stdio.h>			/* For the Syntax message */
+#include <stdlib.h>
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include <X11/Xaw/Cardinals.h>
@@ -48,7 +49,7 @@ static XrmOptionDescRec options[] = {
 };
 
 
-void main (argc, argv)
+int main (argc, argv)
     int argc;
     char **argv;
 {
