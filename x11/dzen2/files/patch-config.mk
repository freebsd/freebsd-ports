--- config.mk.orig	2013-07-03 22:32:45.866885213 +0200
+++ config.mk	2013-07-03 22:32:51.306100406 +0200
@@ -49,5 +49,5 @@
 #LDFLAGS = -g ${LIBS}
 
 # compiler and linker
-CC = gcc
+CC ?= cc
 LD = ${CC}
