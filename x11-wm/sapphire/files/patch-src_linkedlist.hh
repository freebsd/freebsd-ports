$FreeBSD$

--- src/linkedlist.hh.orig	Mon Nov  6 03:53:25 2000
+++ src/linkedlist.hh	Wed Sep 25 15:19:29 2002
@@ -72,7 +72,7 @@
   int elements;
   __llist_node *_first, *_last;
 
-  friend __llist_iterator;
+  friend class __llist_iterator;
 
 
 protected:
