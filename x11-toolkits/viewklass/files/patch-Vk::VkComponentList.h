--- ./Vk/VkComponentList.h.orig	Wed Jul 23 02:09:51 2003
+++ ./Vk/VkComponentList.h	Wed Jul 23 02:18:22 2003
@@ -41,6 +41,8 @@
 
 #include <Vk/VkConfig.h>
 
+using std::vector;
+
 class VkComponent;
 
 class VkComponentList {
@@ -59,10 +61,10 @@
     VkComponent* operator[](int indx) const { return elements[indx]; }
 
 	void insert(int pos, VkComponent* c)
-		{ elements.insert(&elements[pos], c); }
+		{ elements.insert(elements.begin () + pos, c); }
     
 	void remove(int pos)
-		{ elements.erase(&elements[pos]); }
+		{ elements.erase(elements.begin () + pos); }
     
 private:
     vector<VkComponent*> elements;
