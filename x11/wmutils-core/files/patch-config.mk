--- config.mk.orig	2017-01-25 13:19:03 UTC
+++ config.mk
@@ -1,9 +1,9 @@
-PREFIX = /usr
+PREFIX ?= /usr/local
 MANPREFIX = $(PREFIX)/man
 
 CC      = cc
 LD      = $(CC)
 
-CFLAGS  = -std=c99 -pedantic -Wall -Os
-LDFLAGS = -lxcb -lxcb-util
+CFLAGS  := -std=c99 -pedantic -Wall $(CFLAGS)
+LDFLAGS := -lxcb -lxcb-util $(LDFLAGS)
 
