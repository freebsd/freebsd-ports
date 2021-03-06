--- make_freebsd.mak.orig	2021-01-11 14:12:37 UTC
+++ make_freebsd.mak
@@ -12,7 +12,7 @@
 #     IBM Corporation - initial API and implementation
 #*******************************************************************************
 
-# Makefile for creating SWT libraries for Linux GTK
+# Makefile for creating SWT libraries for FreeBSD GTK
 
 # SWT debug flags for various SWT components.
 #SWT_WEBKIT_DEBUG = -DWEBKIT_DEBUG
@@ -64,9 +64,9 @@ CAIROLIBS = `pkg-config --libs-only-L cairo` -lcairo
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-$(GTK_VERSION) gtk+-unix-print-$(GTK_VERSION)`
 ifeq ($(GTK_VERSION), 4.0)
-GTKLIBS = `pkg-config --libs-only-L gtk+-$(GTK_VERSION) gthread-2.0` $(XLIB64) -L/usr/X11R6/lib -lgtk-4 -lcairo -lgthread-2.0
+GTKLIBS = `pkg-config --libs-only-L gtk+-$(GTK_VERSION) gthread-2.0` $(XLIB64) -L$(LOCALBASE)/lib -lgtk-4 -lcairo -lgthread-2.0
 else
-GTKLIBS = `pkg-config --libs-only-L gtk+-$(GTK_VERSION) gthread-2.0` $(XLIB64) -L/usr/X11R6/lib -lgtk-3 -lgdk-3 -lcairo -lgthread-2.0
+GTKLIBS = `pkg-config --libs-only-L gtk+-$(GTK_VERSION) gthread-2.0` $(XLIB64) -L$(LOCALBASE)/lib -lgtk-3 -lgdk-3 -lcairo -lgthread-2.0
 endif
 
 AWT_LFLAGS = -shared ${SWT_LFLAGS} 
@@ -75,12 +75,13 @@ AWT_LIBS = -L$(AWT_LIB_PATH) -ljawt
 ATKCFLAGS = `pkg-config --cflags atk gtk+-$(GTK_VERSION) gtk+-unix-print-$(GTK_VERSION)`
 ATKLIBS = `pkg-config --libs-only-L atk` -latk-1.0 
 
-GLXLIBS = -lGL -lGLU -lm
+GLXLIBS = -L$(LOCALBASE)/lib -lGL -lGLU -lm
+GLXCFLAGS = -I$(LOCALBASE)/include
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
 
-WEBKITLIBS = `pkg-config --libs-only-l gio-2.0`
+WEBKITLIBS = `pkg-config --libs-only-l gio-2.0` $(XLIB64) -L$(LOCALBASE)/lib
 WEBKITCFLAGS = `pkg-config --cflags gio-2.0`
 
 WEBKIT_EXTENSION_CFLAGS=`pkg-config --cflags gtk+-3.0 webkit2gtk-web-extension-4.0`
@@ -108,17 +109,18 @@ CFLAGS := $(CFLAGS) \
 		$(SWT_WEBKIT_DEBUG) \
 		-DLINUX -DGTK \
 		-I$(JAVA_HOME)/include \
-		-I$(JAVA_HOME)/include/linux \
+		-I$(JAVA_HOME)/include/freebsd \
+		-I$(LOCALBASE)/include \
 		${SWT_PTR_CFLAGS}
 LFLAGS = -shared -fPIC ${SWT_LFLAGS}
 
 ifndef NO_STRIP
-	# -s = Remove all symbol table and relocation information from the executable.
-	#      i.e, more efficent code, but removes debug information. Should not be used if you want to debug.
-	#      https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#Link-Options
-	#      http://stackoverflow.com/questions/14175040/effects-of-removing-all-symbol-table-and-relocation-information-from-an-executab
-	AWT_LFLAGS := $(AWT_LFLAGS) -s
-	LFLAGS := $(LFLAGS) -s
+# -s = Remove all symbol table and relocation information from the executable.
+#      i.e, more efficent code, but removes debug information. Should not be used if you want to debug.
+#      https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#Link-Options
+#      http://stackoverflow.com/questions/14175040/effects-of-removing-all-symbol-table-and-relocation-information-from-an-executab
+AWT_LFLAGS := $(AWT_LFLAGS) -s
+LFLAGS := $(LFLAGS) -s
 endif
 
 all: make_swt make_atk make_glx make_webkit
