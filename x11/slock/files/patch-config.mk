--- config.mk.orig	2016-11-20 00:31:23 UTC
+++ config.mk
@@ -22,6 +22,10 @@ COMPATSRC = explicit_bzero.c
 
 # On OpenBSD and Darwin remove -lcrypt from LIBS
 #LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 -lXext -lXrandr
+
+# To enable PAM-based authentication, remove -DHAVE_SHADOW_H from CPPFLAGS
+# and add -DHAVE_PAM instead. Also, add -lpam to LDFLAGS.
+#
 # On *BSD remove -DHAVE_SHADOW_H from CPPFLAGS
 # On NetBSD add -D_NETBSD_SOURCE to CPPFLAGS
 #CPPFLAGS = -DVERSION=\"${VERSION}\" -D_BSD_SOURCE -D_NETBSD_SOURCE
