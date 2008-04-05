--- config.mk.orig	2008-04-03 22:57:01.000000000 +0200
+++ config.mk	2008-04-04 12:05:19.000000000 +0200
@@ -4,19 +4,19 @@
 # Customize below to fit your system
 
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
 #CFLAGS = -g -std=c99 -pedantic -Wall -O2 ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = -g ${LIBS}
 
@@ -25,4 +25,4 @@
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
