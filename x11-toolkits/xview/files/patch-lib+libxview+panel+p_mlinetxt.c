--- lib/libxview/panel/p_mlinetxt.c.orig	Sat Mar 25 23:52:08 2006
+++ lib/libxview/panel/p_mlinetxt.c	Sun Mar 26 00:22:01 2006
@@ -14,6 +14,7 @@
  * Multi-line Text Field Panel Item
  */
 #include <string.h>
+#include <stdarg.h>
 #include <xview_private/panel_impl.h>
 #include <xview_private/draw_impl.h>
 #include <xview/defaults.h>
@@ -449,7 +450,7 @@
 	return (Xv_opaque) dp->rows_displayed;
 
       case PANEL_ITEM_NTH_WINDOW:
-	switch (*(int *) valist) {
+	switch (va_arg(valist, int)) {
 	  case 0:
 	    return dp->view;
 	  case 1:
