--- khtml/html/html_formimpl.cpp.orig	Sun Jan 29 01:15:24 2006
+++ khtml/html/html_formimpl.cpp	Sun Jan 29 01:43:42 2006
@@ -2303,7 +2303,7 @@
         NodeImpl* const parent = current->parentNode();
         current = current->nextSibling();
         if (!current) {
-            if (parent != this)
+            if (static_cast<HTMLSelectElementImpl*>(parent) != this)
                 current = parent->nextSibling();
         }
     }
