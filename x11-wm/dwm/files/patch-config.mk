--- config.mk.orig	2008-06-18 23:08:29.000000000 +0200
+++ config.mk	2008-06-20 10:39:37.000000000 +0200
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
@@ -19,9 +19,9 @@
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS}
 
 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -s ${LIBS}
+CPPFLAGS+= -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CFLAGS+= ${INCS} ${CPPFLAGS}
+LDFLAGS+= ${LIBS}
 
 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
