--- lib/Xm/XmRenderT.c.orig	2023-02-15 16:42:34.000000000 -0800
+++ lib/Xm/XmRenderT.c	2023-12-04 15:42:20.894104000 -0800
@@ -2091,10 +2091,9 @@
 						  static int count_rend=0, num_rend;
 						  num_rend = GetSameRenditions(rend_cache, rend, count_rend);
 
-						  if (num_rend>=0)
+						  if(num_rend >= 0 && (display == _XmRendDisplay(rend_cache[num_rend]))) {
 							  _XmRendXftFont(rend) = _XmRendXftFont(rend_cache[num_rend]);
-						  else
-						  {
+						  } else {
 #endif
 		    _XmRendPattern(rend) = FcPatternCreate();
 		    if (_XmRendFontName(rend))
