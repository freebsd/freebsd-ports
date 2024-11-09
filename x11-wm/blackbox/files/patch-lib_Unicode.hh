--- lib/Unicode.hh.orig	2005-01-03 09:42:53 UTC
+++ lib/Unicode.hh
@@ -37,7 +37,7 @@ namespace bt
   /*
    * Unicode character type.
    */
-  typedef unsigned int Uchar;
+  typedef char32_t Uchar;
 
   /*
    * Unicode string type.
