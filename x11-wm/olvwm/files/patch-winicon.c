--- winicon.c.orig	Thu Jan 13 15:36:26 1994
+++ winicon.c	Mon Oct 19 14:15:05 1998
@@ -37,6 +37,10 @@
 extern 	Bool	PropGetWMName();
 extern 	Bool	PropGetWMIconName();
 
+static	heightTopIcon();
+static	heightBottomIcon();
+static	widthBothIcon();
+
 /***************************************************************************
 * private data
 ***************************************************************************/
