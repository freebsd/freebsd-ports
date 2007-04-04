--- make_freebsd.mak.orig	Thu Jan 25 12:05:38 2007
+++ make_freebsd.mak	Sat Mar  3 00:48:48 2007
@@ -9,7 +9,7 @@
 #     IBM Corporation - initial API and implementation
 #*******************************************************************************
 
-# Makefile for creating SWT libraries for Linux GTK
+# Makefile for creating SWT libraries for FreeBSD GTK
 
 include make_common.mak
 
@@ -46,7 +46,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(X11BASE)/lib $(XLIB64) -lXtst
 
 CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc
 
@@ -59,7 +59,7 @@
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 GLXCFLAGS = 
-GLXLIBS = -shared -fPIC -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXLIBS = -shared -fPIC -L$(X11BASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
@@ -97,15 +97,16 @@
 		-DFREEBSD -DGTK \
 		-I$(JAVA_HOME)/include \
 		-I$(JAVA_HOME)/include/freebsd \
+		-I$(X11BASE)/include \
 		-fPIC \
 		${SWT_PTR_CFLAGS}
 LIBS = -shared -fPIC
 
-ifndef NO_STRIP
-	AWT_LIBS := $(AWT_LIBS) -s
-	MOZILLALIBS := $(MOZILLALIBS) -s
-	LIBS := $(LIBS) -s
-endif
+.ifndef NO_STRIP
+AWT_LIBS := $(AWT_LIBS) -s
+MOZILLALIBS := $(MOZILLALIBS) -s
+LIBS := $(LIBS) -s
+.endif
 
 all: make_swt make_atk make_gnome make_glx
 
