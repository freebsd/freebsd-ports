--- src/engine_loader.c.orig	2009-10-13 20:56:23.000000000 -0400
+++ src/engine_loader.c	2010-11-24 15:34:33.000000000 -0500
@@ -54,7 +54,7 @@ gboolean load_engine(gchar * engine_name
         newengine = dlopen(path,RTLD_NOW);
         if (!newengine)
         {
-            g_warning(dlerror());
+            g_warning("%s", dlerror());
             //here's where we should bail out somehow
         }
     }
