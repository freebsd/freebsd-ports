--- ./src/cfgparse.y.orig	2012-04-28 00:14:46.000000000 +0200
+++ ./src/cfgparse.y	2012-04-28 00:15:01.000000000 +0200
@@ -619,7 +619,7 @@
         start_configerror_nagbar(f);
     }
 
-    yylex_destroy();
+    // yylex_destroy();
     FREE(context->line_copy);
     free(context);
     FREE(font_pattern);
