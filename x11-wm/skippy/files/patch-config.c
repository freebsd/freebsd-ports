--- config.c.orig	Mon Jul  5 22:36:39 2004
+++ config.c	Mon Jul  5 23:32:25 2004
@@ -72,9 +72,9 @@
 	int ix = 0, l_ix = 0;
 	dlist *new_config = 0;
 	
-	regcomp(&re_section, "^[[:space:]]*\\[[[:space:]]*([[:alnum:]]*?)[[:space:]]*\\][[:space:]]*$", REG_EXTENDED);
+	regcomp(&re_section, "^[[:space:]]*\\[[[:space:]]*([[:alnum:]]*)[[:space:]]*\\][[:space:]]*$", REG_EXTENDED);
 	regcomp(&re_empty, "^[[:space:]]*#|^[[:space:]]*$", REG_EXTENDED);
-	regcomp(&re_entry, "^[[:space:]]*([[:alnum:]]+)[[:space:]]*=[[:space:]]*(.*?)[[:space:]]*$", REG_EXTENDED);
+	regcomp(&re_entry, "^[[:space:]]*([[:alnum:]]+)[[:space:]]*=[[:space:]]*(.*)[[:space:]]*$", REG_EXTENDED);
 	
 	while(1)
 	{
@@ -148,6 +148,7 @@
 		fclose(fin);
 		return 0;
 	}
+	data[flen] = '\0';
 	
 	fclose(fin);
 	
