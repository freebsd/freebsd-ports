--- libxklavier/xklavier_config_i18n.c.orig	Tue Jun 13 00:12:44 2006
+++ libxklavier/xklavier_config_i18n.c	Tue Jun 13 00:13:05 2006
@@ -108,7 +108,7 @@ xkl_locale_from_utf8(const gchar * utf8s
 	iconv_t converter;
 	gchar converted[XKL_MAX_CI_DESC_LENGTH];
 	gchar *converted_start = converted;
-	gchar *utf_start = (char *) utf8string;
+	const gchar *utf_start = (const char *) utf8string;
 	size_t clen = XKL_MAX_CI_DESC_LENGTH - 1;
 	const gchar *charset;
 
