--- ./lib/Alien/wxWidgets/Utility.pm.orig	2014-03-08 15:04:14.000000000 +0100
+++ ./lib/Alien/wxWidgets/Utility.pm	2014-04-08 12:40:05.980551105 +0200
@@ -81,6 +81,7 @@
     my( $cc ) = @_;
 
     return    scalar( awx_capture( "$cc --version" ) =~ m/g(cc|\+\+)/i ) # 3.x
+           || scalar( awx_capture( "$cc --version" ) =~ m/clang/i) # clang
            || scalar( awx_capture( "$cc" ) =~ m/gcc/i );          # 2.95
 }
 
@@ -115,6 +116,7 @@
 
     if( $is_gcc ) {
         my $ver = awx_capture( "$cc --version" );
+        return 3.4 if ($ver =~ m/clang/i);
         $ver =~ m/(\d+\.\d+)(?:\.\d+)?/ or return 0;
         return $1;
     } elsif( $is_msvc ) {
