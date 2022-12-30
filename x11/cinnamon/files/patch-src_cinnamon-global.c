diff --git src/cinnamon-global.c src/cinnamon-global.c
index 23c3f2842..ae8c64a06 100644
--- src/cinnamon-global.c
+++ src/cinnamon-global.c
@@ -16,6 +16,10 @@
 #include <meta/main.h>
 #include <cogl-pango/cogl-pango.h>
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 static CinnamonGlobal *the_object = NULL;
 
 enum {
@@ -1605,4 +1609,4 @@ cinnamon_global_alloc_leak (CinnamonGlobal *global, gint mb)
                                       "xxxxxxxxxxxxxxxxxxxxxxxx"
         );
     }
-}
\ No newline at end of file
+}
