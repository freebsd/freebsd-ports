--- config.mk.orig	2019-10-16 17:08:21 UTC
+++ config.mk
@@ -1,9 +1,9 @@
-PREFIX = /usr
+PREFIX ?= /usr/local
 MANPREFIX = $(PREFIX)/man
 
 CC      = cc
 LD      = $(CC)
 
-CFLAGS  = -std=c99 -pedantic -Wall -Os -I/usr/X11R6/include
-LDFLAGS = -lxcb -lxcb-util -lxcb-cursor -L/usr/X11R6/lib
+CFLAGS  := -std=c99 -pedantic -Wall -Os $(CFLAGS)
+LDFLAGS := -lxcb -lxcb-util -lxcb-cursor $(LDFLAGS)
 
