
$FreeBSD$

--- Makefile.PL	2002/04/25 08:17:07	1.1
+++ Makefile.PL	2002/04/25 08:17:56
@@ -70,6 +70,8 @@
     $DISTNAME
     $WANTNOCODECS
     $DEBUG
+    $INSTALLPRIVLIB
+    $INSTALLARCHLIB
 );
 
 use vars @path_expand_ovvars = qw(
