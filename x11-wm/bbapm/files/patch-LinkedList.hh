--- LinkedList.hh.orig	Fri Sep  6 20:14:52 2002
+++ LinkedList.hh	Fri Sep  6 20:14:58 2002
@@ -63,7 +63,7 @@
   int elements;
   __llist_node *_first, *_last;
 
-  friend __llist_iterator;
+  friend class __llist_iterator;
 
 
 protected:
