--- main.C.orig	Sun Jan  5 16:07:31 2003
+++ main.C	Sun Jan  5 16:07:41 2003
@@ -351,7 +351,7 @@
 }
 
 int main(int argc, char** argv) {
-  program_name = filename_name(argv[0]);
+  program_name = fl_filename_name(argv[0]);
   int i; if (Fl::args(argc, argv, i, arg) < argc) Fl::error(
 "options are:\n"
 " -d[isplay] host:#.#\tX display & screen to use\n"
