--- ./package.c.orig	2013-05-10 21:55:40.000000000 +0200
+++ ./package.c	2013-05-10 21:56:27.000000000 +0200
@@ -228,17 +228,18 @@
     return;
 }
 
+static char *w_getenv(const char *envname) {
+	char *envvalue;
+	if (! (envvalue = getenv (envname) )) return 0;
+	return strdup(envvalue);
+}
+
 /*
  * Mark packages, which are deemed not to exist, to be skipped.
  */
 
 static int package_exists(struct package *pkg)
 {
-	char *w_getenv(const char *envname) {
-		char *envvalue;
-		if (! (envvalue = getenv (envname) )) return 0;
-		return strdup(envvalue);
-	}
         char *buf, *cmd, *p, *b, *c;
         char *PATH = w_getenv("PATH");
         int len;
