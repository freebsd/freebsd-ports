--- src/lib/ecore_dbus/ecore_dbus.c.orig	Sun Jun 26 08:21:23 2005
+++ src/lib/ecore_dbus/ecore_dbus.c	Sun Jun 26 08:21:33 2005
@@ -592,9 +592,9 @@
 			  unsigned int pos)
 {
    Ecore_Oldlist      *l, *list;
+   unsigned int        i = 0;
 
    list = (Ecore_Oldlist *) mf;
-   unsigned int        i = 0;
 
    for (l = list; l; l = l->next)
      {
