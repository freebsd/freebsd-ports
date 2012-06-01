--- gtk-xmhtml/readPNG.c.orig	2002-08-06 23:25:46.000000000 +0200
+++ gtk-xmhtml/readPNG.c	2012-05-11 18:06:35.000000000 +0200
@@ -158,6 +158,7 @@
 
 #ifdef HAVE_LIBPNG
 #include <png.h>
+#include <pngpriv.h>
 #include <setjmp.h>
 #include <math.h>		/* required for full alpha channel processing */
 #endif
@@ -208,7 +209,7 @@
 
 	_XmHTMLWarning(__WFUNC__(NULL, "png_error"),
 		"libpng error on image %s: %s", ib->file, msg);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 /*****
@@ -308,7 +309,7 @@
 		return((XmHTMLRawImageData*)NULL);
 	}
 	/* now set error handler */
-	if(setjmp(png_ptr->jmpbuf))
+	if(setjmp(png_jmpbuf(png_ptr)))
 	{
 		/* 
 		* PNG signalled an error. Destroy image data, free any allocated
