--- make_freebsd.mak.orig	2025-10-30 18:52:21 UTC
+++ make_freebsd.mak
@@ -12,7 +12,7 @@
 #     IBM Corporation - initial API and implementation
 #*******************************************************************************
 
-# Makefile for creating SWT libraries for Linux GTK
+# Makefile for creating SWT libraries for FreeBSD GTK
 
 # SWT debug flags for various SWT components.
 #SWT_WEBKIT_DEBUG = -DWEBKIT_DEBUG
@@ -66,11 +66,11 @@ GTKCFLAGS = `pkg-config --cflags gtk4 gtk4-x11 gtk4-un
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 ifeq ($(GTK_VERSION), 4.0)
 GTKCFLAGS = `pkg-config --cflags gtk4 gtk4-x11 gtk4-unix-print`
-GTKLIBS = `pkg-config --libs-only-L gtk4 gtk4-x11 gthread-2.0` $(XLIB64) -L/usr/X11R6/lib -lgtk-4 -lcairo -lgthread-2.0
+GTKLIBS = `pkg-config --libs-only-L gtk4 gtk4-x11 gthread-2.0` $(XLIB64) -L$(LOCALBASE)/lib -lgtk-4 -lcairo -lgthread-2.0
 ATKCFLAGS = `pkg-config --cflags atk gtk4 gtk4-unix-print`
 else
 GTKCFLAGS = `pkg-config --cflags gtk+-$(GTK_VERSION) gtk+-unix-print-$(GTK_VERSION)`
-GTKLIBS = `pkg-config --libs-only-L gtk+-$(GTK_VERSION) gthread-2.0` $(XLIB64) -L/usr/X11R6/lib -lgtk-3 -lgdk-3 -lcairo -lgthread-2.0
+GTKLIBS = `pkg-config --libs-only-L gtk+-$(GTK_VERSION) gthread-2.0` $(XLIB64) -L$(LOCALBASE)/lib -lgtk-3 -lgdk-3 -lcairo -lgthread-2.0
 ATKCFLAGS = `pkg-config --cflags atk gtk+-$(GTK_VERSION) gtk+-unix-print-$(GTK_VERSION)`
 endif
 
@@ -79,12 +79,13 @@ ATKLIBS = `pkg-config --libs-only-L atk` -latk-1.0 
 
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
@@ -118,23 +119,24 @@ CFLAGS := $(CFLAGS) \
 		$(NATIVE_STATS) \
 		$(SWT_DEBUG) \
 		$(SWT_WEBKIT_DEBUG) \
-		-DLINUX -DGTK \
+		-DLINUX -DGTK -Wno-error=deprecated-non-prototype \
 		-I$(JAVA_HOME)/include \
-		-I$(JAVA_HOME)/include/linux \
+		-I$(JAVA_HOME)/include/freebsd \
+		-I$(LOCALBASE)/include \
 		${SWT_PTR_CFLAGS}
 LFLAGS = -shared -fPIC ${SWT_LFLAGS}
 
 # Treat all warnings as errors. If your new code produces a warning, please
 # take time to properly understand and fix/silence it as necessary.
-CFLAGS += -Werror
+#CFLAGS += -Werror
 
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
