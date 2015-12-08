--- config.mk.orig	2015-11-08 22:39:37 UTC
+++ config.mk
@@ -25,10 +25,10 @@ INCS = -I${X11INC} -I${FREETYPEINC}
 LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS}
 
 # flags
-CPPFLAGS = -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
-#CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
-CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS}
-LDFLAGS  = -s ${LIBS}
+CPPFLAGS+= -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
+#CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
+CFLAGS+= -std=c99 -Wno-deprecated-declarations ${INCS} ${CPPFLAGS}
+LDFLAGS+= ${LIBS}
 
 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
