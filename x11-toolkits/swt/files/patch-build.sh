--- build.sh.orig	2021-09-06 06:22:24 UTC
+++ build.sh
@@ -72,7 +72,7 @@ echo -e "${RED}*** ${@}${NC}"
 
 cd `dirname $0`
 
-MAKE_TYPE=make
+MAKE_TYPE=gmake
 
 export CFLAGS='-O -Wall -fPIC'
 
@@ -86,15 +86,15 @@ case $OS in
 		MAKEFILE=make_win32.mak
 		;;
 	*)
-		SWT_OS=`uname -s | tr -s '[:upper:]' '[:lower:]'`
-		MAKEFILE=make_linux.mak
+		SWT_OS=`uname -s | tr '[:upper:]' '[:lower:]'`
+		MAKEFILE=make_${SWT_OS}.mak
 		;;
 esac
 
 # Determine which CPU type we are building for
 if [ "${MODEL}" = "" ]; then
-	if uname -i > /dev/null 2>&1; then
-		MODEL=`uname -i`
+	if uname -p > /dev/null 2>&1; then
+		MODEL=`uname -p`
 		if [ ${MODEL} = 'unknown' ]; then
 		  MODEL=`uname -m`
 		fi
@@ -103,10 +103,18 @@ if [ "${MODEL}" = "" ]; then
 	fi
 fi
 case $MODEL in
-	"x86_64")
+	"x86_64"|"amd64")
 		SWT_ARCH=x86_64
 		AWT_ARCH=amd64
 		;;
+	powerpc64)
+		SWT_ARCH=ppc64
+		AWT_ARCH=ppc64
+		;;
+	powerpc64le)
+		SWT_ARCH=ppc64le
+		AWT_ARCH=ppc64le
+		;;
 	*)
 		SWT_ARCH=$MODEL
 		AWT_ARCH=$MODEL
@@ -148,10 +156,10 @@ esac
 
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64le' -o ${MODEL} = 'aarch64' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'amd64' -o ${MODEL} = 'powerpc64' -o ${MODEL} = 'powerpc64le' -o ${MODEL} = 'ppc64le' -o ${MODEL} = 'aarch64' ]; then
 	SWT_PTR_CFLAGS=-DJNI64
 	if [ -d /lib64 ]; then
-		XLIB64=-L/usr/X11R6/lib64
+		XLIB64=-L${LOCALBASE}/lib64
 		export XLIB64
 	fi
 	if [ ${MODEL} = 'ppc64le' ]; then
@@ -163,18 +171,20 @@ if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64le' -o ${
 	export SWT_PTR_CFLAGS
 fi
 
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
 if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	func_echo_plus "Cairo found, compiling SWT support for the cairo graphics library."
 	MAKE_CAIRO=make_cairo
 else
 	func_echo_error "Cairo not found: Advanced graphics support using cairo will not be compiled."
 fi
+fi
 
 # Find AWT if available
 if [ ${SWT_OS} = 'win32' ]; then
 	AWT_LIB_EXPR="jawt.dll"
 else
-	AWT_LIB_EXPR="libjawt.*"
+	AWT_LIB_EXPR="libjawt.so"
 fi
 
 if [ -z "${AWT_LIB_PATH}" ]; then
@@ -332,4 +342,4 @@ elif [ "${GTK_VERSION}" = "4.0" ]; then
 elif [ "${GTK_VERSION}" = "3.0" -o "${GTK_VERSION}" = "" ]; then
 	export GTK_VERSION="3.0"
 	func_build_gtk3 "$@"
-fi
\ No newline at end of file
+fi
