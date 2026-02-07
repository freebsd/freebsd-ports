--- ./config.mk.orig	2007-08-18 08:18:50.000000000 +0200
+++ ./config.mk	2014-06-17 14:58:37.000000000 +0200
@@ -49,5 +49,5 @@
 #LDFLAGS = -g ${LIBS}
 
 # compiler and linker
-CC = gcc
+CC ?= cc
 LD = ${CC}
