--- ./modules/FvwmWinList/ButtonArray.c.orig	1994-05-09 17:08:28.000000000 +0000
+++ ./modules/FvwmWinList/ButtonArray.c	2009-03-11 09:42:51.000000000 +0000
@@ -14,6 +14,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <X11/Xlib.h>
 #include "ButtonArray.h"
 #include "Mallocs.h"
