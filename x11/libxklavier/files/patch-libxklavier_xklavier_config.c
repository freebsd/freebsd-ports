--- libxklavier/xklavier_config.c.orig	Sat Apr 15 21:04:38 2006
+++ libxklavier/xklavier_config.c	Tue Feb 27 14:57:27 2007
@@ -243,7 +243,7 @@
 		return FALSE;
 
 	nodes = xpath_obj->nodesetval;
-	if (nodes != NULL && nodes->nodeTab != NULL) {
+	if (nodes != NULL && nodes->nodeTab != NULL && nodes->nodeNr > 0) {
 		rv = xkl_read_config_item(*nodes->nodeTab, pitem);
 		if (pnode != NULL) {
 			*pnode = *nodes->nodeTab;
@@ -275,7 +275,11 @@
 gchar *
 xkl_strings_concat_comma_separated(gchar ** array)
 {
-	return g_strjoinv(",", array);
+	if (array) {
+		return g_strjoinv(",", array);
+	} else {
+		return g_strdup("");
+	}
 }
 
 void
