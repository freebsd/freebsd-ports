--- config.mk.orig	2016-10-04 08:01:36 UTC
+++ config.mk
@@ -4,5 +4,5 @@ LD = $(CC)
 CC = cc
 LD = $(CC)
 
-CFLAGS += -std=c99 -pedantic -Wall -Os
-LDFLAGS += -lxcb
+CFLAGS := -std=c99 -pedantic -Wall $(CFLAGS)
+LDFLAGS := -lxcb $(LDFLAGS)
