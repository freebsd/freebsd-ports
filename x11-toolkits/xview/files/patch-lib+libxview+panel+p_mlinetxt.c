--- lib/libxview/panel/p_mlinetxt.c.orig	Tue Jun 29 14:17:05 1993
+++ lib/libxview/panel/p_mlinetxt.c	Sun Jan 10 01:52:00 1999
@@ -449,7 +449,7 @@
 	return (Xv_opaque) dp->rows_displayed;
 
       case PANEL_ITEM_NTH_WINDOW:
-	switch (*(int *) valist) {
+	switch (va_arg(valist, int)) {
 	  case 0:
 	    return dp->view;
 	  case 1:
