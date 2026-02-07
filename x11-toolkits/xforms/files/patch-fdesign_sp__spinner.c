--- fdesign/sp_spinner.c.orig	2013-12-14 13:26:25 UTC
+++ fdesign/sp_spinner.c
@@ -29,7 +29,7 @@
 #include "spec/spinner_spec.h"
 
 static FD_spinnerattrib * spn_attrib;
-FL_OBJECT *curobj;
+static FL_OBJECT * curobj;
 
 
 /***************************************
