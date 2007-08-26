--- config.mk.orig	Mon Aug 20 00:36:39 2007
+++ config.mk	Mon Aug 20 00:48:16 2007
@@ -7,19 +7,19 @@
 SRC = tile.c
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = $(X11BASE)/include
+X11LIB = $(X11BASE)/lib
 
 # includes and libs
 INCS = -I. -I/usr/include -I${X11INC}
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11
 
 # flags
-CFLAGS = -Os ${INCS} -DVERSION=\"${VERSION}\"
-LDFLAGS = -s ${LIBS}
+CFLAGS+= ${INCS} -DVERSION=\"${VERSION}\"
+LDFLAGS+= ${LIBS}
 #CFLAGS = -g -Wall -O2 ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = -g ${LIBS}
 
@@ -29,4 +29,4 @@
 #CFLAGS += -xtarget=ultra
 
 # compiler and linker
-CC = cc
+CC?= cc
