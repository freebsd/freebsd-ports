--- lib/libxview/ttysw/tty_impl.h.orig	Tue Jun 29 00:17:18 1993
+++ lib/libxview/ttysw/tty_impl.h	Sun Oct 12 20:29:16 2003
@@ -14,6 +14,7 @@
  * terminal emulation for teletype based programs.
  */
 
+#include <sys/param.h>
 #include <xview_private/portable.h>	/* tty and pty configuration info */
 
 #ifdef	XV_USE_TERMIOS
@@ -210,7 +211,13 @@
  * Access functions for tty characteristics.
  */
 #ifdef	XV_USE_TERMIOS
+#if (defined(BSD) && (BSD >= 199103))
+#include <sys/ioctl.h>
+#include <sys/ioctl_compat.h>
+#define tty_gettabs(t)		((t)->termios.c_oflag & OXTABS)
+#else   
 #define	tty_gettabs(t)		((t)->termios.c_oflag & XTABS)
+#endif
 #define	tty_getdsuspc(t)	((int) ((t)->termios.c_cc[VDSUSP]))
 #define	tty_geteofc(t)		((int) ((t)->termios.c_cc[VEOF]))
 #define	tty_geteolc(t)		((int) ((t)->termios.c_cc[VEOL]))
