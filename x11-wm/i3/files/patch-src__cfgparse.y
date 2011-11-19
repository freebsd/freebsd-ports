--- ./src/cfgparse.y.orig	2011-08-01 23:24:22.000000000 +0200
+++ ./src/cfgparse.y	2011-08-07 13:35:02.000000000 +0200
@@ -468,7 +468,7 @@
         start_configerror_nagbar(f);
     }
 
-    yylex_destroy();
+    // yylex_destroy();
     FREE(context->line_copy);
     free(context);
     free(new);
