$FreeBSD$

FreeBSD 4 is not C99-compliant.

--- src/timux.c.orig	Wed Aug  6 14:27:19 2003
+++ src/timux.c	Sat Oct 18 17:14:40 2003
@@ -45,7 +45,7 @@ struct TiMux {
     TiMuxEvent target;
 };
 
-static volatile uintmax_t timux_count=0;
+static volatile uint32_t timux_count=0;
 static TiMux theTiMux=NULL;
 
 static void TheHandlerTM   (int);
