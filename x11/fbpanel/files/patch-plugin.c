--- plugin.c~	Tue May 16 19:22:41 2006
+++ plugin.c	Tue May 16 19:16:29 2006
@@ -98,7 +98,11 @@
 #ifdef STATIC_DESKNO
     REGISTER_PLUGIN_CLASS(deskno_plugin_class, 0);
 #endif
-    
+
+#if defined(STATIC_CPU) && defined(PLUGIN_CPU)
+    REGISTER_PLUGIN_CLASS(cpu_plugin_class, 0);
+#endif
+
     RET();
 }
 
