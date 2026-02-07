--- regex_feature.h.orig	Tue May 14 16:05:14 2002
+++ regex_feature.h	Tue May 14 16:05:29 2002
@@ -16,6 +16,7 @@
 #ifndef REGEX_FEATURE_H
 #define REGEX_FEATURE_H
 
+#include <sys/types.h>
 #include <regex.h>
 
 regex_t *regex_feature_alloc(char *regex_str);
