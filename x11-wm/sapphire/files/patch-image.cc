--- image.cc.orig	2001-12-31 17:48:53.000000000 -0500
+++ image.cc	2007-09-10 13:43:45.000000000 -0400
@@ -22,7 +22,9 @@
 
 #include "sapphire.hh"
 
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 
 #ifdef GradientHack
 #  include <math.h>
