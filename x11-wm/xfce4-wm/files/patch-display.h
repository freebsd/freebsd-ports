--- src/display.h.orig	2007-04-02 21:32:01.000000000 +0200
+++ src/display.h	2007-10-25 22:26:36.000000000 +0200
@@ -226,6 +226,7 @@
     gboolean quit;
     gboolean reload;
 
+    Window timestamp_win;
     Cursor busy_cursor;
     Cursor move_cursor;
     Cursor root_cursor;
