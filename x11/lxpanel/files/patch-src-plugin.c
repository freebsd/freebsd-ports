--- src/plugin.c.orig	Sat Dec 23 22:15:17 2006
+++ src/plugin.c	Sat Dec 23 22:17:21 2006
@@ -148,6 +148,10 @@
     REGISTER_PLUGIN_CLASS(icons_plugin_class, 0);
 #endif
 
+#if defined(STATIC_CPU) && defined(PLUGIN_CPU)
+    REGISTER_PLUGIN_CLASS(cpu_plugin_class, 0);
+#endif
+
     RET();
 }
 
