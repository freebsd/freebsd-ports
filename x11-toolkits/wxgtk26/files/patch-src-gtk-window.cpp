--- src/gtk/window.cpp.orig	2006-03-22 00:42:17.000000000 +0100
+++ src/gtk/window.cpp	2007-11-22 14:01:22.000000000 +0100
@@ -3279,7 +3279,7 @@
                 right_border += default_border->right;
                 top_border += default_border->top;
                 bottom_border += default_border->bottom;
-                g_free( default_border );
+                gtk_border_free( default_border );
             }
 #else
             left_border = 6;
