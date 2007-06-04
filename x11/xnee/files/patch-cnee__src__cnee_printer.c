--- cnee/src/cnee_printer.c.orig	Thu Nov  9 06:20:31 2006
+++ cnee/src/cnee_printer.c	Mon May 28 13:25:56 2007
@@ -388,6 +388,13 @@
 
 
 
+  fprintf (fd ,"@dircategory Miscellaneous\n");
+  fprintf (fd ,"@direntry\n");
+  fprintf (fd ,"* Cnee: (cnee).         Record, replays or distributes X11 data.\n");
+  fprintf (fd ,"@end direntry\n");
+
+
+
   fprintf (fd, "@ifinfo\n");
   fprintf (fd, "@node Top, Options,, (dir)\n");
   fprintf (fd, "@top \n");
