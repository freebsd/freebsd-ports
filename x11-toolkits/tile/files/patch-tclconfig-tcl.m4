--- tclconfig/tcl.m4.orig	2007-12-16 19:19:16.000000000 +0100
+++ tclconfig/tcl.m4	2009-02-14 11:22:54.000000000 +0100
@@ -3513,7 +3513,7 @@
 AC_DEFUN([TEA_PRIVATE_TCL_HEADERS], [
     AC_MSG_CHECKING([for Tcl private include files])
 
-    TCL_SRC_DIR_NATIVE=`${CYGPATH} ${TCL_SRC_DIR}`
+    TCL_SRC_DIR_NATIVE=`${CYGPATH} ${TCL_INCLUDEDIR}`
     TCL_TOP_DIR_NATIVE=\"${TCL_SRC_DIR_NATIVE}\"
     TCL_GENERIC_DIR_NATIVE=\"${TCL_SRC_DIR_NATIVE}/generic\"
     TCL_UNIX_DIR_NATIVE=\"${TCL_SRC_DIR_NATIVE}/unix\"
@@ -3541,8 +3541,8 @@
 	        ;;
 	esac
     else
-	if test ! -f "${TCL_SRC_DIR}/generic/tclInt.h" ; then
-	    AC_MSG_ERROR([Cannot find private header tclInt.h in ${TCL_SRC_DIR}])
+	if test ! -f "${TCL_INCLUDEDIR}/generic/tclInt.h" ; then
+	    AC_MSG_ERROR([yes])
 	fi
     fi
 
@@ -3671,7 +3671,7 @@
 AC_DEFUN([TEA_PRIVATE_TK_HEADERS], [
     AC_MSG_CHECKING([for Tk private include files])
 
-    TK_SRC_DIR_NATIVE=`${CYGPATH} ${TK_SRC_DIR}`
+    TK_SRC_DIR_NATIVE=`${CYGPATH} ${TK_INCLUDEDIR}`
     TK_TOP_DIR_NATIVE=\"${TK_SRC_DIR_NATIVE}\"
     TK_UNIX_DIR_NATIVE=\"${TK_SRC_DIR_NATIVE}/unix\"
     TK_WIN_DIR_NATIVE=\"${TK_SRC_DIR_NATIVE}/win\"
@@ -3706,8 +3706,8 @@
 	        ;;
 	esac
     else
-	if test ! -f "${TK_SRC_DIR}/generic/tkInt.h" ; then
-	    AC_MSG_ERROR([Cannot find private header tkInt.h in ${TK_SRC_DIR}])
+	if test ! -f "${TK_INCLUDEDIR}/generic/tkInt.h" ; then
+	    AC_MSG_ERROR([yes])
 	fi
     fi
 
