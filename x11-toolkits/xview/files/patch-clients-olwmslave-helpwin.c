--- clients/olwmslave/helpwin.c.orig	2012-02-07 19:18:57.806432096 -0800
+++ clients/olwmslave/helpwin.c	2012-02-07 19:26:21.863976814 -0800
@@ -186,7 +186,7 @@
 /* ----------------------------------------------------------------------
  *	InitHelpWindow		- Inits helpWinList array.
  * ----------------------------------------------------------------------*/
-static	void
+void
 InitHelpWindow()
 {
 	HelpWindow	*hw;
@@ -215,7 +215,7 @@
 /* ----------------------------------------------------------------------
  *	CreateHelpWindow	- Creates the help window frame and etc.
  * ----------------------------------------------------------------------*/
-static 	Bool
+Bool
 CreateHelpWindow(hw,helpkey)
 	HelpWindow	*hw;
 	char		*helpkey;
@@ -325,7 +325,7 @@
 /* ----------------------------------------------------------------------
  *	ResetHelpWindow
  * ---------------------------------------------------------------------*/
-static	void
+void
 ResetHelpWindow(hw)
 	HelpWindow	*hw;
 {
@@ -335,7 +335,7 @@
 /* ----------------------------------------------------------------------
  *	DestroyHelpWindow	- Destroy the help window
  * ---------------------------------------------------------------------*/
-static Notify_value
+Notify_value
 DestroyHelpWindow(client,status)
 	Notify_client	client;
 	Destroy_status	status;
@@ -361,7 +361,7 @@
 /* ----------------------------------------------------------------------
  *	TextHelpWindow		- Inserts the help text.
  * ---------------------------------------------------------------------*/
-static	Bool
+Bool
 TextHelpWindow(hw,helpkey)
 	HelpWindow	*hw;
 	char		*helpkey;
@@ -460,7 +460,7 @@
 /* ----------------------------------------------------------------------
  *	ImageHelpWindow
  * ---------------------------------------------------------------------*/
-static	Bool
+Bool
 ImageHelpWindow(hw,mousex,mousey)
 	HelpWindow	*hw;
 {
@@ -500,7 +500,7 @@
 /* ----------------------------------------------------------------------
  *	ConstrainMousePos
  * ---------------------------------------------------------------------*/
-static int
+int
 ConstrainMousePos(nscreen,mousex,mousey,imagex,imagey)
 	int		nscreen;
 	int		mousex,mousey;
@@ -528,7 +528,7 @@
  *	MoreHelp
  * ---------------------------------------------------------------------*/
 /*ARGSUSED*/
-static void
+void
 MoreHelp(item,event)
 	Panel_item	item;
 	Event		*event;
@@ -547,7 +547,7 @@
 /* ----------------------------------------------------------------------
  *	ErrorNotice
  * ---------------------------------------------------------------------*/
-static	void
+void
 ErrorNotice(nscreen,errmsg,helpkey)
 	int		nscreen;
 	char		*errmsg;
