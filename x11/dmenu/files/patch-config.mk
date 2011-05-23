--- config.mk.orig	2011-05-18 18:02:16.000000000 +0200
+++ config.mk	2011-05-20 22:58:36.000000000 +0200
@@ -2,11 +2,11 @@
 VERSION = 4.3.1
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX = %%PREFIX%%
+MANPREFIX = %%MANPREFIX%%
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = %%LOCALBASE%%/include
+X11LIB = %%LOCALBASE%%/lib
 
 # Xinerama, comment if you don't want it
 XINERAMALIBS  = -lXinerama
@@ -17,9 +17,9 @@
 LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS}
 
 # flags
-CPPFLAGS = -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS   = -ansi -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS  = -s ${LIBS}
+CPPFLAGS+= -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CFLAGS  += -ansi ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
