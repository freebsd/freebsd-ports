--- _config.mk	2008-08-04 14:08:03.000000000 +0200
+++ config.mk	2008-08-04 14:07:48.000000000 +0200
@@ -7,16 +7,16 @@
 PREFIX = ${HOME}
 MANPREFIX = ${PREFIX}/share/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = /usr/local/include
+X11LIB = /usr/local/lib
 
 # includes and libs
 INCS = -I. -I/usr/include -I${X11INC} `pkg-config --cflags xft`
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 `pkg-config --libs xft`
 
 # flags
-CFLAGS = -Os ${INCS} -DVERSION=\"${VERSION}\"
-LDFLAGS = -s ${LIBS}
+CFLAGS += -Os ${INCS} -DVERSION=\"${VERSION}\"
+LDFLAGS += -s ${LIBS}
 #CFLAGS = -g3 -ggdb3 -std=c99 -pedantic -Wall -O0 ${INCS} -DVERSION=\"${VERSION}\" 
 #LDFLAGS = -g3 -ggdb3 ${LIBS}
 
@@ -26,4 +26,4 @@
 #CFLAGS += -xtarget=ultra
 
 # compiler and linker
-CC = cc
+CC? = cc
