--- build.py.orig	Tue Sep 17 15:40:30 2002
+++ build.py	Tue Sep 17 15:40:48 2002
@@ -805,7 +805,7 @@
     proPatches["DEFINES"] = [re.compile("@BL_DEFINES@",re.M), defines]
 
     checkQtLibrary()
-    checkThreading ()
+    #checkThreading ()
     checkKDELibrary()
     checkPyQt ()
 
