--- ./src/cmdparse.y.orig	2011-08-07 13:35:55.000000000 +0200
+++ ./src/cmdparse.y	2011-08-07 13:35:24.000000000 +0200
@@ -99,7 +99,7 @@
     }
     printf("done, json output = %s\n", json_output);
 
-    cmdyylex_destroy();
+    // cmdyylex_destroy();
     FREE(context->line_copy);
     FREE(context->compact_error);
     free(context);
