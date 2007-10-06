--- config.mk.orig	2007-09-26 11:41:29.000000000 +0300
+++ config.mk	2007-09-26 11:42:35.000000000 +0300
@@ -7,19 +7,19 @@
 LAYOUTS = layouts/tile.c layouts/floating.c layouts/max.c
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-X11INC = /usr/include/X11
-X11LIB = /usr/lib/X11
+X11INC = ${X11BASE}/include
+X11LIB = ${X11BASE}/lib
 
 # includes and libs
 INCS = -I. -I/usr/include -I${X11INC} `pkg-config --cflags libconfig xft`
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 `pkg-config --libs libconfig xft` -lXext -lXrandr -lXinerama
 
 # flags
-CFLAGS = -fgnu89-inline -std=gnu99 -ggdb3 -pipe -Wall -Wextra -W -Wchar-subscripts -Wundef -Wshadow -Wcast-align -Wwrite-strings -Wsign-compare -Wunused -Wuninitialized -Winit-self -Wpointer-arith -Wredundant-decls -Wno-format-zero-length -Wmissing-prototypes -Wmissing-format-attribute -Wmissing-noreturn -O3 ${INCS} -DVERSION=\"${VERSION}\"
-LDFLAGS = -ggdb3 ${LIBS}
+CFLAGS+= -pipe -Wall -W -Wchar-subscripts -Wshadow -Wcast-align -Wwrite-strings -Wunused -Wuninitialized -Wpointer-arith -Wredundant-decls -Wmissing-prototypes ${INCS} -DVERSION=\"${VERSION}\"
+LDFLAGS+= ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
