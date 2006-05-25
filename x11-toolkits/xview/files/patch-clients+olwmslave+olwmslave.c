--- clients/olwmslave/olwmslave.c.orig	Sat Mar 25 22:35:19 2006
+++ clients/olwmslave/olwmslave.c	Sat Mar 25 22:36:52 2006
@@ -44,9 +44,9 @@
 /* ----------------------------------------------------------------------
  *	Forward Definitions
  * ----------------------------------------------------------------------*/
-void		InitScreenInfo();
-void		ParseScreenArgs();
-Notify_value	InputReader();
+static void		InitScreenInfo();
+static void		ParseScreenArgs();
+static Notify_value	InputReader();
 
 /* ----------------------------------------------------------------------
  * 	main
