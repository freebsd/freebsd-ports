--- lib/libxview/ttysw/tty_impl.h.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/tty_impl.h	2012-02-03 11:51:09.464890989 -0800
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
+#define tty_gettabs(t)                ((t)->termios.c_oflag & OXTABS)
+#else
 #define	tty_gettabs(t)		((t)->termios.c_oflag & XTABS)
+#endif
 #if !(defined(__linux__)||defined(__CYGWIN__)) || defined(VDSUSP)
 #define	tty_getdsuspc(t)	((int) ((t)->termios.c_cc[VDSUSP]))
 #else
