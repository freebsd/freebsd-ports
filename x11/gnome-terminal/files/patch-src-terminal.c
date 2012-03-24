--- src/terminal.c.orig	2010-11-10 10:47:14.000000000 -0800
+++ src/terminal.c	2012-03-23 21:10:08.520503912 -0700
@@ -579,7 +579,7 @@
     data = g_new (OwnData, 1);
     data->factory_name = get_factory_name_for_display (display_name);
     data->options = options;
-    data->exit_code = -1;
+    data->exit_code = EXIT_SUCCESS;
     data->argv = argv_copy;
     data->argc = argc_copy;
 
