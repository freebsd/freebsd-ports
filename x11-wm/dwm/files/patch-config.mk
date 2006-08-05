--- config.mk.orig	Wed Aug  2 18:59:04 2006
+++ config.mk	Wed Aug  2 19:00:14 2006
@@ -4,21 +4,21 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = $(X11BASE)/include
+X11LIB = $(X11BASE)/lib
 
 # includes and libs
 INCS = -I/usr/lib -I${X11INC}
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11
 
 # flags
-CFLAGS = -O3 ${INCS} -DVERSION=\"${VERSION}\"
+CFLAGS+= ${INCS} -DVERSION=\"${VERSION}\"
 LDFLAGS = ${LIBS}
 #CFLAGS = -g -Wall -O2 ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = -g ${LIBS}
 
 # compiler
-CC = cc
+CC?= cc
