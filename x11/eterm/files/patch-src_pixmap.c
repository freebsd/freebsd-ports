
$FreeBSD$

--- src/pixmap.c.orig
+++ src/pixmap.c
@@ -1634,7 +1634,7 @@
             for (x = -(w * 4); x < 0; x += 4) {
                 int r, g, b;
 
-# ifdef WORDS_BIGENDIAN
+# if WORDS_BIGENDIAN
                 r = (ptr[x + 1] * rm) >> 8;
                 g = (ptr[x + 2] * gm) >> 8;
                 b = (ptr[x + 3] * bm) >> 8;
@@ -1657,7 +1657,7 @@
             for (x = -(w * 4); x < 0; x += 4) {
                 int r, g, b;
 
-# ifdef WORDS_BIGENDIAN
+# if WORDS_BIGENDIAN
                 r = (ptr[x + 1] * rm) >> 8;
                 g = (ptr[x + 2] * gm) >> 8;
                 b = (ptr[x + 3] * bm) >> 8;
@@ -1669,7 +1669,7 @@
                 r |= (!(r >> 8) - 1);
                 g |= (!(g >> 8) - 1);
                 b |= (!(b >> 8) - 1);
-# ifdef WORDS_BIGENDIAN
+# if WORDS_BIGENDIAN
                 ptr[x + 1] = r;
                 ptr[x + 2] = g;
                 ptr[x + 3] = b;
@@ -1699,7 +1699,7 @@
             for (x = -(w * 3); x < 0; x += 3) {
                 int r, g, b;
 
-# ifdef WORDS_BIGENDIAN
+# if WORDS_BIGENDIAN
                 r = (ptr[x + 0] * rm) >> 8;
                 g = (ptr[x + 1] * gm) >> 8;
                 b = (ptr[x + 2] * bm) >> 8;
@@ -1722,7 +1722,7 @@
             for (x = -(w * 3); x < 0; x += 3) {
                 int r, g, b;
 
-# ifdef WORDS_BIGENDIAN
+# if WORDS_BIGENDIAN
                 r = (ptr[x + 0] * rm) >> 8;
                 g = (ptr[x + 1] * gm) >> 8;
                 b = (ptr[x + 2] * bm) >> 8;
@@ -1734,7 +1734,7 @@
                 r |= (!(r >> 8) - 1);
                 g |= (!(g >> 8) - 1);
                 b |= (!(b >> 8) - 1);
-# ifdef WORDS_BIGENDIAN
+# if WORDS_BIGENDIAN
                 ptr[x + 0] = r;
                 ptr[x + 1] = g;
                 ptr[x + 2] = b;
