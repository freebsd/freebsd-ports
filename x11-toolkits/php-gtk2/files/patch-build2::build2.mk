--- build2/build2.mk.orig	Thu Apr 11 02:19:45 2002
+++ build2/build2.mk	Wed Jul  7 01:51:27 2004
@@ -9,3 +9,3 @@
 	@echo rebuilding $@
-	@autoconf
+	@autoconf253
 
@@ -19,2 +19,2 @@
 	@rm -f $@
-	@autoheader
+	@autoconf253
