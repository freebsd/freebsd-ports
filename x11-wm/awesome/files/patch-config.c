--- config.c
+++ config.c
@@ -400,7 +400,7 @@ parse_config(Display * disp, int scr, DC * drawcontext, const char *confpatharg,
     awesomeconf->mwfact = f ? f : 0.6;
 
     /* resize_hints */
-    awesomeconf->resize_hints = config_lookup_float(&awesomelibconf, "awesome.resize_hints");
+    awesomeconf->resize_hints = config_lookup_bool(&awesomelibconf, "awesome.resize_hints");
 
     /* colors */
     tmp = config_lookup_string(&awesomelibconf, "awesome.normal_border_color");
