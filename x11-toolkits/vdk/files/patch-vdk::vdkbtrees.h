--- vdk/vdkbtrees.h.orig	Wed Nov 22 14:10:33 2000
+++ vdk/vdkbtrees.h	Thu Aug  5 19:16:36 2004
@@ -717,7 +717,7 @@
 class AbstractRedBlackTree : public AbstractBinaryTree<T, Node> {
 protected:
     virtual Node *FindNode(T q)  
-        { return (root) ? (Node *) root->find(q) : NULL; }
+        { return (this->root) ? (Node *) this->root->find(q) : NULL; }
 };
 
 /*!
@@ -985,14 +985,14 @@
         BlackHeight = -1;
 
     // Check binary tree properties.
-    if (parent != _parent)
+    if (this->parent != _parent)
         return NULL;
-    if (left) {
-        if (object < left->object)
+    if (this->left) {
+        if (this->object < this->left->object)
             return NULL;
     }
-    if (right) {
-        if (right->object < object)
+    if (this->right) {
+        if (this->right->object < this->object)
             return NULL;
     }
 
@@ -1001,15 +1001,15 @@
     // If a node is red, then both its children are black
     // (NULL nodes are black).
     if (clr == Red) {
-        if ((left && left->clr != Black) ||
-            (right && right->clr != Black))
+        if ((this->left && this->left->clr != Black) ||
+            (this->right && this->right->clr != Black))
             return NULL;
     }
 
     // The black-heights of all leaf nodes are equal.
     int bh = NULL;
 
-    if ((! left) && (! right)) {
+    if ((! this->left) && (! this->right)) {
         // Compute black-height of node
         for (Node *sc = (Node *) this; sc; sc = sc->parent)
             if (sc->clr == Black)
@@ -1023,9 +1023,9 @@
                 return NULL;
         }
     }
-    if (left && (! left->CheckTreeProperties((Node *) this)))
+    if (this->left && (! this->left->CheckTreeProperties((Node *) this)))
         return NULL;
-    if (right && (! right->CheckTreeProperties((Node *) this)))
+    if (this->right && (! this->right->CheckTreeProperties((Node *) this)))
         return NULL;
     return 1;
 }
