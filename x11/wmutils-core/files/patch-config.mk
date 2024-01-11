--- config.mk.orig	2022-07-01 20:47:48 UTC
+++ config.mk
@@ -4,6 +4,6 @@ LD      = $(CC)
 CC      = cc
 LD      = $(CC)
 
-CFLAGS  = -std=c99 -pedantic -Wall -Os -I/usr/X11R6/include
-LDFLAGS = -lxcb -lxcb-util -lxcb-cursor -L/usr/X11R6/lib
+CFLAGS  := -std=c99 -pedantic -Wall -Os $(CFLAGS)
+LDFLAGS := -lxcb -lxcb-util -lxcb-cursor $(LDFLAGS)
 
