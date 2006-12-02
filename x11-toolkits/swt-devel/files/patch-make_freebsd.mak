--- make_freebsd.mak.orig	Fri Dec  1 14:43:20 2006
+++ make_freebsd.mak	Fri Dec  1 14:43:20 2006
@@ -9,7 +9,7 @@
 #     IBM Corporation - initial API and implementation
 #*******************************************************************************
 
-# Makefile for creating SWT libraries for Linux GTK
+# Makefile for creating SWT libraries for FreeBSD GTK
 
 include make_common.mak
 
@@ -78,7 +78,7 @@
 	-fPIC \
 	-I. \
 	-I$(JAVA_HOME)/include \
-	-I$(JAVA_HOME)/include/linux \
+	-I$(JAVA_HOME)/include/freebsd \
 	${SWT_PTR_CFLAGS}
 MOZILLALIBS = -shared -s -Wl,--version-script=mozilla_exports -Bsymbolic
 	
@@ -98,15 +98,16 @@
 CFLAGS = -O -Wall \
 		-DSWT_VERSION=$(SWT_VERSION) \
 		$(NATIVE_STATS) \
-		-DLINUX -DGTK \
+		-DFREEBSD -DGTK \
 		-I$(JAVA_HOME)/include \
-		-I$(JAVA_HOME)/include/linux \
-		-fPIC \
+		-I$(JAVA_HOME)/include/freebsd \
+                -fpic -fPIC \
+                -I$(X11BASE)/include \
 		${SWT_PTR_CFLAGS}
-LIBS = -shared -fPIC -s
+LIBS = -shared -fPIC -fpic -s
 
 
-all: make_swt make_atk make_gnome make_glx
+all: make_swt make_atk $(MAKE_GNOME) make_awt $(MAKE_MOZILLA) $(MAKE_CAIRO) make_glx
 
 #
 # SWT libs
@@ -264,4 +265,4 @@
 # Clean
 #
 clean:
-	rm -f *.o *.so
+	rm -f *.o *.so *.jar
