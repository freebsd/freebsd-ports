--- inc/My/Build/Base.pm.orig	2009-03-21 00:11:09.000000000 +0100
+++ inc/My/Build/Base.pm	2009-03-21 00:11:36.000000000 +0100
@@ -108,7 +108,7 @@
     $ver =~ m/^(\d+)\.(\d+)\.(\d+)$/ and
       $dec = $1 + $2 / 1000 + $3 / 1000000;
 
-    return $dec;
+    return sprintf( "%.6f", $dec );
 }
 
 sub _init_config {
