--- ./lib/libxview/ttysw/tty_gtty.c.orig	Tue Jun 29 07:17:20 1993
+++ ./lib/libxview/ttysw/tty_gtty.c	Sat Apr  1 18:25:29 2000
@@ -14,6 +14,7 @@ static  char sccsid[] = "@(#)tty_gtty.c 
  * Ttysw parameter retrieval mechanism to get original tty settings to pty.
  */
 
+#include <sys/param.h>
 #include <sys/types.h>
 #include <stdio.h>
 #include <xview_private/portable.h>	/* for tty_mode_t and XV* defines */
@@ -34,6 +35,7 @@ static  char sccsid[] = "@(#)tty_gtty.c 
  */
 #ifdef	XV_USE_TERMIOS
 
+#if !(defined(BSD) && (BSD >= 199103))
 static struct termios	default_modes = {
 	BRKINT|ICRNL|IXON|IGNPAR|IMAXBEL,	    	/* input modes */
 	OPOST|ONLCR,				    	/* output modes */
@@ -57,6 +59,20 @@ static struct termios	default_modes = {
 	CWERASE,	/* VWERASE */
 	CLNEXT,		/* VLNEXT */
 };
+#else
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
+#endif
 
 #else	/* XV_USE_TERMIOS */
 
