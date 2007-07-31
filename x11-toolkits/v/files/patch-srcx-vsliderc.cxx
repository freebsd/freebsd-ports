--- srcx/vsliderc.cxx.orig	2007-07-31 22:29:12.000000000 +0200
+++ srcx/vsliderc.cxx	2007-07-31 22:29:56.000000000 +0200
@@ -402,7 +402,7 @@
 //============================>>> CScollProcCB <<<=============================
   void CSliderScrollProcCB(Widget w, XtPointer This, XtPointer position)
   {
-    int pos = (int)position;
+    intptr_t pos = (intptr_t)position;
     ((vSliderCmd*)This)->ScrollProcCB(pos);
   }
 }
