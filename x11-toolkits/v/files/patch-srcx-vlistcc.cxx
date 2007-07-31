--- srcx/vlistc.cxx.orig	2007-07-31 22:27:03.000000000 +0200
+++ srcx/vlistc.cxx	2007-07-31 22:28:09.000000000 +0200
@@ -676,7 +676,7 @@
 //============================>>> CScollProcCB <<<=============================
   void CScrollProcCB(Widget w, XtPointer This, XtPointer position)
   {
-    int pos = (int)position;
+    intptr_t pos = (intptr_t)position;
     ((vListCmd*)This)->ScrollProcCB(pos);
   }
 #endif	// Athena only
