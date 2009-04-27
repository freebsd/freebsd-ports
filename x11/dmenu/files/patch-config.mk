--- config.mk.orig	2009-04-18 13:50:04.000000000 +0200
+++ config.mk	2009-04-21 13:15:36.000000000 +0200
@@ -4,11 +4,11 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = $(LOCALBASE)/include
+X11LIB = $(LOCALBASE)/lib
 
 # Xinerama, comment if you don't want it
 XINERAMALIBS = -L${X11LIB} -lXinerama
@@ -19,13 +19,13 @@
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS}
 
 # flags
-CPPFLAGS = -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -s ${LIBS}
+CPPFLAGS+= -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CFLAGS+= -std=c99 ${INCS} ${CPPFLAGS}
+LDFLAGS+= ${LIBS}
 
 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
