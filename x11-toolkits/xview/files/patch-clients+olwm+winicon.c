--- ./clients/olwm/winicon.c.orig	Tue Jun 29 07:12:04 1993
+++ ./clients/olwm/winicon.c	Sat Apr  1 18:26:06 2000
@@ -32,6 +32,10 @@
 extern 	Bool	PropGetWMName();
 extern 	Bool	PropGetWMIconName();
 
+static int heightTopIcon();
+static int heightBottomIcon();
+static int widthBothIcon();
+
 /***************************************************************************
 * private data
 ***************************************************************************/
