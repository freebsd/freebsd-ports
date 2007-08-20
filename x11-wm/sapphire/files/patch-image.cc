--- image.cc.orig	2001-11-03 12:14:22.000000000 -0500
+++ image.cc	2007-08-13 11:25:46.000000000 -0400
@@ -22,7 +22,9 @@
 
 #include "sapphire.hh"
 
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 
 #ifdef GradientHack
 #  include <math.h>
@@ -158,12 +160,12 @@
     }
 
   if (control->dither()) {
-    short er, eg, eb, *or, *og, *ob, *nor, *nog, *nob, *por, *pog, *pob;
+    short er, eg, eb, *or_, *og, *ob, *nor, *nog, *nob, *por, *pog, *pob;
     unsigned short *ort, *ogt, *obt;
     
-    control->getDitherBuffers(width + 2, &or, &og, &ob, &nor, &nog, &nob,
+    control->getDitherBuffers(width + 2, &or_, &og, &ob, &nor, &nog, &nob,
 			      &ort, &ogt, &obt);
-    if ((! or) || (! og) || (! ob) || (! nor) || (! nog) || (! nob) ||
+    if ((! or_) || (! og) || (! ob) || (! nor) || (! nog) || (! nob) ||
 	(! ort) || (! ogt) || (! obt)) {
       fprintf(stderr,
 	      "BImage::renderXImage: error getting dither information\n");
@@ -173,7 +175,7 @@
     
     x = width;
 
-    por = or;
+    por = or_;
     pog = og;
     pob = ob;
 
@@ -204,14 +206,14 @@
       }
       
       for (x = 0; x < width; x++) {
-	if (*(or + x) > 255) *(or + x) = 255;
-	else if (*(or + x) < 0) *(or + x) = 0;
+	if (*(or_ + x) > 255) *(or_ + x) = 255;
+	else if (*(or_ + x) < 0) *(or_ + x) = 0;
 	if (*(og + x) > 255) *(og + x) = 255;
 	else if (*(og + x) < 0) *(og + x) = 0;
 	if (*(ob + x) > 255) *(ob + x) = 255;
 	else if (*(ob + x) < 0) *(ob + x) = 0;
 	
-	r = *(tr + *(or + x));
+	r = *(tr + *(or_ + x));
 	g = *(tg + *(og + x));
 	b = *(tb + *(ob + x));
 	
@@ -273,11 +275,11 @@
 	  return 0;
 	}
 
-	er = *(or + x) - *(ort + *(or + x));
+	er = *(or_ + x) - *(ort + *(or_ + x));
 	eg = *(og + x) - *(ogt + *(og + x));
 	eb = *(ob + x) - *(obt + *(ob + x));
 	
-	*(or + x + 1) += er;
+	*(or_ + x + 1) += er;
 	*(og + x + 1) += eg;
 	*(ob + x + 1) += eb;
 	
@@ -293,7 +295,7 @@
       off += image->width;
       idata = (pd += image->bytes_per_line);
       
-      por = or; or = nor; nor = por;
+      por = or_; or_ = nor; nor = por;
       pog = og; og = nog; nog = pog;
       pob = ob; ob = nob; nob = pob;
     }
