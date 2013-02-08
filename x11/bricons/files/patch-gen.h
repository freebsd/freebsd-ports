--- gen.h.orig	1993-01-22 05:27:33.000000000 +0900
+++ gen.h	2013-01-12 22:14:38.000000000 +0900
@@ -1,6 +1,7 @@
 static char* sccs_gen_h = "%W%%G%";
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/param.h>
 #include <sys/stat.h>
 #include <X11/Xos.h>
@@ -11,8 +12,8 @@
 #include <X11/Xaw/MenuButton.h>
 #include <X11/Shell.h>
 #include <X11/Xaw/Cardinals.h>
-/* #include <stdlib.h>  */
-#include <malloc.h>
+#include <stdlib.h>
+/* #include <malloc.h> */
 #include <ctype.h>
 #include <unistd.h>
 #include "xpm.h"
@@ -76,10 +77,6 @@
 
 ChildInfo	ci_ptr[MAXPROCS];
 
-/* forward declarations */
-int	fprintf(), ungetc(), fclose(), fscanf();
-char	*strcpy(), *getenv(), *malloc(); 
-
 typedef int     bool_t;
 
 Pixmap  pix, pix2;
