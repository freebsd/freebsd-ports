--- src/borders.c.orig	2008-12-04 18:27:27.000000000 +0100
+++ src/borders.c	2008-12-04 18:31:16.000000000 +0100
@@ -45,7 +45,7 @@
 
 static Ecore_List  *border_list = NULL;
 
-static void         BorderDestroy(Border * b);
+static void         BorderDestroy(const Border * b);
 static void         BorderWinpartHandleEvents(Win win, XEvent * ev, void *prm);
 static void         BorderFrameHandleEvents(Win win, XEvent * ev, void *prm);
 static Border      *BorderGetFallback(void);
@@ -628,7 +628,7 @@
 }
 
 static void
-BorderDestroy(Border * b)
+BorderDestroy(const Border * b)
 {
    int                 i;
 
@@ -641,7 +641,7 @@
 	return;
      }
 
-   ecore_list_node_remove(border_list, b);
+   ecore_list_node_remove(border_list, (Border *)b);
 
    for (i = 0; i < b->num_winparts; i++)
      {
