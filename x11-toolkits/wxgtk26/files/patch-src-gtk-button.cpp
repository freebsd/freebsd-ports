--- src/gtk/button.cpp.orig	2006-03-22 00:42:16.000000000 +0100
+++ src/gtk/button.cpp	2007-11-22 14:00:47.000000000 +0100
@@ -89,7 +89,7 @@
             right_border += default_border->right;
             top_border += default_border->top;
             bottom_border += default_border->bottom;
-            g_free( default_border );
+            gtk_border_free( default_border );
         }
 #else
         left_border = 6;
