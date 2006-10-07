--- lib/libxview/misc/quark.c.orig	Thu Oct  5 18:57:21 2006
+++ lib/libxview/misc/quark.c	Thu Oct  5 18:57:45 2006
@@ -16,7 +16,7 @@
 #include  <xview/xview.h>
 #include  <xview/pkg.h>
 
-Xv_opaque resource_type_conv();
+static Xv_opaque resource_type_conv();
 
 /* 
  *    Utilities to deal with quark lists and such.
