--- cmd/wmii/dat.h.orig	2020-10-18 11:55:59 UTC
+++ cmd/wmii/dat.h
@@ -358,7 +358,7 @@ EXTERN Divide*	divs;
 EXTERN Client	c_magic;
 EXTERN Client	c_root;
 
-EXTERN Handlers	framehandler;
+extern Handlers	framehandler;
 
 EXTERN char	buffer[8092];
 EXTERN char*	_buffer;
@@ -371,7 +371,7 @@ static char*	const _buf_end = buffer + sizeof buffer;
 
 /* IXP */
 EXTERN IxpServer srv;
-EXTERN Ixp9Srv	p9srv;
+extern Ixp9Srv	p9srv;
 
 /* X11 */
 EXTERN uint	valid_mask;
@@ -382,12 +382,12 @@ EXTERN Image*	ibuf32;
 EXTERN Cursor	cursor[CurLast];
 
 typedef void (*XHandler)(XEvent*);
-EXTERN XHandler handler[LASTEvent];
+extern XHandler handler[LASTEvent];
 
 /* Misc */
 EXTERN int	starting;
 EXTERN bool	resizing;
-EXTERN long	ignoreenter;
+extern long	ignoreenter;
 EXTERN char*	user;
 EXTERN char*	execstr;
 EXTERN int	debugflag;
