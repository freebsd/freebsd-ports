--- config.mk.orig	2012-01-08 13:18:43.000000000 +0100
+++ config.mk	2012-02-13 16:57:04.000000000 +0100
@@ -2,11 +2,11 @@
 VERSION = 4.5
 
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
@@ -17,10 +17,10 @@
 LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS}
 
 # flags
-CPPFLAGS = -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CPPFLAGS+= -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
 #CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
-CFLAGS   = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS  = -s ${LIBS}
+CFLAGS  += -std=c99 ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
