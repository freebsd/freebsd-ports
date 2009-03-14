--- ./modules/FvwmWinList/Mallocs.c.orig	1994-09-14 20:07:21.000000000 +0000
+++ ./modules/FvwmWinList/Mallocs.c	2009-03-11 09:42:43.000000000 +0000
@@ -33,6 +33,8 @@
 #include "../../fvwm/alpha_header.h"
 #endif /* NEEDS_ALPHA_HEADER */
 
+#include "Mallocs.h"
+
 extern char *Module;
 
 /******************************************************************************
