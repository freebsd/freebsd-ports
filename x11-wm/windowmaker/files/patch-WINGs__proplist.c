--- WINGs/proplist.c.orig	2013-05-03 02:48:24.000000000 +0900
+++ WINGs/proplist.c	2013-05-03 02:52:24.000000000 +0900
@@ -1162,7 +1162,7 @@
 	WMPropList *key, *value, *dvalue;
 	WMHashEnumerator e;
 
-	wassertr(source->type == WPLDictionary && dest->type == WPLDictionary);
+	wassertrv(source->type == WPLDictionary && dest->type == WPLDictionary, NULL);
 
 	if (source == dest)
 		return dest;
@@ -1189,7 +1189,7 @@
 	WMPropList *key, *value, *dvalue;
 	WMHashEnumerator e;
 
-	wassertr(source->type == WPLDictionary && dest->type == WPLDictionary);
+	wassertrv(source->type == WPLDictionary && dest->type == WPLDictionary, NULL);
 
 	if (source == dest) {
 		WMPropList *keys = WMGetPLDictionaryKeys(dest);
