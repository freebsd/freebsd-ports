diff -Naur ./config.mk ../echinus-0.3.8/config.mk
--- ./config.mk	2009-11-07 22:00:00.000000000 +0100
+++ ../echinus-0.3.8/config.mk	2009-11-07 22:01:52.000000000 +0100
@@ -6,10 +6,10 @@
 # paths
 PREFIX = /usr/local
 MANPREFIX = ${PREFIX}/share/man
-CONF = /share/examples/echinus
+CONF = ${PREFIX}/etc/echinus/
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = /usr/local/include
+X11LIB = /usr/local/lib
 
 # includes and libs
 INCS = -I. -I/usr/include -I${X11INC} `pkg-config --cflags xft`
