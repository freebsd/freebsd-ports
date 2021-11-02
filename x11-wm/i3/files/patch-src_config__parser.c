--- src/config_parser.c.orig	2021-10-19 06:37:59 UTC
+++ src/config_parser.c
@@ -864,7 +864,7 @@ parse_file_result_t parse_file(struct parser_ctx *ctx,
     FILE *fstr;
     char buffer[4096], key[512], value[4096], *continuation = NULL;
 
-    char *old_dir = get_current_dir_name();
+    char *old_dir = getwd(NULL);
     char *dir = NULL;
     /* dirname(3) might modify the buffer, so make a copy: */
     char *dirbuf = sstrdup(f);
