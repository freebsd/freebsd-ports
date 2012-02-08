--- lib/libxview/ttysw/tty_main.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/tty_main.c	2012-02-03 12:15:40.077487003 -0800
@@ -60,12 +60,14 @@
 #include <wctype.h>
 #include <stdlib.h>
 #include <xview_private/charimage.h>
-#ifdef FULL_R5
+#if defined(FULL_R5) || defined(X11R6)
 #include <X11/Xlib.h>
 #endif /* FULL_R5 */    
 #endif
 
-#if (defined(__linux__) && defined(__GLIBC__)) || defined(__CYGWIN__)
+#include <sys/param.h>
+
+#if (defined(__linux__) && defined(__GLIBC__)) || defined(__CYGWIN__) || (defined(__FreeBSD__) && defined(__FreeBSD_version) && __FreeBSD_version > 900007)
 /* martin.buck@bigfoot.com */
 #include <sys/ioctl.h>
 #endif
@@ -80,6 +82,11 @@
 int     committed_left = 0;
 #endif
 
+static int ttysw_process_point();
+static int ttysw_process_adjust();
+static int ttysw_process_motion();
+static int ttysw_process_keyboard();
+
 extern Textsw_index textsw_insert();
 #ifdef OW_I18N
 extern Textsw_index textsw_insert_wcs();
