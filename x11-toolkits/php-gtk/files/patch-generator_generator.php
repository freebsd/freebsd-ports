--- generator/generator.php.orig	Thu Apr 11 04:19:49 2002
+++ generator/generator.php	Thu Jul 10 23:08:48 2003
@@ -27,6 +27,11 @@
  *
  */
 
+$memlim= ini_get ('memory_limit');
+if (!empty ($memlim) && 32 < (int)$memlim) {
+  ini_set ('memory_limit', '64M');
+}
+
 set_time_limit(300);
 
 require "Getopt.php";
