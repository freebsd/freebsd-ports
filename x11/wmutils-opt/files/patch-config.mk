--- config.mk.orig	2016-10-04 08:01:36 UTC
+++ config.mk
@@ -1,8 +1,8 @@
-PREFIX = /usr
-MANPREFIX = $(PREFIX)/share/man
+PREFIX ?= /usr/local
+MANPREFIX = $(PREFIX)/man
 
 CC = cc
 LD = $(CC)
 
-CFLAGS += -std=c99 -pedantic -Wall -Os
-LDFLAGS += -lxcb
+CFLAGS := -std=c99 -pedantic -Wall $(CFLAGS)
+LDFLAGS := -lxcb $(LDFLAGS)
