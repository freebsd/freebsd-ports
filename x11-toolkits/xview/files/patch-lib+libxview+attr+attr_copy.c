--- ./lib/libxview/attr/attr_copy.c.orig	Tue Jun 29 07:14:35 1993
+++ ./lib/libxview/attr/attr_copy.c	Sat Apr  1 18:25:23 2000
@@ -12,6 +12,11 @@ static char     sccsid[] = "@(#)attr_cop
 
 #include <xview/attr.h>
 
+static int copy_1_attr();
+static int copy_counted_list();
+static int copy_singleton();
+static int copy_null_list();
+
 /*
  * attr_copy:	copy an attribute list, returning the size in bytes
  */
