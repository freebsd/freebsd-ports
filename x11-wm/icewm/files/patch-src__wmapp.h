--- src/wmapp.h.orig
+++ src/wmapp.h
@@ -78,7 +78,7 @@
     Window managerWindow;
 };
 
-#if 0
+#ifdef CONFIG_GUIEVENTS
 extern YWMApp * wmapp;
 #endif
 
