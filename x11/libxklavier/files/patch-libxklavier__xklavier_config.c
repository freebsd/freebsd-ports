--- libxklavier/xklavier_config.c.orig	Sun Mar 25 16:03:37 2007
+++ libxklavier/xklavier_config.c	Sun Mar 25 16:25:08 2007
@@ -280,7 +280,7 @@
 		return FALSE;
 
 	nodes = xpath_obj->nodesetval;
-	if (nodes != NULL && nodes->nodeTab != NULL) {
+	if (nodes != NULL && nodes->nodeNr) {
 		rv = xkl_read_config_item(config, *nodes->nodeTab, pitem);
 		if (pnode != NULL) {
 			*pnode = *nodes->nodeTab;
