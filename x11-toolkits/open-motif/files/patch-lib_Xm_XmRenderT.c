--- lib/Xm/XmRenderT.c.orig	2017-03-27 15:24:31.000000000 -0700
+++ lib/Xm/XmRenderT.c	2023-12-04 15:42:22.406098000 -0800
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
