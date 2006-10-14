--- build.sh.orig	Wed May  4 19:45:04 2005
+++ build.sh	Sat Sep 30 20:54:52 2006
@@ -100,6 +100,32 @@
 				;;	
 		esac
 		;;
+	"FreeBSD")
+		CC=%%CC%%
+		CXX=%%CXX%%
+		LD=%%CC%%
+		XTEST_LIB_PATH=$X11BASE/lib
+		GECKO_INCLUDES="`${GECKO_CONFIG} --cflags gtkmozembed` -I${LOCALBASE}/include/nspr"
+		GECKO_LIBS="`${GECKO_CONFIG} --libs gtkmozembed` -L${LOCALBASE}/lib"
+		case $MODEL in
+			"amd64")
+				AWT_LIB_PATH=$JAVA_HOME/jre/lib/amd64
+				SWT_PTR_CFLAGS=-DSWT_PTR_SIZE_64
+				OUTPUT_DIR=../../../org.eclipse.swt.gtk.freebsd.amd64
+				makefile="make_freebsd.mak"
+				echo "Building FreeBSD GTK AMD64 version of SWT"
+				;;
+			"i386")
+				AWT_LIB_PATH=$JAVA_HOME/jre/lib/i386
+				OUTPUT_DIR=../../../org.eclipse.swt.gtk.freebsd.x86
+				makefile="make_freebsd.mak"
+				echo "Building FreeBSD GTK x86 version of SWT"
+				;;
+			*)
+				echo "*** Unknown MODEL <${MODEL}>"
+				;;	
+		esac
+		;;
 	"SunOS")
 		CC=gcc
 		LD=gcc
@@ -126,6 +152,6 @@
 	;;
 esac
 
-export CC LD JAVA_HOME AWT_LIB_PATH XTEST_LIB_PATH GECKO_SDK GECKO_INCLUDES GECKO_LIBS SWT_PTR_CFLAGS CDE_HOME OUTPUT_DIR
+export CC CXX LD JAVA_HOME AWT_LIB_PATH XTEST_LIB_PATH GECKO_SDK GECKO_INCLUDES GECKO_LIBS SWT_PTR_CFLAGS CDE_HOME OUTPUT_DIR
 
-make -f $makefile ${1} ${2} ${3} ${4}
+gmake -f $makefile ${1} ${2} ${3} ${4}
