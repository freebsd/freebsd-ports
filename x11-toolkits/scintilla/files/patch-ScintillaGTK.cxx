--- ScintillaGTK.cxx.orig	Sun Sep 28 12:41:04 2003
+++ ScintillaGTK.cxx	Sun Sep 28 12:43:32 2003
@@ -965,7 +965,7 @@
 					iconv_t iconvh = iconv_open(source, "UTF-8");
 					if (iconvh != ((iconv_t)(-1))) {
 						char localeVal[4]="\0\0\0";
-						char *pin = utfVal;
+						const char *pin = utfVal;
 						size_t inLeft = strlen(utfVal);
 						char *pout = localeVal;
 						size_t outLeft = sizeof(localeVal);
@@ -1103,7 +1103,7 @@
 	iconv_t iconvh = iconv_open(charSetDest, charSetSource);
 	if (iconvh != ((iconv_t)(-1))) {
 		destForm = new char[len*3+1];
-		char *pin = s;
+		const char *pin = s;
 		size_t inLeft = len;
 		char *pout = destForm;
 		size_t outLeft = len*3+1;
