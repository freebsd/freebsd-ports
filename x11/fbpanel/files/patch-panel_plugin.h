--- panel/plugin.h.orig	2020-08-28 22:09:44 UTC
+++ panel/plugin.h
@@ -9,7 +9,7 @@
 #include <stdio.h>
 #include "panel.h"
 
-struct _plugin_instance *stam;
+extern struct _plugin_instance *stam;
 
 typedef struct {
     /* common */
