--- configs/ConfigX.mk.orig	Fri Nov 24 18:13:58 2006
+++ configs/ConfigX.mk	Fri Nov 24 18:14:19 2006
@@ -34,8 +34,8 @@
 #---------------------------------------------------------------------
 # Tools used in the makefile execution
 #---------------------------------------------------------------------
-CC	=	gcc
-CXX	=	g++
+#CC	=	gcc
+#CXX	=	g++
 
 #---------------------------------------------------------------------
 # VPATH for dependencies on header files
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
@@ -305,9 +305,9 @@
 # FreeBSD with gcc
 #----------------------------------------------------------------------
 ifeq ($(Arch),bsd)
-INCDIR  +=       -I/usr/$(X11RV)/include
-LIBDIR  +=       -L/usr/$(X11RV)/lib
-LIBS    +=       -lV -lXmu -lXt -lXext -lX11 -lxm
+INCDIR  +=       -I$(LOCALBASE)/include
+LIBDIR  +=       -L$(LOCALBASE)/lib
+LIBS    +=       -lXmu -lXt -lXext -lX11
 TARZ    =
 RANLIB  =       ranlib
 VGPATH	=	UNIX
