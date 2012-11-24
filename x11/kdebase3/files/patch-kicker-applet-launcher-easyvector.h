--- kicker/applets/launcher/easyvector.h.orig	2012-11-24 11:38:20.000000000 +0100
+++ kicker/applets/launcher/easyvector.h	2012-11-24 11:39:40.000000000 +0100
@@ -87,7 +87,7 @@
 template < class VALUE, bool CHECKINDEX >
 void EasyVector< VALUE, CHECKINDEX >::eraseAt(Index index)
 {   _checkIndex(index);
-    erase(this->begin()+index);
+    this->erase(this->begin()+index);
 }
 
 
@@ -108,7 +108,7 @@
         this->push_back(value);
         return;
     }
-    insert(this->begin()+index,value);
+    this->insert(this->begin()+index,value);
 }
 
 
@@ -116,7 +116,7 @@
 void EasyVector< VALUE, CHECKINDEX >::insertAt(EasyVector< VALUE, CHECKINDEX >::Index index,const EasyVector< VALUE, CHECKINDEX > &v)
 {   index=_convertInsertIndex(index);
     _checkInsertIndex(index);
-    insert(this->begin()+index,v.begin(),v.end());
+    this->insert(this->begin()+index,v.begin(),v.end());
 }
 
 
