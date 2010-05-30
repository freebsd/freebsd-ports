--- config.mk.orig	2010-05-28 12:43:17.000000000 +0200
+++ config.mk	2010-05-28 14:05:14.000000000 +0200
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
 
 # Xinerama
 XINERAMALIBS = -L${X11LIB} -lXinerama
@@ -20,9 +20,9 @@
 
 # flags
 CPPFLAGS = -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
+CFLAGS+= -std=c99 ${INCS} ${CPPFLAGS}
 #CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -g ${LIBS}
+LDFLAGS+= ${LIBS}
 #LDFLAGS = -s ${LIBS}
 
 # Solaris
@@ -30,4 +30,4 @@
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
