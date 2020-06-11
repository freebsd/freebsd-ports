--- build.sh.orig	2018-03-30 05:04:36 UTC
+++ build.sh
@@ -115,9 +115,19 @@ case $OS in
 			fi
 		fi
 		;;
+	"DragonFly")
+		SWT_OS=dragonfly
+		MAKEFILE=make_dragonfly.mak
+		if uname -p > /dev/null 2>&1; then
+			MODEL=`uname -p`
+		fi
+		;;
 	"FreeBSD")
 		SWT_OS=freebsd
 		MAKEFILE=make_freebsd.mak
+		if uname -p > /dev/null 2>&1; then
+			MODEL=`uname -p`
+		fi
 		;;
 	"Windows_NT")
 		SWT_OS=win32
@@ -149,6 +159,10 @@ case $MODEL in
 		SWT_ARCH=x86
 		AWT_ARCH=i386
 		;;
+	powerpc64)
+		SWT_ARCH=ppc64
+		AWT_ARCH=ppc64
+		;;
 	*)
 		SWT_ARCH=$MODEL
 		AWT_ARCH=$MODEL
@@ -469,10 +483,10 @@ esac	
 
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 'sparcv9'  -o ${MODEL} = 's390x' -o ${MODEL} = 'ppc64le' -o ${MODEL} = 'aarch64' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 'sparcv9'  -o ${MODEL} = 's390x' -o ${MODEL} == 'powerpc64' -o ${MODEL} = 'ppc64le' -o ${MODEL} = 'aarch64'  -o ${MODEL} = 'amd64' ]; then
 	SWT_PTR_CFLAGS=-DJNI64
 	if [ -d /lib64 ]; then
-		XLIB64=-L/usr/X11R6/lib64
+		XLIB64=-L${LOCALBASE}/lib64
 		export XLIB64
 	fi
 	if [ ${MODEL} = 'ppc64' -o ${MODEL} = 'ppc64le' ]; then
@@ -517,37 +531,24 @@ if [ ${MODEL} = 'ppc' -a ${SWT_OS} = 'linux' ]; then
 	export SWT_LFLAGS SWT_PTR_CFLAGS
 fi
 
-
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
 if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	func_echo_plus "Cairo found, compiling SWT support for the cairo graphics library."
 	MAKE_CAIRO=make_cairo
 else
 	func_echo_error "Cairo not found: Advanced graphics support using cairo will not be compiled."
 fi
+fi
 
-if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" -a ${SWT_OS} != 'solaris' ]; then
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
-		func_echo_error "None of the following libraries were found:  Mozilla/XPCOM, Firefox/XPCOM, or XULRunner/XPCOM:"
-		func_echo_error "   >> Mozilla embedding support will not be compiled."
-	fi
+if [ x${MAKE_MOZILLA} = "xmake_xulrunner" ]; then
+	echo "Using libxul for gecko support"
+	XULRUNNER_INCLUDES=`pkg-config --cflags libxul libxul-embedding`
+	XULRUNNER_LIBS=`pkg-config --libs libxul libxul-embedding`
+	export XULRUNNER_INCLUDES
+	export XULRUNNER_LIBS
+else
+	echo "None of the following libraries were found:  XULRunner/XPCOM"
+	echo "    *** Mozilla embedding support will not be compiled."
 fi
 
 # Find AWT if available
