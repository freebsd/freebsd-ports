--- lib/Menu.cc.orig	2005-01-27 17:08:22 UTC
+++ lib/Menu.cc
@@ -30,6 +30,8 @@
 #include "PixmapCache.hh"
 #include "Resource.hh"
 
+#include <cstdlib>
+
 #include <X11/Xlib.h>
 #include <X11/keysym.h>
 
@@ -135,11 +137,11 @@ void bt::MenuStyle::load(const Resource &resource) {
 
   str = resource.read("menu.title.marginWidth", "Menu.Title.MarginWidth", "1");
   title_margin =
-    static_cast<unsigned int>(std::max(strtol(str.c_str(), 0, 0), 0l));
+    static_cast<unsigned int>(std::max(std::strtol(str.c_str(), 0, 0), 0l));
 
   str = resource.read("menu.frame.marginWidth", "Menu.Frame.MarginWidth", "1");
   frame_margin =
-    static_cast<unsigned int>(std::max(strtol(str.c_str(), 0, 0), 0l));
+    static_cast<unsigned int>(std::max(std::strtol(str.c_str(), 0, 0), 0l));
 }
 
 
@@ -363,7 +365,7 @@ unsigned int bt::Menu::insertItem(const MenuItem &item
   } else {
     index = std::min(static_cast<size_t>(index), _items.size());
     it = _items.begin();
-    std::advance<ItemList::iterator, signed>(it, index);
+    std::advance(it, index);
   }
 
   it = _items.insert(it, item);
@@ -514,7 +516,7 @@ void bt::Menu::removeItem(unsigned int id) {
 
 void bt::Menu::removeIndex(unsigned int index) {
   ItemList::iterator it = _items.begin();
-  std::advance<ItemList::iterator, signed>(it, index);
+  std::advance(it, index);
   if (it == _items.end())
     return; // item not found
   removeItemByIterator(it);
@@ -1035,7 +1037,7 @@ void bt::Menu::keyPressEvent(const XKeyEvent * const e
     const ItemList::const_iterator &end = _items.end();
     ItemList::const_iterator anchor = _items.begin();
     if (_active_index != ~0u) {
-      std::advance<ItemList::const_iterator, signed>(anchor, _active_index);
+      std::advance(anchor, _active_index);
 
       // go one paste the current active index
       if (anchor != end && !anchor->separator)
@@ -1055,8 +1057,7 @@ void bt::Menu::keyPressEvent(const XKeyEvent * const e
     ItemList::const_reverse_iterator anchor = _items.rbegin();
     const ItemList::const_reverse_iterator &end = _items.rend();
     if (_active_index != ~0u) {
-      std::advance<ItemList::const_reverse_iterator, signed>
-        (anchor, _items.size() - _active_index - 1);
+      std::advance(anchor, _items.size() - _active_index - 1);
 
       // go one item past the current active index
       if (anchor != end && !anchor->separator)
@@ -1174,7 +1175,7 @@ unsigned int bt::Menu::verifyId(unsigned int id) {
     }
 
     fprintf(stderr, "Error: bt::Menu::verifyId: id %u already used\n", id);
-    abort();
+    std::abort();
   }
 
   std::vector<bool>::iterator it =
