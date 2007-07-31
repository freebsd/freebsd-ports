--- srcx/vcanvas.cxx.orig	2007-07-31 22:24:59.000000000 +0200
+++ srcx/vcanvas.cxx	2007-07-31 22:25:47.000000000 +0200
@@ -1326,7 +1326,7 @@
 	  }
       }
 #else
-    int pos = (int)position;
+    intptr_t pos = (intptr_t)position;
     ((vCanvasPane*)This)->HScrollProcCB(pos);
 #endif
   }
@@ -1365,7 +1365,7 @@
 	  }
       }
 #else
-    int pos = (int)position;
+    intptr_t pos = (intptr_t)position;
     ((vCanvasPane*)This)->VScrollProcCB(pos);
 #endif
   }
