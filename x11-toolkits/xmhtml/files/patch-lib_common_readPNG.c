--- lib/common/readPNG.c.orig	1998-11-16 23:56:19.000000000 +0100
+++ lib/common/readPNG.c	2012-05-26 14:16:45.000000000 +0200
@@ -82,6 +82,7 @@
 
 #ifdef HAVE_LIBPNG
 #include <png.h>
+#include <pngpriv.h>
 #include <setjmp.h>
 #include <math.h>		/* required for full alpha channel processing */
 #endif
@@ -132,7 +133,7 @@
 
 	_XmHTMLWarning(__WFUNC__(NULL, "png_error"), XMHTML_MSG_121, "png",
 		ib->file, msg);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 /*****
@@ -232,7 +233,7 @@
 		return((XmHTMLRawImageData*)NULL);
 	}
 	/* now set error handler */
-	if(setjmp(png_ptr->jmpbuf))
+	if(setjmp(png_jmpbuf(png_ptr)))
 	{
 		/* 
 		* PNG signalled an error. Destroy image data, free any allocated
