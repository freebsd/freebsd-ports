--- config.mk.orig	Wed Feb 21 22:21:27 2007
+++ config.mk	Wed Feb 21 22:21:26 2007
@@ -4,18 +4,18 @@
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
+CFLAGS+= ${INCS} -DVERSION=\"${VERSION}\"
 LDFLAGS = ${LIBS}
 #CFLAGS = -g -Wall -O2 ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = -g ${LIBS}
@@ -26,4 +26,4 @@
 #CFLAGS += -xtarget=ultra
 
 # compiler and linker
-CC = cc
+CC?= cc
