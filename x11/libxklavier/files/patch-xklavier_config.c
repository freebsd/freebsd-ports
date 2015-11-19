--- libxklavier/xklavier_config.c	2012-08-24 02:23:02.000000000 +0400
+++ libxklavier/xklavier_config.c	2015-11-18 01:56:26.307937000 +0300
@@ -29,6 +29,8 @@
 
 #include "xklavier_private.h"
 
+#include "utf8.c"
+
 static GObjectClass *parent_class = NULL;
 
 static xmlXPathCompExprPtr models_xpath;
@@ -162,6 +164,8 @@
 	gchar *vendor = NULL, *translated = NULL, *escaped =
 	    NULL, *unescaped = NULL;
 
+	guchar *s = NULL;
+
 	gint i;
 
 	*item->name = 0;
@@ -190,17 +194,32 @@
 	desc_element = xkl_find_element(ptr, XML_TAG_DESCR);
 	vendor_element = xkl_find_element(ptr, XML_TAG_VENDOR);
 
-	if (name_element != NULL && name_element->children != NULL)
+	if (name_element != NULL && name_element->children != NULL) {
 		strncat(item->name,
 			(char *) name_element->children->content,
 			XKL_MAX_CI_NAME_LENGTH - 1);
 
+		s = utf8_check((guchar *)item->name);
+
+		for (i = strlen(item->name); i > 0 && s != NULL; i--) {
+			item->name[i] = 0;
+			s = utf8_check((guchar *)item->name);
+		}
+	}
+
 	if (short_desc_element != NULL
 	    && short_desc_element->children != NULL) {
 		strncat(item->short_description,
 			dgettext(XKB_DOMAIN, (const char *)
 				 short_desc_element->children->content),
 			XKL_MAX_CI_SHORT_DESC_LENGTH - 1);
+
+		s = utf8_check((guchar *)item->short_description);
+
+		for (i = strlen(item->short_description); i > 0 && s != NULL; i--) {
+			item->short_description[i] = 0;
+			s = utf8_check((guchar *)item->short_description);
+		}
 	}
 
 	if (desc_element != NULL && desc_element->children != NULL) {
@@ -238,8 +257,18 @@
 			g_free(translated);
 			translated = unescaped;
 		}
+
 		strncat(item->description,
 			translated, XKL_MAX_CI_DESC_LENGTH - 1);
+
+		s = utf8_check((guchar *)item->description);
+
+		for (i = strlen(item->description); i > 0 && s != NULL; i--) {
+			item->description[i] = 0;
+			s = utf8_check((guchar *)item->description);
+		}
+		
+		g_free(s);
 		g_free(translated);
 	}
 
