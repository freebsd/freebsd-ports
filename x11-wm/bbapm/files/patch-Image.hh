--- Image.hh.orig	Sun Aug 15 07:43:55 1999
+++ Image.hh	Sat Aug  4 20:52:40 2001
@@ -35,11 +35,21 @@
 class BImage;
 class BImageControl;
 
+#if 0
 typedef struct BColor {
   int allocated;
   unsigned char red, green, blue;
   unsigned long pixel;
 };
+#else
+class BColor {
+public:
+  int allocated;
+  unsigned char red, green, blue;
+  unsigned long pixel;
+  BColor::BColor() { allocated = False; }
+};
+#endif
 
 typedef struct BTexture {
   BColor color, colorTo, hiColor, loColor;
