--- config.mk.orig	2015-11-08 22:42:21 UTC
+++ config.mk
@@ -2,11 +2,11 @@
 VERSION = 4.6
 
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
@@ -23,9 +23,9 @@ INCS = -I${X11INC} -I${FREETYPEINC}
 LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS}
 
 # flags
-CPPFLAGS = -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS   = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS  = -s ${LIBS}
+CPPFLAGS+= -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CFLAGS  += -std=c99 ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
