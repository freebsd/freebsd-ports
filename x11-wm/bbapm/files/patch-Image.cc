--- Image.cc.orig	Sun Aug 15 07:43:55 1999
+++ Image.cc	Mon May 19 12:56:41 2003
@@ -50,6 +50,17 @@
 BImage::BImage(BImageControl *c, unsigned int w, unsigned int h) {
   control = c;
 
+  colors = NULL;
+  red    = NULL;
+  green  = NULL;
+  blue   = NULL;
+  tr     = NULL;
+  tg     = NULL;
+  tb     = NULL;
+
+  from.allocated = 0;
+  to.allocated   = 0;
+
   width = ((signed) w > 0) ? w : 1;
   height = ((signed) h > 0) ? h : 1;
 
@@ -225,12 +236,12 @@
     }
 
   if (control->doDither()) {
-    short er, eg, eb, *or, *og, *ob, *nor, *nog, *nob, *por, *pog, *pob;
+    short er, eg, eb, *bbor, *og, *ob, *nor, *nog, *nob, *por, *pog, *pob;
     unsigned short *ort, *ogt, *obt;
     
-    control->getDitherBuffers(width + 2, &or, &og, &ob, &nor, &nog, &nob,
+    control->getDitherBuffers(width + 2, &bbor, &og, &ob, &nor, &nog, &nob,
 			      &ort, &ogt, &obt);
-    if ((! or) || (! og) || (! ob) || (! nor) || (! nog) || (! nob) ||
+    if ((! bbor) || (! og) || (! ob) || (! nor) || (! nog) || (! nob) ||
 	(! ort) || (! ogt) || (! obt)) {
       fprintf(stderr,
 	      "BImage::renderXImage: error getting dither information\n");
@@ -240,7 +251,7 @@
     
     x = width;
 
-    por = or;
+    por = bbor;
     pog = og;
     pob = ob;
 
@@ -271,14 +282,14 @@
       }
       
       for (x = 0; x < width; x++) {
-	if (*(or + x) > 255) *(or + x) = 255;
-	else if (*(or + x) < 0) *(or + x) = 0;
+	if (*(bbor + x) > 255) *(bbor + x) = 255;
+	else if (*(bbor + x) < 0) *(bbor + x) = 0;
 	if (*(og + x) > 255) *(og + x) = 255;
 	else if (*(og + x) < 0) *(og + x) = 0;
 	if (*(ob + x) > 255) *(ob + x) = 255;
 	else if (*(ob + x) < 0) *(ob + x) = 0;
 	
-	r = *(tr + *(or + x));
+	r = *(tr + *(bbor + x));
 	g = *(tg + *(og + x));
 	b = *(tb + *(ob + x));
 	
@@ -340,11 +351,11 @@
 	  return 0;
 	}
 
-	er = *(or + x) - *(ort + *(or + x));
+	er = *(bbor + x) - *(ort + *(bbor + x));
 	eg = *(og + x) - *(ogt + *(og + x));
 	eb = *(ob + x) - *(obt + *(ob + x));
 	
-	*(or + x + 1) += er;
+	*(bbor + x + 1) += er;
 	*(og + x + 1) += eg;
 	*(ob + x + 1) += eb;
 	
@@ -360,7 +371,7 @@
       off += image->width;
       idata = (pd += image->bytes_per_line);
       
-      por = or; or = nor; nor = por;
+      por = bbor; bbor = nor; nor = por;
       pog = og; og = nog; nog = pog;
       pob = ob; ob = nob; nob = pob;
     }
@@ -843,7 +854,14 @@
   window = blackbox->getRootWindow();
   screen_number = blackbox->getScreenNumber();
 
-  colors = 0;
+  colors = NULL;
+  red_err = NULL;
+  green_err = NULL;
+  blue_err = NULL;
+  next_red_err = NULL;
+  next_green_err = NULL;
+  next_blue_err = NULL;
+  cache = NULL;
   colors_per_channel = ncolors = 0;
   
   int count;
