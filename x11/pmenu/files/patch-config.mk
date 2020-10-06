--- config.mk.orig	2020-10-06 11:12:09 UTC
+++ config.mk
@@ -17,12 +17,12 @@ FREETYPEINC = /usr/include/freetype2
 
 # includes and libs
 INCS = -I${LOCALINC} -I${X11INC} -I${FREETYPEINC}
-LIBS = -L${LOCALLIB} -L${X11LIB} -lm -lfontconfig -lXft -lX11 -lXinerama -lXext -lImlib2
+LIBS += -L${LOCALLIB} -L${X11LIB} -lm -lfontconfig -lXft -lX11 -lXinerama -lXext -lImlib2
 
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
