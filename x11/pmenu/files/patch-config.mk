--- config.mk.orig	2021-02-05 04:34:38 UTC
+++ config.mk
@@ -2,16 +2,16 @@
 PROG = pmenu
 
 # paths
-PREFIX = /usr/local
+PREFIX ?= /usr/local
 MANPREFIX = ${PREFIX}/share/man
 
-LOCALINC = /usr/local/include
-LOCALLIB = /usr/local/lib
+LOCALINC = ${LOCALBASE}/include
+LOCALLIB = ${LOCALBASE}/lib
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = ${LOCALBASE}/include/xorg
+X11LIB = ${LOCALBASE}/lib/xorg
 
-FREETYPEINC = /usr/include/freetype2
+FREETYPEINC = ${LOCALBASE}/include/freetype2
 # OpenBSD (uncomment)
 #FREETYPEINC = ${X11INC}/freetype2
 
@@ -20,9 +20,9 @@ INCS = -I${LOCALINC} -I${X11INC} -I${FREETYPEINC}
 LIBS = -L${LOCALLIB} -L${X11LIB} -lm -lfontconfig -lXft -lX11 -lXinerama -lXrender -lXext -lImlib2
 
 # flags
-CPPFLAGS =
-CFLAGS = -Wall -Wextra ${INCS} ${CPPFLAGS}
-LDFLAGS = ${LIBS}
+CPPFLAGS +=
+CFLAGS += -Wall -Wextra ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
-CC = cc
+CC ?= cc
