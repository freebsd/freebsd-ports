--- config.mk.orig	Fri Jul 21 21:14:42 2006
+++ config.mk	Sat Jul 29 21:01:26 2006
@@ -1,11 +1,11 @@
 # Customize to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = $(X11BASE)/include
+X11LIB = $(X11BASE)/lib
 
 VERSION = 0.5
 
@@ -13,7 +13,7 @@
 LIBS = -L${PREFIX}/lib -L/usr/lib -lc -L${X11LIB} -lX11
 
 # Linux/BSD
-CFLAGS = -O3 -I. -I${PREFIX}/include -I/usr/include -I${X11INC} \
+CFLAGS+= -I. -I${PREFIX}/include -I/usr/include -I${X11INC} \
 	-DVERSION=\"${VERSION}\"
 LDFLAGS = ${LIBS}
 #CFLAGS = -g -Wall -O2 -I. -I${PREFIX}/include -I/usr/include -I${X11INC} \
@@ -26,5 +26,5 @@
 #LIBS += -lnsl -lsocket
 
 AR = ar cr
-CC = cc
+CC?= cc
 RANLIB = ranlib
