*** src/tacho.c.orig	Thu Apr 24 20:48:57 1997
--- src/tacho.c	Thu Apr 24 20:56:55 1997
***************
*** 19,24 ****
--- 19,28 ----
  #include "drawobj_impl.h"
  #include <math.h>
  
+ #ifdef __FreeBSD__
+ #define irint(x)    ((int)rint((x)))
+ #endif
+ 
  Pkg_private int 	tacho_init();
  Pkg_private Xv_opaque	tacho_set_avlist();
  Pkg_private Xv_opaque	tacho_get_attr();
