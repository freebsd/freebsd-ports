--- libxklavier/xklavier_config_i18n.c.orig	Tue Nov 23 18:33:37 2004
+++ libxklavier/xklavier_config_i18n.c	Tue Nov 23 18:34:30 2004
@@ -106,7 +106,7 @@
   iconv_t converter;
   static char converted[XKL_MAX_CI_DESC_LENGTH];
   char *convertedStart = converted;
-  char *utfStart = ( char * ) utf8string;
+  const char *utfStart = ( const char * ) utf8string;
   size_t clen = XKL_MAX_CI_DESC_LENGTH - 1;
   const char *charset;
 
