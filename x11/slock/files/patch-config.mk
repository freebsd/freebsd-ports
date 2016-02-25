--- config.mk.orig	2013-10-09 16:23:24.000000000 +0200
+++ config.mk	2013-10-09 16:25:18.000000000 +0200
@@ -18,6 +18,9 @@
 CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
 LDFLAGS = -s ${LIBS}
 
+# To enable PAM-based authentication, remove -DHAVE_SHADOW_H from CPPFLAGS
+# and add -DHAVE_PAM instead. Also, add -lpam to LDFLAGS.
+#
 # On *BSD remove -DHAVE_SHADOW_H from CPPFLAGS and add -DHAVE_BSD_AUTH
 # On OpenBSD and Darwin remove -lcrypt from LIBS
