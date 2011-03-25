--- config.mk.orig	2011-03-25 12:53:06.000000000 +0100
+++ config.mk	2011-03-25 12:54:25.000000000 +0100
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
 
 # Xinerama
 XINERAMALIBS = -L${X11LIB} -lXinerama
@@ -19,10 +19,10 @@
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS}
 
 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
+CPPFLAGS+= -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
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
