
--- libawn/awn-settings.old.c	2009-12-05 08:14:18.000000000 +0000
+++ libawn/awn-settings.c	2009-12-05 08:14:31.000000000 +0000
@@ -139,7 +139,7 @@
 
   AwnSettings *s = NULL;
 
-  s = g_new(AwnSettings, 1);
+  s = g_new0(AwnSettings, 1);
 
   settings = s;
 


