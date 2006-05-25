--- clients/olwmslave/propswin.c.orig	Sat Mar 25 22:43:32 2006
+++ clients/olwmslave/propswin.c	Sat Mar 25 22:44:16 2006
@@ -38,9 +38,9 @@
  *      Local Forward Declarations
  * ----------------------------------------------------------------------*/
 int		ShowWindowProps();
-void		InitWindowProps();
-Bool		CreateWindowProps();
-Notify_value	DestroyWindowProps();
+static void		InitWindowProps();
+static Bool		CreateWindowProps();
+static Notify_value	DestroyWindowProps();
 void		ApplyProps();
 void		ResetProps();
 
