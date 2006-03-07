--- configs/ConfigX.mk.orig	Thu Apr  3 18:14:40 2003
+++ configs/ConfigX.mk	Mon Mar  6 23:53:38 2006
@@ -51,7 +51,7 @@
 # User contributed definitions are available for:
 # hpux, aix, solaris, bsd
 #---------------------------------------------------------------------
-ARCH	= linuxdev
+#ARCH	= linuxdev
 #ARCH	= linux
 #ARCH	= linuxelf
 #ARCH	= sun4
@@ -60,9 +60,9 @@
 #ARCH	= hpux
 #ARCH	= aix
 #ARCH	= solaris
-#ARCH	= bsd
+ARCH	= bsd
 #ARCH	= tru64
-Arch = $(ARCH)
+Arch = bsd
 
 
 #---------------------------------------------------------------------
@@ -307,7 +307,7 @@
 ifeq ($(Arch),bsd)
 INCDIR  +=       -I/usr/$(X11RV)/include
 LIBDIR  +=       -L/usr/$(X11RV)/lib
-LIBS    +=       -lV -lXmu -lXt -lXext -lX11 -lxm
+LIBS    +=       -lXmu -lXt -lXext -lX11
 TARZ    =
 RANLIB  =       ranlib
 VGPATH	=	UNIX
