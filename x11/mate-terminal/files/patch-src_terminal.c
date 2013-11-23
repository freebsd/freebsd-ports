--- src/terminal.c.orig	2012-07-27 16:57:04.000000000 -0500
+++ src/terminal.c	2012-07-27 16:57:20.000000000 -0500
@@ -598,7 +598,7 @@
 		data = g_new (OwnData, 1);
 		data->factory_name = get_factory_name_for_display (display_name);
 		data->options = options;
-		data->exit_code = -1;
+		data->exit_code = EXIT_SUCCESS;
 		data->argv = argv_copy;
 		data->argc = argc_copy;
 
