--- Makefile.PL.orig	2008-07-04 16:41:37 UTC
+++ Makefile.PL
@@ -5,7 +5,9 @@ use Devel::CheckLib;
 
 check_lib_or_exit(
     # fill in what you prompted the user for here
-    lib => [qw(X11 Xext Xss)]
+    lib => [qw(X11 Xext Xss)],
+    INC => '-I/usr/local/include',
+    LIBS => '-L/usr/local/lib'
 );
 
 
