--- config.mk.orig	2014-01-21 18:22:03 UTC
+++ config.mk
@@ -5,15 +5,15 @@ VERSION = 0.6
 
 # paths
 PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+MANPREFIX = ${PREFIX}/man
 
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
@@ -21,5 +21,5 @@ LDFLAGS = -s ${LIBS}
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
 
