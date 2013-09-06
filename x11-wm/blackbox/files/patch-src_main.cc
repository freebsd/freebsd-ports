--- src/main.cc.orig	2013-08-31 16:15:04.709773262 +0200
+++ src/main.cc	2013-08-31 16:15:45.604774045 +0200
@@ -24,6 +24,8 @@
 
 // #define PRINT_SIZES
 
+#include <cstdlib>
+
 #if defined(PRINT_SIZES)
 #  include "Screen.hh"
 #  include "Slit.hh"
@@ -69,7 +71,7 @@
 #endif // SHAPE
          );
 
-  ::exit(exitval);
+  std::exit(exitval);
 }
 
 int main(int argc, char **argv) {
@@ -87,13 +89,13 @@
              "Copyright (c) 1997 - 2000, 2002 - 2005 Bradley T Hughes\n",
              __blackbox_version);
 
-      ::exit(0);
+      std::exit(0);
     } else if (! strcmp(argv[i], "-rc")) {
       // look for alternative rc file to use
 
       if ((++i) >= argc) {
         fprintf(stderr, "error: '-rc' requires and argument\n");
-        ::exit(1);
+        std::exit(1);
       }
 
       rc_file = argv[i];
@@ -103,7 +105,7 @@
 
       if ((++i) >= argc) {
         fprintf(stderr, "error: '-display' requires an argument\n");
-        ::exit(1);
+	std::exit(1);
       }
 
       dpy_name = argv[i];
