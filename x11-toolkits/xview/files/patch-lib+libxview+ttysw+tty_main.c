--- lib/libxview/ttysw/tty_main.c.orig	Tue Jun 29 00:17:22 1993
+++ lib/libxview/ttysw/tty_main.c	Fri Oct 17 09:49:09 2003
@@ -60,7 +60,7 @@
 #include <wctype.h>
 #include <stdlib.h>
 #include <xview_private/charimage.h>
-#ifdef FULL_R5
+#if defined(FULL_R5) || defined(X11R6)
 #include <X11/Xlib.h>
 #endif /* FULL_R5 */    
 #endif
@@ -75,6 +75,11 @@
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
@@ -906,8 +911,12 @@
 
 	    if (int_ucntl == (tiocsti & 0xff))
 		ttysw_process_STI(ttysw, owbp, cc - 1);
+#ifndef XV_USE_TERMIOS
 	    (void) ioctl(ttysw->ttysw_tty, TIOCGETC, &ttysw->tchars);
 	    (void) ioctl(ttysw->ttysw_tty, TIOCGLTC, &ttysw->ltchars);
+#else
+	    (void) tcgetattr(ttysw->ttysw_tty, &ttysw->termios);
+#endif
 	    ttysw_getp(TTY_VIEW_HANDLE_FROM_TTY_FOLIO(ttysw));	/* jcb for nng */
 	} else
 #ifdef OW_I18N
