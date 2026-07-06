--- test/compose.c.orig	2026-06-26 17:56:33 UTC
+++ test/compose.c
@@ -24,6 +24,8 @@
 #include "test/compose-iter.h"
 #include "test/utils-text.h"
 
+#undef	HAVE_NEWLOCALE
+
 static const char *
 compose_status_string(enum xkb_compose_status status)
 {
