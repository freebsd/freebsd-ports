--- src/menuinfo.cc.orig	2003-02-15 21:05:41 UTC
+++ src/menuinfo.cc
@@ -21,7 +21,7 @@ void MenuInfo::Init() {
   MenuItemList *actions=0,*last=0;
   for (Entry *e=s->fe;e;e=e->next)
     if (e->tag) {
-      lower(e->value);
+      // lower(e->value); // why? (RP)
       if (last) {
         last->next = new MenuItemList;
         last = last->next;
