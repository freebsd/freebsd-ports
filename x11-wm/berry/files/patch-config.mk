--- config.mk.orig	2020-04-23 23:18:46 UTC
+++ config.mk
@@ -36,8 +36,8 @@ LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIB
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS} ${DEBUG_CPPFLAGS}
 #CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS} ${DEBUG_CFLAGS}
-CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS} ${DEBUG_CFLAGS} $(NAME_DEFINES)
-LDFLAGS  = ${LIBS}
+CFLAGS  += -std=c99 -pedantic -Wall -Wno-deprecated-declarations ${INCS} ${CPPFLAGS} ${DEBUG_CFLAGS} $(NAME_DEFINES)
+LDFLAGS += ${LIBS} -lm
 
 # Solaris
 #CFLAGS  = -fast ${INCS} -DVERSION=\"${VERSION}\"
