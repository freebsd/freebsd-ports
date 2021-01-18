--- config.mk.orig	2021-01-04 14:17:43 UTC
+++ config.mk
@@ -4,8 +4,8 @@ VERSION = 0.8
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
 # Xinerama, comment if you don't want it
 XINERAMALIBS = -lXinerama
