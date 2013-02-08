Fix build with clang

http://icewm.cvs.sourceforge.net/viewvc/icewm/icewm-1.2/src/yarray.h?r1=1.5.4.3&r2=1.5.4.4&pathrev=icewm-1-3-BRANCH

--- src/yarray.h	2009/06/01 17:10:07	1.5.4.3
+++ src/yarray.h	2010/12/25 15:29:53	1.5.4.4
@@ -152,7 +152,8 @@
     }
 
     virtual void remove(const typename YArray<DataType *>::SizeType index) {
-        if (index < YArray<DataType *>::getCount()) delete getItem(index);
+        if (index < YArray<DataType *>::getCount())
+             delete YArray<DataType *>::getItem(index);
         YArray<DataType *>::remove(index);
     }
     
