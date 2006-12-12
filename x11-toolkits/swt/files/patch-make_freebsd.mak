--- make_freebsd.mak.orig	Tue Dec 12 11:49:31 2006
+++ make_freebsd.mak	Tue Dec 12 11:50:20 2006
@@ -9,7 +9,7 @@
 #     IBM Corporation - initial API and implementation
 #*******************************************************************************
 
-# Makefile for creating SWT libraries for Linux GTK
+# Makefile for creating SWT libraries for FreeBSD GTK
 
 include make_common.mak
 
@@ -48,7 +48,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(X11BASE)/lib $(XLIB64) -lXtst
 
 CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc
 
@@ -61,7 +61,7 @@
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 GLXCFLAGS = 
-GLXLIBS = -shared -fPIC -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXLIBS = -shared -fPIC -L$(X11BASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
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
@@ -220,22 +221,22 @@
 	$(CXX) $(MOZILLACFLAGS) ${GECKO_INCLUDES} -c xpcom_stats.cpp	
 
 $(PROFILE14_OBJECTS): xpcom_profile.cpp
-	$(CXX) -o $(PROFILE14_OBJECTS) $(MOZILLACFLAGS) ${PROFILE14_INCLUDES} -c xpcom_profile.cpp	
+	$(CXX) -o $(PROFILE14_OBJECTS) $(MOZILLACFLAGS) ${GECKO_INCLUDES} ${PROFILE14_INCLUDES} -c xpcom_profile.cpp	
 
 $(PROFILE17_OBJECTS): xpcom_profile.cpp
-	$(CXX) -o $(PROFILE17_OBJECTS) $(MOZILLACFLAGS) ${PROFILE17_INCLUDES} -c xpcom_profile.cpp	
+	$(CXX) -o $(PROFILE17_OBJECTS) $(MOZILLACFLAGS) ${GECKO_INCLUDES} ${PROFILE17_INCLUDES} -c xpcom_profile.cpp	
 
 $(PROFILE18_OBJECTS): xpcom_profile.cpp
-	$(CXX) -o $(PROFILE18_OBJECTS) $(MOZILLACFLAGS) ${PROFILE18_INCLUDES} -c xpcom_profile.cpp	
+	$(CXX) -o $(PROFILE18_OBJECTS) $(MOZILLACFLAGS) ${GECKO_INCLUDES} ${PROFILE18_INCLUDES} -c xpcom_profile.cpp	
 
 $(PROFILE14_LIB): $(PROFILE14_OBJECTS)
-	$(CXX) -o $(PROFILE14_LIB) $(PROFILE14_OBJECTS) $(MOZILLALIBS) ${PROFILE14_LIBS}
+	$(CXX) -o $(PROFILE14_LIB) $(PROFILE14_OBJECTS) $(MOZILLALIBS) ${GECKO_LIBS} ${PROFILE14_LIBS}
 
 $(PROFILE17_LIB): $(PROFILE17_OBJECTS)
-	$(CXX) -o $(PROFILE17_LIB) $(PROFILE17_OBJECTS) $(MOZILLALIBS) ${PROFILE17_LIBS}
+	$(CXX) -o $(PROFILE17_LIB) $(PROFILE17_OBJECTS) $(MOZILLALIBS) ${GECKO_LIBS} ${PROFILE17_LIBS}
 
 $(PROFILE18_LIB): $(PROFILE18_OBJECTS)
-	$(CXX) -o $(PROFILE18_LIB) $(PROFILE18_OBJECTS) $(MOZILLALIBS) ${PROFILE18_LIBS}
+	$(CXX) -o $(PROFILE18_LIB) $(PROFILE18_OBJECTS) $(MOZILLALIBS) ${GECKO_LIBS} ${PROFILE18_LIBS}
 
 #
 # GLX lib
@@ -264,4 +265,4 @@
 # Clean
 #
 clean:
-	rm -f *.o *.so
+	rm -f *.o *.so *.jar
