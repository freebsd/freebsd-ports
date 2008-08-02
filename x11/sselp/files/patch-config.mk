--- config.mk.orig	2008-07-30 19:11:59.000000000 +0200
+++ config.mk	2008-07-30 19:13:21.000000000 +0200
@@ -4,20 +4,20 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = $(LOCALBASE)/include
+X11LIB = $(LOCALBASE)/lib
 
 # includes and libs
 INCS = -I. -I/usr/include -I${X11INC}
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11
 
 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\"
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -s ${LIBS}
+CPPFLAGS += -DVERSION=\"${VERSION}\"
+CFLAGS += -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
+LDFLAGS += -s ${LIBS}
 
 # compiler and linker
-CC = cc
+CC ?= cc
