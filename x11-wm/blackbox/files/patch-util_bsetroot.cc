--- util/bsetroot.cc.orig	2013-08-31 16:18:50.697762748 +0200
+++ util/bsetroot.cc	2013-08-31 16:19:53.695753444 +0200
@@ -28,6 +28,7 @@
 #include <Texture.hh>
 
 #include <cctype>
+#include <cstdlib>
 
 #include <X11/Xatom.h>
 #include <stdio.h>
@@ -68,11 +69,11 @@
     } else if (! strcmp("-mod", argv[i])) {
       if ((++i) >= argc) usage();
 
-      mod_x = atoi(argv[i]);
+      mod_x = std::atoi(argv[i]);
 
       if ((++i) >= argc) usage();
 
-      mod_y = atoi(argv[i]);
+      mod_y = std::atoi(argv[i]);
 
       if (mod_x < 1) mod_x = 1;
       if (mod_y < 1) mod_y = 1;
@@ -336,7 +337,7 @@
           "  -to <color>              gradient end color\n\n"
           "  -solid <color>           solid color\n\n"
           "  -help                    print this help text and exit\n");
-  exit(exit_code);
+  std::exit(exit_code);
 }
 
 int main(int argc, char **argv) {
@@ -350,7 +351,7 @@
       if ((++i) >= argc) {
         fprintf(stderr, "error: '-display' requires an argument\n");
 
-        ::exit(1);
+        std::exit(1);
       }
 
       display_name = argv[i];
