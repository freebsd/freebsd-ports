--- clients/olwmslave/helpwin.c.orig	1993-06-29 07:12:11.000000000 +0200
+++ clients/olwmslave/helpwin.c	2007-08-03 15:23:23.000000000 +0200
@@ -128,14 +128,15 @@
  *	Local Forward Functions
  * ---------------------------------------------------------------------*/
 int		ShowHelpWindow();
-void		InitHelpWindow();
-Bool		CreateHelpWindow();
-Notify_value	DestroyHelpWindow();
-void		ResetHelpWindow();
-Bool		TextHelpWindow();
-Bool		ImageHelpWindow();
-void		MoreHelp();
-void		ErrorNotice();
+static void		InitHelpWindow();
+static Bool		CreateHelpWindow();
+static Notify_value	DestroyHelpWindow();
+static void		ResetHelpWindow();
+static Bool		TextHelpWindow();
+static Bool		ImageHelpWindow();
+static void		MoreHelp();
+static void		ErrorNotice();
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
