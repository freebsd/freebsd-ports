--- src/rxvt.h.orig	2013-10-03 01:05:18.000000000 +0200
+++ src/rxvt.h	2014-03-12 22:52:58.000000000 +0100
@@ -1540,7 +1540,7 @@
   bool scr_page (int nlines) NOTHROW;
   bool scr_page (enum page_dirn direction, int nlines) NOTHROW
   {
-    scr_page (direction * nlines);
+    return scr_page (direction * nlines);
   }
   bool scr_changeview (int new_view_start) NOTHROW;
   void scr_bell () NOTHROW;
