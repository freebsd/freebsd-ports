--- ./VkNameList.C.orig	Wed Jul 23 02:39:09 2003
+++ ./VkNameList.C	Wed Jul 23 02:39:23 2003
@@ -105,7 +105,7 @@
 }
 
 void
-VkNameList::remove(int index, int count=1)
+VkNameList::remove(int index, int count)
 {
 	_contents.erase(_contents.begin() + index,
 					_contents.begin() + index + count);
