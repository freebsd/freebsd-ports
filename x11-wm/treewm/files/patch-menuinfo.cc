diff -ru treewm-0.4.5.orig/src/menuinfo.cc treewm-0.4.5/src/menuinfo.cc
--- src/menuinfo.cc	Mon Mar  8 00:20:42 2004
+++ src/menuinfo.cc	Mon Mar  8 00:22:37 2004
@@ -21,7 +21,7 @@
   MenuItemList *actions=0,*last=0;
   for (Entry *e=s->fe;e;e=e->next)
     if (e->tag) {
-      lower(e->value);
+      // lower(e->value); // why? (RP)
       if (last) {
         last->next = new MenuItemList;
         last = last->next;
