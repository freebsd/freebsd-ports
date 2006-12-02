--- build.sh.orig	Mon Nov 21 23:48:16 2005
+++ build.sh	Fri Dec  1 16:34:03 2006
@@ -31,6 +31,10 @@
 		SWT_OS=solaris
 		MAKEFILE=make_solaris.mak
 		;;
+	"FreeBSD")
+		SWT_OS=freebsd
+		MAKEFILE=make_freebsd.mak
+		;;
 	*)
 		SWT_OS=`uname -s | tr -s '[:upper:]' '[:lower:]'`
 		MAKEFILE=make_linux.mak
@@ -61,7 +65,7 @@
 esac
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 'amd64' ]; then
 	SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
 	export SWT_PTR_CFLAGS
 	if [ -d /lib64 ]; then
@@ -70,6 +74,7 @@
 	fi
 fi
 
+if [ x${MAKE_GNOME} = "xmake_gnome" ]; then
 if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
 	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
 	MAKE_GNOME=make_gnome
@@ -77,7 +82,9 @@
 	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
 	echo "    *** SWT Program support for GNOME will not be compiled."
 fi
+fi
 
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
 if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	echo "Cairo found, compiling SWT support for the cairo graphics library."
 	MAKE_CAIRO=make_cairo
@@ -85,7 +92,9 @@
 	echo "Cairo not found:"
 	echo "    *** Advanced graphics support using cairo will not be compiled."
 fi
+fi
 
+if [ x${MAKE_MOZILLA} = "xmake_mozilla" ]; then
 if [ -z "${GECKO_INCLUDES}" -a -z "${GECKO_LIBS}" ]; then
 	if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
 		GECKO_INCLUDES=`pkg-config --cflags mozilla-xpcom`
@@ -98,6 +107,7 @@
 		echo "    *** Mozilla embedding support will not be compiled."
 	fi
 fi
+fi
 
 # Find AWT if available
 if [ -z "${AWT_LIB_PATH}" ]; then
@@ -126,5 +136,5 @@
 if [ "x${1}" = "xclean" ]; then
 	make -f $MAKEFILE clean
 else
-	make -f $MAKEFILE all $MAKE_GNOME $MAKE_CAIRO $MAKE_AWT $MAKE_MOZILLA ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9}
+	make -f $MAKEFILE all ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9}
 fi
