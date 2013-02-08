--- build.sh.orig	2011-11-02 21:46:45.000000000 -0500
+++ build.sh	2011-11-02 21:46:57.000000000 -0500
@@ -54,6 +54,9 @@
 	"FreeBSD")
 		SWT_OS=freebsd
 		MAKEFILE=make_freebsd.mak
+		if uname -p > /dev/null 2>&1; then
+			MODEL=`uname -p`
+		fi
 		;;
 	*)
 		SWT_OS=`uname -s | tr -s '[:upper:]' '[:lower:]'`
@@ -92,10 +95,10 @@
 esac
 echo "Model is ${MODEL}"
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 'sparc64'  -o ${MODEL} = 's390x' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 'sparc64'  -o ${MODEL} = 's390x' -o ${MODEL} = 'amd64' ]; then
 	SWT_PTR_CFLAGS=-DJNI64
 	if [ -d /lib64 ]; then
-		XLIB64=-L/usr/X11R6/lib64
+		XLIB64=-L${LOCALBASE}/lib64
 		export XLIB64
 	fi
 	if [ ${MODEL} = 'ppc64' ]; then
@@ -131,6 +134,7 @@
 	export SWT_LFLAGS SWT_PTR_CFLAGS
 fi
 
+if [ x${MAKE_GNOME} = "xmake_gnome" ]; then
 if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES"  -a 	 ${MODEL} != "sparc64" 	]; then
 	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
 	MAKE_GNOME=make_gnome
@@ -138,7 +142,9 @@
 	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
 	echo "    *** SWT Program support for GNOME will not be compiled."
 fi
+fi
 
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
 if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	echo "Cairo found, compiling SWT support for the cairo graphics library."
 	MAKE_CAIRO=make_cairo
@@ -146,40 +152,28 @@
 	echo "Cairo not found:"
 	echo "    *** Advanced graphics support using cairo will not be compiled."
 fi
-
-if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" -a ${MODEL} != 'sparc64' ]; then
-	if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
-		MOZILLA_INCLUDES=`pkg-config --cflags mozilla-xpcom`
-		MOZILLA_LIBS=`pkg-config --libs mozilla-xpcom`
-		export MOZILLA_INCLUDES
-		export MOZILLA_LIBS
-		MAKE_MOZILLA=make_mozilla
-	elif [ x`pkg-config --exists firefox-xpcom && echo YES` = "xYES" ]; then
-		MOZILLA_INCLUDES=`pkg-config --cflags firefox-xpcom`
-		MOZILLA_LIBS=`pkg-config --libs firefox-xpcom`
-		export MOZILLA_INCLUDES
-		export MOZILLA_LIBS
-		MAKE_MOZILLA=make_mozilla
-	elif [ x`pkg-config --exists libxul && echo YES` = "xYES" ]; then
-		XULRUNNER_INCLUDES=`pkg-config --cflags libxul`
-		XULRUNNER_LIBS=`pkg-config --libs libxul`
-		export XULRUNNER_INCLUDES
-		export XULRUNNER_LIBS
-		MAKE_MOZILLA=make_xulrunner
-	else
-		echo "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM"
-		echo "    *** Mozilla embedding support will not be compiled."
-	fi
 fi
 
-if [ x`pkg-config --exists webkit-1.0 && echo YES` = "xYES" ]; then
-	echo "WebKit found, compiling webkit embedded browser support."
-	MAKE_WEBKIT=make_webkit
+if [ x${MAKE_MOZILLA} = "xmake_xulrunner" ]; then
+	echo "Using libxul for gecko support"
+	XULRUNNER_INCLUDES=`pkg-config --cflags libxul libxul-embedding`
+	XULRUNNER_LIBS=`pkg-config --libs libxul libxul-embedding`
+	export XULRUNNER_INCLUDES
+	export XULRUNNER_LIBS
 else
-	echo "WebKit not found:"
-	echo "    *** WebKit embedding support will not be compiled."
+	echo "None of the following libraries were found:  XULRunner/XPCOM"
+	echo "    *** Mozilla embedding support will not be compiled."
 fi
 
+#if [ x`pkg-config --exists webkit-1.0 && echo YES` = "xYES" ]; then
+#	echo "WebKit found, compiling webkit embedded browser support."
+#	MAKE_WEBKIT=make_webkit
+#else
+#	echo "WebKit not found:"
+	echo "    *** WebKit embedding support will not be compiled, causes build to fail."
+	echo "    *** (temporary workaround until a better solution can be found)"
+#fi
+
 # Find AWT if available
 if [ -z "${AWT_LIB_PATH}" ]; then
 	if [ -f ${JAVA_HOME}/jre/lib/${AWT_ARCH}/libjawt.* ]; then
