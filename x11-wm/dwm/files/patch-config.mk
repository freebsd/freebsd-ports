--- config.mk.orig	2011-12-19 15:02:46.000000000 +0000
+++ config.mk	2012-08-18 00:38:31.000000000 +0000
@@ -4,30 +4,34 @@
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
 XINERAMAFLAGS = -DXINERAMA
 
+# Xft
+XFTINCS = -I${X11INC}/freetype2
+XFTLIBS = -L${X11LIB} -lXft
+
 # includes and libs
-INCS = -I. -I/usr/include -I${X11INC}
-LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS}
+INCS = -I. -I/usr/include -I${X11INC} ${XFTINCS}
+LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} ${XFTLIBS}
 
 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+CPPFLAGS+= -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
 #CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
+CFLAGS+= -std=c99 ${INCS} ${CPPFLAGS}
 #LDFLAGS = -g ${LIBS}
-LDFLAGS = -s ${LIBS}
+LDFLAGS+= ${LIBS}
 
 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
