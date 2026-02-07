--- config.mk.orig	2021-10-13 18:48:49 UTC
+++ config.mk
@@ -16,12 +16,12 @@ FREETYPEINC = /usr/include/freetype2
 #FREETYPEINC = ${X11INC}/freetype2
 
 # includes and libs
-INCS = -I${LOCALINC} -I${X11INC} -I${FREETYPEINC}
-LIBS = -L${LOCALLIB} -L${X11LIB} -lm -lfontconfig -lXft -lX11 -lXinerama -lXrender -lXext -lImlib2
+INCS += -I${LOCALINC} -I${X11INC} -I${FREETYPEINC}
+LIBS += -L${LOCALLIB} -L${X11LIB} -lm -lfontconfig -lXft -lX11 -lXinerama -lXrender -lXext -lImlib2
 
 # flags
-CFLAGS = -Wall -Wextra ${INCS} ${CPPFLAGS}
-LDFLAGS = ${LIBS}
+CFLAGS += -Wall -Wextra ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
 CC = cc
