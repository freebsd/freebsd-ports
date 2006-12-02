--- make_freebsd.mak.orig	Wed Nov 15 16:34:25 2006
+++ make_freebsd.mak	Wed Nov 15 16:36:53 2006
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
