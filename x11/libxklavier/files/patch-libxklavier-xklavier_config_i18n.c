--- libxklavier/xklavier_config_i18n.c.orig	Mon Oct 25 21:55:29 2004
+++ libxklavier/xklavier_config_i18n.c	Mon Oct 25 21:56:51 2004
@@ -142,13 +142,14 @@
     XklDebug( 0,
               "Unable to convert %s from UTF-8 to %s, this string will probably display wrong.",
               utf8string, charset );
+    iconv_close( converter );
     return strdup( utf8string );
   }
   *convertedStart = '\0';
 
   iconv_close( converter );
 
-  return converted;
+  return strdup( converted );
 }
 
 /*
