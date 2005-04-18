
$FreeBSD$

--- xtrlock.c.orig	Sun Aug 22 18:08:41 2004
+++ xtrlock.c	Sun Aug 22 18:08:58 2004
@@ -31,11 +31,9 @@
 #include <grp.h>
 #include <limits.h>
 #include <string.h>
-#include <crypt.h>
 #include <unistd.h>
 #include <math.h>
 #include <ctype.h>
-#include <values.h>
 
 #ifdef SHADOW_PWD
 #include <shadow.h>

