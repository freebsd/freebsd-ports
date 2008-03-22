--- plugin.c~	2007-04-21 14:28:25.000000000 +0300
+++ plugin.c	2008-03-19 15:54:08.000000000 +0200
@@ -65 +65,5 @@
-    
+
+#ifdef STATIC_TCLOCK
+    REGISTER_PLUGIN_CLASS(tclock_plugin_class, 0);
+#endif
+  
@@ -101 +105,5 @@
-    
+
+#if defined(STATIC_CPU) && defined(PLUGIN_CPU)
+    REGISTER_PLUGIN_CLASS(cpu_plugin_class, 0);
+#endif
+
