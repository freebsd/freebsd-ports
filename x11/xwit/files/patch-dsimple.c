--- dsimple.c~	Thu Oct 19 00:59:17 1995
+++ dsimple.c	Wed Jul 24 15:49:26 2002
@@ -5,6 +5,8 @@
 #include <X11/Xutil.h>
 #include <X11/cursorfont.h>
 #include <stdio.h>
+#include <stdlib.h>
+
 /*
  * Other_stuff.h: Definitions of routines in other_stuff.
  *
@@ -46,7 +48,7 @@
 char *Malloc(size)
      unsigned size;
 {
-	char *data, *malloc();
+	char *data;
 
 	if (!(data = malloc(size)))
 	  Fatal_Error("Out of memory!");
@@ -62,7 +64,7 @@
         char *ptr;
         int size;
 {
-	char *new_ptr, *realloc();
+	char *new_ptr;
 
 	if (!ptr)
 	  return(Malloc(size));
