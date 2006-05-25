--- clients/olwmslave/helprecv.c.orig	Sat Mar 25 22:29:53 2006
+++ clients/olwmslave/helprecv.c	Sat Mar 25 22:30:46 2006
@@ -15,7 +15,7 @@
 #include "helpcmd.h"
 
 extern	int	ShowHelpWindow();
-	void	ReceiveHelpCmd();
+static	void	ReceiveHelpCmd();
 
 /* ----------------------------------------------------------------------
  *	RegisterHelpWindow
