--- ./lib/libxview/ttysw/cim_change.c.orig	Tue Jun 29 07:17:12 1993
+++ ./lib/libxview/ttysw/cim_change.c	Sat Apr  1 18:25:29 2000
@@ -17,10 +17,10 @@ static char     sccsid[] = "@(#)cim_chan
 #include <xview_private/i18n_impl.h>
 #include <sys/types.h>
 #include <pixrect/pixrect.h>
-#include <xview_private/ttyansi.h>
 #include <xview_private/charimage.h>
 #include <xview_private/charscreen.h>
 #include <xview_private/tty_impl.h>
+#include <xview_private/ttyansi.h>
 
 char            boldify;
 
