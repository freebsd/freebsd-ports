--- clients/olwmslave/helpwin.c.orig	Fri Oct 17 18:23:54 2003
+++ clients/olwmslave/helpwin.c	Fri Oct 17 19:01:59 2003
@@ -136,6 +136,7 @@
 Bool		ImageHelpWindow();
 void		MoreHelp();
 void		ErrorNotice();
+static int	ConstrainMousePos();
 
 /* ----------------------------------------------------------------------
  *	ShowHelpWindow
@@ -493,6 +494,7 @@
 	xv_set(hw->hwMGlassItem,
 		PANEL_LABEL_IMAGE,	hw->hwMGlassRender,
 		NULL);
+	return True;
 }
 
 /* ----------------------------------------------------------------------
