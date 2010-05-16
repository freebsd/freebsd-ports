--- ./config.mk.orig	2010-04-04 18:37:12.000000000 +0530
+++ ./config.mk	2010-04-04 18:37:36.000000000 +0530
@@ -4,8 +4,8 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX = %%PREFIX%%
+MANPREFIX = %%MANPREFIX%%
 
 X11INC = /usr/X11R6/include
 X11LIB = /usr/X11R6/lib
