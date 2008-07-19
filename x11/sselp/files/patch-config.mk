--- config.mk.orig 2008-07-19 13:20:31.000000000 +0200
+++ config.mk  2008-07-19 14:18:14.000000000 +0200
@@ -4,22 +4,22 @@
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
-CFLAGS = -Os ${INCS} -DVERSION=\"${VERSION}\"
-LDFLAGS = ${LIBS}
+CFLAGS += -Os ${INCS} -DVERSION=\"${VERSION}\"
+LDFLAGS += ${LIBS}
 #CFLAGS = -g -Wall -O2 ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = -g ${LIBS}

 # compiler and linker
-CC = cc
+CC ?= cc
 LD = ${CC}
