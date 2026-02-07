--- panel/plugin.c.orig	2020-08-28 22:09:44 UTC
+++ panel/plugin.c
@@ -17,6 +17,7 @@
 //#define DEBUGPRN
 #include "dbg.h"
 extern panel *the_panel;
+struct _plugin_instance *stam;
 
 
 /**************************************************************/
