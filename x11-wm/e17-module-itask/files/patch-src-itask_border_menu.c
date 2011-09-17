--- src/itask_border_menu.c.orig	2011-09-16 17:25:26.367307838 +0200
+++ src/itask_border_menu.c	2011-09-16 17:25:59.976867758 +0200
@@ -25,7 +25,7 @@
    E_Menu_Item *mi;
    E_Menu *m, *m_maximize, *m_stacking;
    if (bd->border_menu)
-      return;
+      return NULL;
 
    /* Only allow to change layer for windows in "normal" layers */
    if ((!bd->lock_user_stacking) &&
