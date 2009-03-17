--- src/Inventor/Qt/SoQtComponent.cpp.orig	2009-03-16 23:36:07.000000000 -0300
+++ src/Inventor/Qt/SoQtComponent.cpp	2009-03-16 23:36:23.000000000 -0300
@@ -100,7 +100,7 @@
   this->parent->removeEventFilter(this);
 }
 
-static void delete_dict_value(unsigned long key, void * value)
+static void delete_dict_value(uintptr_t key, void * value)
 {
   delete (QCursor *)value;
 }
