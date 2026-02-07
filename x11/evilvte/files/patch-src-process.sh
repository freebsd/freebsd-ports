--- src/process.sh.orig	2011-12-04 22:40:02.000000000 +0200
+++ src/process.sh	2011-12-04 22:42:40.000000000 +0200
@@ -147,7 +147,7 @@
 
 head -n 1 $0 > src/showvte
 tail -n 6 $0 | grep -v ^grep >> src/showvte
-cat src/custom.h | tr '\t' ' ' | tr -s ' ' ' ' | sed -e 's/^ //' -e 's~/\*~\n~g' | grep ^\#define >> src/showvte
+grep ^\#define src/custom.h | tr '\t' ' ' | tr -s ' ' ' ' | sed -e 's/^ //' -e 's;/\*.*$;;g' >>src/showvte
 
 SHOWVTE_PROG_NAME=`grep PROGRAM_NAME    src/custom.h | tr '\t' ' ' | sed 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | cut -d '"' -f 2`
 [ "$SHOWVTE_PROG_NAME" = "" ] && SHOWVTE_PROG_NAME="evilvte"
