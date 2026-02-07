--- ./gadgets/config.mk.orig	2007-08-18 08:18:50.000000000 +0200
+++ ./gadgets/config.mk	2014-06-17 14:58:37.000000000 +0200
@@ -14,5 +14,5 @@
 LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = gcc
+CC ?= cc
 LD = ${CC}
