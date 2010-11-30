--- tclconfig/tcl.m4.orig	2010-11-13 19:12:50.000000000 +0100
+++ tclconfig/tcl.m4	2010-11-30 15:43:29.209843513 +0100
@@ -3360,7 +3360,7 @@
     AC_REQUIRE([TEA_PUBLIC_TCL_HEADERS])
     AC_MSG_CHECKING([for Tcl private include files])
 
-    TCL_SRC_DIR_NATIVE=`${CYGPATH} ${TCL_SRC_DIR}`
+    TCL_SRC_DIR_NATIVE=`${CYGPATH} ${TCL_INCLUDEDIR}`
     TCL_TOP_DIR_NATIVE=\"${TCL_SRC_DIR_NATIVE}\"
 
     # Check to see if tcl<Plat>Port.h isn't already with the public headers
@@ -3399,7 +3399,7 @@
 	    esac
 	    result="Using ${TCL_INCLUDES}"
 	else
-	    if test ! -f "${TCL_SRC_DIR}/generic/tclInt.h" ; then
+	    if test ! -f "${TCL_INCLUDEDIR}/generic/tclInt.h" ; then
 		AC_MSG_ERROR([Cannot find private header tclInt.h in ${TCL_SRC_DIR}])
 	    fi
 	    result="Using srcdir found in tclConfig.sh: ${TCL_SRC_DIR}"
@@ -3527,7 +3527,7 @@
     AC_REQUIRE([TEA_PUBLIC_TK_HEADERS])
     AC_MSG_CHECKING([for Tk private include files])
 
-    TK_SRC_DIR_NATIVE=`${CYGPATH} ${TK_SRC_DIR}`
+    TK_SRC_DIR_NATIVE=`${CYGPATH} ${TK_INCLUDEDIR}`
     TK_TOP_DIR_NATIVE=\"${TK_SRC_DIR_NATIVE}\"
 
     # Check to see if tk<Plat>Port.h isn't already with the public headers
@@ -3577,7 +3577,7 @@
 	    esac
 	    result="Using ${TK_INCLUDES}"
 	else
-	    if test ! -f "${TK_SRC_DIR}/generic/tkInt.h" ; then
+	    if test ! -f "${TK_INCLUDEDIR}/generic/tkInt.h" ; then
 	       AC_MSG_ERROR([Cannot find private header tkInt.h in ${TK_SRC_DIR}])
 	    fi
 	    result="Using srcdir found in tkConfig.sh: ${TK_SRC_DIR}"
