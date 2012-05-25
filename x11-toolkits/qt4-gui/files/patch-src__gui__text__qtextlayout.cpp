--- ./src/gui/text/qtextlayout.cpp.orig	2012-03-14 15:01:14.000000000 +0100
+++ ./src/gui/text/qtextlayout.cpp	2012-04-03 09:40:53.779974016 +0200
@@ -2508,6 +2508,10 @@
     int pos = *cursorPos;
     int itm;
     const HB_CharAttributes *attributes = eng->attributes();
+    if (!attributes) {
+        *cursorPos = 0;
+        return x.toReal();
+    }
     while (pos < line.from + line.length && !attributes[pos].charStop)
         pos++;
     if (pos == line.from + (int)line.length) {
