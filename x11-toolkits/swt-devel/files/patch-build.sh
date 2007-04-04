--- build.sh.orig	Fri Feb  2 17:43:50 2007
+++ build.sh	Fri Mar  2 23:12:01 2007
@@ -65,7 +65,7 @@
 esac
 
 # For 64-bit CPUs, we have a switch
-if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' ]; then
+if [ ${MODEL} = 'x86_64' -o ${MODEL} = 'ppc64' -o ${MODEL} = 'ia64' -o ${MODEL} = 'amd64' ]; then
 	SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
 	export SWT_PTR_CFLAGS
 	if [ -d /lib64 ]; then
@@ -74,6 +74,7 @@
 	fi
 fi
 
+if [ x${MAKE_GNOME} = "xmake_gnome" ]; then
 if [ x`pkg-config --exists gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0 && echo YES` = "xYES" ]; then
 	echo "libgnomeui-2.0 found, compiling SWT program support using GNOME"
 	MAKE_GNOME=make_gnome
@@ -81,7 +82,9 @@
 	echo "libgnome-2.0 and libgnomeui-2.0 not found:"
 	echo "    *** SWT Program support for GNOME will not be compiled."
 fi
+fi
 
+if [ x${MAKE_CAIRO} = "xmake_cairo" ]; then
 if [ x`pkg-config --exists cairo && echo YES` = "xYES" ]; then
 	echo "Cairo found, compiling SWT support for the cairo graphics library."
 	MAKE_CAIRO=make_cairo
@@ -89,7 +92,9 @@
 	echo "Cairo not found:"
 	echo "    *** Advanced graphics support using cairo will not be compiled."
 fi
+fi
 
+if [ x${MAKE_MOZILLA} = "xmake_mozilla" ]; then
 if [ -z "${MOZILLA_INCLUDES}" -a -z "${MOZILLA_LIBS}" ]; then
 	if [ x`pkg-config --exists mozilla-xpcom && echo YES` = "xYES" ]; then
 		MOZILLA_INCLUDES=`pkg-config --cflags mozilla-xpcom`
@@ -107,6 +112,7 @@
 		echo "Mozilla/XPCOM or Firefox/XPCOM libraries not found:"
 		echo "    *** Mozilla embedding support will not be compiled."
 	fi
+fi
 fi
 
 # Find AWT if available
