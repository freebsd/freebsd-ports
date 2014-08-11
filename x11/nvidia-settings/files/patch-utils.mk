--- utils.mk.orig	2014-08-09 21:23:23.872132403 -0700
+++ utils.mk	2014-08-09 21:25:03.537126421 -0700
@@ -34,6 +34,7 @@
 CFLAGS                += -fno-strict-aliasing -fno-omit-frame-pointer -Wformat=2
 CC_ONLY_CFLAGS        ?=
 LDFLAGS               ?=
+LDFLAGS               += -Wl,--as-needed
 BIN_LDFLAGS           ?=

 HOST_CC               ?= $(CC)
