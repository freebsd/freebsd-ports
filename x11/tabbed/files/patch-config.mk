--- config.mk.orig	2010-09-03 23:40:32.000000000 -0500
+++ config.mk	2010-09-03 23:42:18.000000000 -0500
@@ -4,12 +4,12 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
 # includes and libs
-INCS = -I. -I/usr/include
-LIBS = -L/usr/lib -lc -lX11
+INCS = -I. -I/usr/include -I/usr/local/include
+LIBS = -L/usr/lib -L/usr/local/lib -lc -lX11
 
 # flags
 CPPFLAGS = -DVERSION=\"${VERSION}\"
@@ -21,4 +21,4 @@
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
