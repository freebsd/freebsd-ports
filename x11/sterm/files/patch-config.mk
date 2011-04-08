--- config.mk.orig	2011-01-23 12:30:01.000000000 +0100
+++ config.mk	2011-04-06 14:25:05.291720015 +0200
@@ -5,6 +5,7 @@
 
 # paths
 PREFIX = /usr/local
+LOCALBASE= /usr/local
 MANPREFIX = ${PREFIX}/share/man
 
 X11INC = /usr/X11R6/include
@@ -16,8 +17,8 @@
 
 # flags
 CPPFLAGS = -DVERSION=\"${VERSION}\"
-CFLAGS += -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS += -s ${LIBS}
+CFLAGS += -std=c99 -pedantic -Wall ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
 CC ?= cc
