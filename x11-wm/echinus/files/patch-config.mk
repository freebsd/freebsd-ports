--- config.mk.orig	2011-09-19 21:42:25 UTC
+++ config.mk
@@ -7,12 +7,12 @@ VERSION = 0.4.9
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
@@ -44,4 +44,4 @@ LIBS += -lXrandr
 #CFLAGS += -xtarget=ultra
 
 # compiler and linker
-#CC = cc
+CC?= cc
