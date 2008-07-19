--- config.mk.orig 2008-07-13 17:31:26.000000000 +0200
+++ config.mk  2008-07-14 15:01:43.000000000 +0200
@@ -4,14 +4,14 @@
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

-IMLIB2INC = /usr/include/imlib2
-IMLIB2LIB = /usr/lib/imlib2/
+IMLIB2INC = $(LOCALBASE)/imlib2
+IMLIB2LIB = $(LOCALBASE)/lib/imlib2/

 # Xinerama, comment if you don't want it
 XINERAMALIBS = -L${X11LIB} -lXinerama
@@ -22,13 +22,13 @@
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} -L ${IMLIB2LIB} -lImlib2

 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -s ${LIBS}
+CPPFLAGS += -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CFLAGS += -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}

 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = ${LIBS}

 # compiler and linker
-CC = cc
+CC ?= cc
