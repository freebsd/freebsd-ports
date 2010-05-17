--- ./config.mk.orig	2009-04-18 15:50:04.000000000 +0400
+++ ./config.mk	2010-05-16 21:32:00.163080828 +0400
@@ -4,11 +4,11 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX = %%PREFIX%%
+MANPREFIX = %%MANPREFIX%%
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = %%LOCALBASE%%/include
+X11LIB = %%LOCALBASE%%/lib
 
 # Xinerama, comment if you don't want it
 XINERAMALIBS = -L${X11LIB} -lXinerama
