--- config.mk.orig	2012-11-02 20:09:49.000000000 +0100
+++ config.mk	2012-11-26 22:28:12.270095047 +0100
@@ -11,7 +11,7 @@
 X11LIB = /usr/X11R6/lib
 
 # includes and libs
-INCS = -I. -I/usr/include -I${X11INC} -I/usr/include/freetype2
+INCS = -I. -I/usr/include -I${X11INC} -I${X11INC}/freetype2
 LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 -lutil -lXext -lXft -lfontconfig
 
 # flags
