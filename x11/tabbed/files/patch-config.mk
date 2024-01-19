--- config.mk.orig	2014-01-21 18:22:03 UTC
+++ config.mk
@@ -8,12 +8,12 @@ MANPREFIX = ${PREFIX}/share/man
 MANPREFIX = ${PREFIX}/share/man
 
 # includes and libs
-INCS = -I. -I/usr/include
-LIBS = -L/usr/lib -lc -lX11
+INCS = -I. -I${LOCALBASE}/include
+LIBS = -L${LOCALBASE}/lib -lX11
 
 # flags
 CPPFLAGS = -DVERSION=\"${VERSION}\" -D_BSD_SOURCE
-CFLAGS = -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
+CFLAGS += -Wall ${INCS} ${CPPFLAGS}
 LDFLAGS = -s ${LIBS}
 
 # Solaris
