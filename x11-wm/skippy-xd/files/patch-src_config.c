--- src/config.c.orig	2015-02-24 13:35:00 UTC
+++ src/config.c
@@ -73,9 +73,9 @@ config_parse(const char *config) {
 	int ix = 0, l_ix = 0;
 	dlist *new_config = 0;
 	
-	regcomp(&re_section, "^[[:space:]]*\\[[[:space:]]*([[:alnum:]]*?)[[:space:]]*\\][[:space:]]*$", REG_EXTENDED);
+	regcomp(&re_section, "^[[:space:]]*\\[[[:space:]]*([[:alnum:]]*)[[:space:]]*\\][[:space:]]*$", REG_EXTENDED);
 	regcomp(&re_empty, "^[[:space:]]*#|^[[:space:]]*$", REG_EXTENDED);
-	regcomp(&re_entry, "^[[:space:]]*([[:alnum:]]+)[[:space:]]*=[[:space:]]*(.*?)[[:space:]]*$", REG_EXTENDED);
+	regcomp(&re_entry, "^[[:space:]]*([[:alnum:]]+)[[:space:]]*=[[:space:]]*(.*)[[:space:]]*$", REG_EXTENDED);
 	
 	while(1)
 	{
@@ -150,6 +150,7 @@ config_load(const char *path)
 		fclose(fin);
 		return 0;
 	}
+	data[flen] = '\0';
 	
 	fclose(fin);
 	
