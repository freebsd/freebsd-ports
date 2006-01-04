--- build.sh.orig	Wed May  4 19:44:42 2005
+++ build.sh	Wed Jan  4 08:43:08 2006
@@ -100,6 +100,34 @@
 				;;	
 		esac
 		;;
+	"FreeBSD")
+		CC=%%CC%%
+		CXX=%%CXX%%
+		LD=%%CC%%
+		XTEST_LIB_PATH=$X11BASE/lib
+		GECKO_I=${X11BASE}/include/${BROWSER}
+		GECKO_INCLUDES="-I${GECKO_I} -I${LOCALBASE}/include/nspr -I${GECKO_I}/xpcom -I${GECKO_I}/string -I${GECKO_I}/embed_base -I${GECKO_I}/embedstring"
+		GECKO_L=${X11BASE}/lib/${BROWSER}
+		GECKO_LIBS="-L${GECKO_L} -L${LOCALBASE}/lib -lxpcom -lnspr4 -lplds4 -lplc4 -lgtkembedmoz"
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
@@ -126,6 +154,6 @@
 	;;
 esac
 
-export CC LD JAVA_HOME AWT_LIB_PATH XTEST_LIB_PATH GECKO_SDK GECKO_INCLUDES GECKO_LIBS SWT_PTR_CFLAGS CDE_HOME OUTPUT_DIR
+export CC CXX LD JAVA_HOME AWT_LIB_PATH XTEST_LIB_PATH GECKO_SDK GECKO_INCLUDES GECKO_LIBS SWT_PTR_CFLAGS CDE_HOME OUTPUT_DIR
 
-make -f $makefile ${1} ${2} ${3} ${4}
+gmake -f $makefile ${1} ${2} ${3} ${4}
