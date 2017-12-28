--- hsetroot.c.orig	2016-02-14 00:09:11 UTC
+++ hsetroot.c
@@ -8,7 +8,7 @@
 #include "outputs.h"
 
 
-typedef enum { Full, Fill, Center, Tile, Xtend, Cover } ImageMode;
+typedef enum { Full, Fill, Center, Tile, Xtend, Cover, Sane } ImageMode;
 
 void
 usage(char *commandline)
@@ -33,6 +33,7 @@ usage(char *commandline)
     "Image files:\n"
     " -center <image>            Render an image centered on screen\n"
     " -cover <image>             Render an image centered on screen scaled to fill the screen fully\n"
+    " -sane <image>              Render an image in sane mode (choose the best aspect, but do not center)\n"
     " -tile <image>              Render an image tiled\n"
     " -full <image>              Render an image maximum aspect\n"
     " -extend <image>            Render an image max aspect and fill borders\n"
@@ -165,7 +166,7 @@ parse_color(char *arg, PColor c, int a)
 int
 load_image(ImageMode mode, const char *arg, int alpha, Imlib_Image rootimg, OutputInfo *outputs, int noutputs)
 {
-  int imgW, imgH, o;
+  int i, imgW, imgH, o;
   Imlib_Image buffer = imlib_load_image(arg);
 
   if (!buffer)
@@ -193,7 +194,7 @@ load_image(ImageMode mode, const char *arg, int alpha,
 
   imlib_context_set_image(rootimg);
 
-  for (int i = 0; i < noutputs; i++) {
+  for (i = 0; i < noutputs; i++) {
     OutputInfo o = outputs[i];
     printf("output %d: size(%d, %d) pos(%d, %d)\n", i, o.w, o.h, o.x, o.y);
 
@@ -229,6 +230,20 @@ load_image(ImageMode mode, const char *arg, int alpha,
           }
         }
       }
+    } else if (mode == Sane) {
+      int newW, newH;
+      double aspect_w = ((double) o.w) / imgW;
+      double aspect_h = ((double) o.h) / imgH;
+      if (aspect_h < aspect_w) {
+        // image is taller
+        newW = o.w;
+        newH = (int) (imgH * aspect_w);
+      } else {
+        // image is wider
+        newW = (int) (imgW * aspect_h);
+        newH = o.h;
+      }
+      imlib_blend_image_onto_image(buffer, 0, 0, 0, imgW, imgH, 0, 0, newW, newH);
     } else {  // Center || Tile
       int left = (o.w - imgW) / 2;
       int top = (o.h - imgH) / 2;
@@ -457,6 +472,15 @@ main(int argc, char **argv)
         }
         if (load_image(Cover, argv[i], alpha, image, outputs, noutputs) == 0) {
           fprintf (stderr, "Bad image (%s)\n", argv[i]);
+          continue;
+        }
+      } else if (strcmp (argv[i], "-sane") == 0) {
+        if ((++i) >= argc) {
+          fprintf(stderr, "Missing image\n");
+          continue;
+        }
+        if (load_image(Sane, argv[i], alpha, image, outputs, noutputs) == 0) {
+          fprintf(stderr, "Bad image (%s)\n", argv[i]);
           continue;
         }
       } else if (strcmp(argv[i], "-tint") == 0) {
