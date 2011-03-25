--- config.mk.orig	2010-11-20 10:24:33.000000000 +0100
+++ config.mk	2011-03-24 17:19:41.000000000 +0100
@@ -4,11 +4,11 @@
 # Customize below to fit your system
 
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
@@ -19,9 +19,9 @@
 LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS}
 
 # flags
-CPPFLAGS = -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS   = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS  = -s ${LIBS}
+CPPFLAGS+= -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CFLAGS  += -std=c99 ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
