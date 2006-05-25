--- clients/olwmslave/propsrecv.c.orig	Sat Mar 25 22:42:20 2006
+++ clients/olwmslave/propsrecv.c	Sat Mar 25 22:43:01 2006
@@ -15,7 +15,7 @@
 #include "propscmd.h"
 
 extern	int	ShowWindowProps();
-	void	ReceivePropsCmd();
+static	void	ReceivePropsCmd();
 
 /* ----------------------------------------------------------------------
  *	RegisterPropsWindow
