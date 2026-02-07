--- fdesign/sp_twheel.c.orig	2014-06-28 20:34:29 UTC
+++ fdesign/sp_twheel.c
@@ -38,7 +38,7 @@
 #include "spec/twheel_spec.h"
 
 static FD_twheelattrib * twheel_attrib;
-FL_OBJECT * curobj;
+static FL_OBJECT * curobj;
 
 
 /***************************************
