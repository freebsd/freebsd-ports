--- panel/plugin.h.orig	2020-08-30 19:42:52 UTC
+++ panel/plugin.h
@@ -9,7 +9,7 @@
 #include <stdio.h>
 #include "panel.h"
 
-struct _plugin_instance *stam;
+struct _plugin_instance;
 
 typedef struct {
     /* common */
