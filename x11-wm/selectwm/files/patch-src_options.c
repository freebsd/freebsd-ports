--- src/options.c.orig	2002-05-22 17:39:27 UTC
+++ src/options.c
@@ -32,7 +32,7 @@
 #include "miscui.h"
 #include "modify.h"
 
-static GString *getline (FILE *fichier) {
+static GString *get_line (FILE *fichier) {
 	GString *temp;
 	gchar buf[128];
 	
@@ -64,7 +64,7 @@ static gint read_config_file (config *se
 	}
 	buf = g_string_new ("");
 	while (!feof (config)) {
-		buf = getline (config);
+		buf = get_line (config);
 
 		if (buf->len > 0 && buf->str[0] != '#') {
 			if (g_strrstr (buf->str, ":")) {
