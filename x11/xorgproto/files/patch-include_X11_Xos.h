--- include/X11/Xos.h.orig	2022-04-21 00:48:08 UTC
+++ include/X11/Xos.h
@@ -60,7 +60,7 @@ in this Software without prior written authorization f
  */
 
 # include <string.h>
-# if defined(__SCO__) || defined(__UNIXWARE__) || defined(__sun) || defined(__CYGWIN__) || defined(_AIX) || defined(__APPLE__)
+# if defined(__SCO__) || defined(__UNIXWARE__) || defined(__sun) || defined(__CYGWIN__) || defined(_AIX) || defined(__APPLE__) || defined(__FreeBSD__)
 #  include <strings.h>
 # else
 #  ifndef index
