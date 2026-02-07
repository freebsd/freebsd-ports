--- src/main.cc.orig	2005-01-03 09:42:57 UTC
+++ src/main.cc
@@ -24,6 +24,8 @@
 
 // #define PRINT_SIZES
 
+#include <cstdlib>
+
 #if defined(PRINT_SIZES)
 #  include "Screen.hh"
 #  include "Slit.hh"
@@ -69,7 +71,7 @@ static void showHelp(int exitval) {
 #endif // SHAPE
          );
 
-  ::exit(exitval);
+  std::exit(exitval);
 }
 
 int main(int argc, char **argv) {
@@ -87,13 +89,13 @@ int main(int argc, char **argv) {
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
@@ -103,7 +105,7 @@ int main(int argc, char **argv) {
 
       if ((++i) >= argc) {
         fprintf(stderr, "error: '-display' requires an argument\n");
-        ::exit(1);
+	std::exit(1);
       }
 
       dpy_name = argv[i];
