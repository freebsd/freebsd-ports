--- build.sh.orig	2019-03-07 02:31:04 UTC
+++ build.sh
@@ -72,7 +72,7 @@
 
 cd `dirname $0`
 
-MAKE_TYPE=make
+MAKE_TYPE=gmake
 
 export CFLAGS='-O -Wall -fPIC'
 
@@ -86,8 +86,8 @@
 		MAKEFILE=make_win32.mak
 		;;
 	*)
-		SWT_OS=`uname -s | tr -s '[:upper:]' '[:lower:]'`
-		MAKEFILE=make_linux.mak
+		SWT_OS=`uname -s | tr '[:upper:]' '[:lower:]'`
+		MAKEFILE=make_${SWT_OS}.mak
 		;;
 esac
 
@@ -95,7 +95,7 @@
 if [ "${MODEL}" = "" ]; then
 	if uname -i > /dev/null 2>&1; then
 		MODEL=`uname -i`
-		if [ ${MODEL} = 'unknown' ]; then
+		if [ ${MODEL} = 'unknown' ] || [ ${MODEL} = 'GENERIC' ]; then
 		  MODEL=`uname -m`
 		fi
 	else
@@ -103,7 +103,7 @@
 	fi
 fi
 case $MODEL in
-	"x86_64")
+	"x86_64"|"amd64")
 		SWT_ARCH=x86_64
 		AWT_ARCH=amd64
 		;;
@@ -111,6 +111,10 @@
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
@@ -156,7 +160,7 @@
 				# Cross-platform method of finding JAVA_HOME.
 				# Tested on Fedora 24 and Ubuntu 16
 				DYNAMIC_JAVA_HOME=`readlink -f /usr/bin/java | sed "s:jre/::" | sed "s:bin/java::"`
-				if [ -a "${DYNAMIC_JAVA_HOME}include/jni.h" ]; then
+				if [ -a "${DYNAMIC_JAVA_HOME}include/freebsd/jni.h" ]; then
                 	func_echo_plus "JAVA_HOME not set, but jni.h found, dynamically configured to $DYNAMIC_JAVA_HOME"
             		export JAVA_HOME="$DYNAMIC_JAVA_HOME"
                 else
@@ -194,10 +198,10 @@
 
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ia64' -o ${MODEL} = 's390x' -o ${MODEL} = 'ppc64le' -o ${MODEL} = 'aarch64' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ia64' -o ${MODEL} = 's390x' -o ${MODEL} = 'powerpc64' -o ${MODEL} = 'ppc64le' -o ${MODEL} = 'aarch64' ]; then
 	SWT_PTR_CFLAGS=-DJNI64
 	if [ -d /lib64 ]; then
-		XLIB64=-L/usr/X11R6/lib64
+		XLIB64=-L${LOCALBASE}/lib64
 		export XLIB64
 	fi
 	if [ ${MODEL} = 'ppc64le' ]; then
@@ -214,11 +218,13 @@
 	export SWT_LFLAGS SWT_PTR_CFLAGS
 fi
 
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
 if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	func_echo_plus "Cairo found, compiling SWT support for the cairo graphics library."
 	MAKE_CAIRO=make_cairo
 else
 	func_echo_error "Cairo not found: Advanced graphics support using cairo will not be compiled."
+fi
 fi
 
 # Find AWT if available
@@ -364,4 +370,4 @@
 elif [ "${GTK_VERSION}" = "3.0" -o "${GTK_VERSION}" = "" ]; then
 	export GTK_VERSION="3.0"
 	func_build_gtk3 "$@"
-fi
\ No newline at end of file
+fi
