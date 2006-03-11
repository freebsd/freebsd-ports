--- srcx/vtimer.cxx.orig	Fri Apr  4 23:37:00 2003
+++ srcx/vtimer.cxx	Thu Mar  9 19:06:58 2006
@@ -95,7 +95,7 @@
 extern "C"
 {
 //============================>>> CtimerCB <<<==========================
-  void CtimerCB(XtPointer client_data, XtIntervalId* notUsed)
+  void CtimerCB(XtPointer client_data, XtIntervalId* notUsedVoid)
   { 
     //	timer tick callback
     //
