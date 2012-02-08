--- lib/libxview/ttysw/tty_gtty.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/tty_gtty.c	2012-02-04 10:05:24.248305867 -0800
@@ -14,6 +14,7 @@
  * Ttysw parameter retrieval mechanism to get original tty settings to pty.
  */
 
+#include <sys/param.h>
 #include <sys/types.h>
 #include <stdio.h>
 #include <xview_private/portable.h>	/* for tty_mode_t and XV* defines */
@@ -93,7 +94,20 @@
 	CREPRINT, CDISCARD, CWERASE, CLNEXT,
 	CEOL2
 };
-	
+
+#elif defined(BSD) && (BSD >= 199103)
+#include <sys/ttydefaults.h>
+static struct termios default_modes = {
+	TTYDEF_IFLAG,   /* input modes */
+	TTYDEF_OFLAG,   /* output modes */      
+	TTYDEF_CFLAG,   /* control modes */
+	TTYDEF_LFLAG,   /* local modes */
+	/* control characters */
+	{ CEOF,   CEOL,   CEOL,   CERASE, CWERASE, CKILL, CREPRINT,
+	_POSIX_VDISABLE, CINTR, CQUIT,  CSUSP,  CDSUSP, CSTART, CSTOP,  CLNEXT,
+	CDISCARD, CMIN, CTIME,  CSTATUS, _POSIX_VDISABLE },
+	TTYDEF_SPEED, TTYDEF_SPEED /* input and output speeds */
+};
 #else /* __linux__ */
 static struct termios	default_modes = {
 	BRKINT|ICRNL|IXON|IGNPAR|IMAXBEL,	    	/* input modes */
