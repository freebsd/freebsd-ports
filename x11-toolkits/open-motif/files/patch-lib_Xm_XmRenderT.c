--- lib/Xm/XmRenderT.c.orig	2017-12-05 12:46:16 UTC
+++ lib/Xm/XmRenderT.c
@@ -2091,10 +2091,9 @@ ValidateAndLoadFont(XmRendition rend, Display *display
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
