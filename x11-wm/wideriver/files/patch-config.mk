--- config.mk.orig	2025-07-29 04:27:40 UTC
+++ config.mk
@@ -4,11 +4,11 @@ PREFIX ?= /usr/local
 
 PREFIX ?= /usr/local
 
-INCS = -Iinc -Ipro -Ilib/col/inc
+INCS ?= -Iinc -Ipro -Ilib/col/inc
 
 CPPFLAGS += $(INCS) -D_GNU_SOURCE -DVERSION=\"$(VERSION)\" -DRIVER_LAYOUT_V3_VERSION=$(RIVER_LAYOUT_V3_VERSION)
 
-OFLAGS = -O3
+#OFLAGS = -O3
 WFLAGS = -pedantic -Wall -Wextra -Werror -Wimplicit-fallthrough -Wno-unused-parameter -Wno-format-zero-length
 DFLAGS = -g
 COMPFLAGS = $(WFLAGS) $(OFLAGS) $(DFLAGS)
@@ -26,4 +26,4 @@ LDLIBS += $(foreach p,$(PKGS),$(shell $(PKG_CONFIG) --
 CFLAGS += $(foreach p,$(PKGS),$(shell $(PKG_CONFIG) --cflags $(p)))
 LDLIBS += $(foreach p,$(PKGS),$(shell $(PKG_CONFIG) --libs $(p)))
 
-CC = gcc
+CC ?= gcc
