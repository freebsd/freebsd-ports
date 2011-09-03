--- ./config.mk.orig	2011-08-19 18:19:22.000000000 +0200
+++ ./config.mk	2011-09-03 13:08:44.000000000 +0200
@@ -7,12 +7,12 @@
 PREFIX?= /usr/local
 BINPREFIX?= ${PREFIX}/bin
 MANPREFIX?= ${PREFIX}/share/man
-CONFPREFIX?= ${PREFIX}/share/examples
+CONFPREFIX?= ${PREFIX}/etc/echinus/
 DOCPREFIX?= ${PREFIX}/share/doc
 CONF?= ${CONFPREFIX}
 
-X11INC?= /usr/X11R6/include
-X11LIB?= /usr/X11R6/lib
+X11INC = /usr/local/include
+X11LIB = /usr/local/lib
 
 # includes and libs
 INCS = -I. -I/usr/include -I${X11INC} `pkg-config --cflags xft`
@@ -44,4 +44,4 @@
 #CFLAGS += -xtarget=ultra
 
 # compiler and linker
-#CC = cc
+CC?= cc
