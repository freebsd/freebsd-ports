--- make_freebsd.mak.orig	2018-03-01 07:35:22.000000000 +0100
+++ make_freebsd.mak	2018-06-27 11:33:21.105457000 +0200
@@ -9,7 +9,7 @@
 #     IBM Corporation - initial API and implementation
 #*******************************************************************************
 
-# Makefile for creating SWT libraries for Linux GTK
+# Makefile for creating SWT libraries for FreeBSD GTK
 
 include make_common.mak
 
@@ -43,7 +43,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0 gtk+-unix-print-$(GTK_VERSION)`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(LOCALBASE)/lib $(XLIB64) -lXtst
 
 AWT_LFLAGS = -shared
 AWT_LIBS = -L$(AWT_LIB_PATH) -ljawt
@@ -51,7 +51,8 @@
 ATKCFLAGS = `pkg-config --cflags atk gtk+-2.0 gtk+-unix-print-$(GTK_VERSION)`
 ATKLIBS = `pkg-config --libs-only-L atk gtk+-2.0` -latk-1.0 -lgtk-x11-2.0
 
-GLXLIBS = -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXCFLAGS = -I$(LOCALBASE)/include
+GLXLIBS = -L$(LOCALBASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
@@ -70,14 +71,24 @@
 	-I$(JAVA_HOME)/include/freebsd \
 	${SWT_PTR_CFLAGS}
 MOZILLALFLAGS = -shared -Wl,--version-script=mozilla_exports -Bsymbolic
-	
+MOZILLAEXCLUDES = -DNO__1XPCOMGlueShutdown \
+	-DNO__1XPCOMGlueStartup \
+	-DNO__1XPCOMGlueLoadXULFunctions \
+	-DNO_memmove__ILorg_eclipse_swt_internal_mozilla_nsDynamicFunctionLoad_2I \
+	-DNO_memmove__JLorg_eclipse_swt_internal_mozilla_nsDynamicFunctionLoad_2J \
+	-DNO_nsDynamicFunctionLoad_1sizeof \
+	-DNO__1Call__IIIIII \
+	-DNO__1Call__JJJJJI \
+	-DNO_nsDynamicFunctionLoad
+XULRUNNEREXCLUDES = -DNO__1NS_1InitXPCOM2
+
 SWT_OBJECTS = swt.o c.o c_stats.o callback.o
 AWT_OBJECTS = swt_awt.o
 SWTPI_OBJECTS = swt.o os.o os_structs.o os_custom.o os_stats.o
 CAIRO_OBJECTS = swt.o cairo.o cairo_structs.o cairo_stats.o
 ATK_OBJECTS = swt.o atk.o atk_structs.o atk_custom.o atk_stats.o
 MOZILLA_OBJECTS = swt.o xpcom.o xpcom_custom.o xpcom_structs.o xpcom_stats.o
-XULRUNNER_OBJECTS = swt.o xpcomxul.o xpcomxul_custom.o xpcomxul_structs.o xpcomxul_stats.o xpcomxulglue.o xpcomxulglue_stats.o
+XULRUNNER_OBJECTS = swt.o xpcomxul.o xpcomxul_custom.o xpcomxul_structs.o xpcomxul_stats.o
 XPCOMINIT_OBJECTS = swt.o xpcominit.o xpcominit_structs.o xpcominit_stats.o
 GLX_OBJECTS = swt.o glx.o glx_structs.o glx_stats.o
 
@@ -85,17 +96,18 @@
 		-DSWT_VERSION=$(SWT_VERSION) \
 		$(NATIVE_STATS) \
 		-DFREEBSD -DGTK \
+		-I$(LOCALBASE)/include \
 		-I$(JAVA_HOME)/include \
 		-I$(JAVA_HOME)/include/freebsd \
 		-fPIC \
 		${SWT_PTR_CFLAGS}
 LFLAGS = -shared -fPIC
 
-ifndef NO_STRIP
-	AWT_LFLAGS := $(AWT_LFLAGS) -s
-	MOZILLALFLAGS := $(MOZILLALFLAGS) -s
-	LFLAGS := $(LFLAGS) -s
-endif
+.ifndef NO_STRIP
+AWT_LFLAGS := $(AWT_LFLAGS) -s
+MOZILLALFLAGS := $(MOZILLALFLAGS) -s
+LFLAGS := $(LFLAGS) -s
+.endif
 
 all: make_swt make_atk make_glx
 
@@ -173,16 +185,16 @@
 	$(CXX) -o $(MOZILLA_LIB) $(MOZILLA_OBJECTS) $(MOZILLALFLAGS) ${MOZILLA_LIBS}
 
 xpcom.o: xpcom.cpp
-	$(CXX) $(MOZILLACFLAGS) ${MOZILLA_INCLUDES} -c xpcom.cpp
+	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom.cpp
 
 xpcom_structs.o: xpcom_structs.cpp
-	$(CXX) $(MOZILLACFLAGS) ${MOZILLA_INCLUDES} -c xpcom_structs.cpp
+	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom_structs.cpp
 	
 xpcom_custom.o: xpcom_custom.cpp
-	$(CXX) $(MOZILLACFLAGS) ${MOZILLA_INCLUDES} -c xpcom_custom.cpp
+	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom_custom.cpp
 
 xpcom_stats.o: xpcom_stats.cpp
-	$(CXX) $(MOZILLACFLAGS) ${MOZILLA_INCLUDES} -c xpcom_stats.cpp
+	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom_stats.cpp
 
 #
 # XULRunner lib
@@ -193,22 +205,16 @@
 	$(CXX) -o $(XULRUNNER_LIB) $(XULRUNNER_OBJECTS) $(MOZILLALFLAGS) ${XULRUNNER_LIBS}
 
 xpcomxul.o: xpcom.cpp
-	$(CXX) -o xpcomxul.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcom.cpp
+	$(CXX) -o xpcomxul.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom.cpp
 
 xpcomxul_structs.o: xpcom_structs.cpp
-	$(CXX) -o xpcomxul_structs.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcom_structs.cpp
+	$(CXX) -o xpcomxul_structs.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom_structs.cpp
 	
 xpcomxul_custom.o: xpcom_custom.cpp
-	$(CXX) -o xpcomxul_custom.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcom_custom.cpp
+	$(CXX) -o xpcomxul_custom.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom_custom.cpp
 
 xpcomxul_stats.o: xpcom_stats.cpp
-	$(CXX) -o xpcomxul_stats.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcom_stats.cpp
-
-xpcomxulglue.o: xpcomglue.cpp
-	$(CXX) -o xpcomxulglue.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcomglue.cpp
-
-xpcomxulglue_stats.o: xpcomglue_stats.cpp
-	$(CXX) -o xpcomxulglue_stats.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcomglue_stats.cpp
+	$(CXX) -o xpcomxul_stats.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom_stats.cpp
 
 #
 # XPCOMInit lib
