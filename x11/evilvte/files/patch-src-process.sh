--- src/process.sh.orig	2010-10-06 08:19:31.000000000 +0200
+++ src/process.sh	2010-11-02 21:09:49.000000000 +0200
@@ -19,11 +19,11 @@
 grep ^#define src/config.o > $CONFFILE
 rm -f $1 src/evilvte.o
 
-MENU_DEFAULT_ENCODING=`grep   MENU_ENCODING_LIST src/custom.h | sed -e 's/\t/ /g' -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | grep 'Default Encoding'`
-MENU_ENCODING_LIST_SIZE=`grep MENU_ENCODING_LIST src/custom.h | sed -e 's/\t/ /g' -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | tr ',' '\n' | grep '"' | wc -l`
-TOGGLE_BG_ORDER_SIZE=`grep    TOGGLE_BG_ORDER    src/custom.h | sed -e 's/\t/ /g' -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | tr ',' '\n' | grep '"' | wc -l`
-MENU_CUSTOM_SIZE=`grep        MENU_CUSTOM        src/custom.h | sed -e 's/\t/ /g' -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | tr ',' '\n' | grep '"' | wc -l`
-UPPER_PROGRAM_NAME=`grep      PROGRAM_NAME       src/custom.h | sed -e 's/\t/ /g' -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | cut -d '"' -f 2 | sed 's/\b\(.\)/\u\1/'`
+MENU_DEFAULT_ENCODING=`grep   MENU_ENCODING_LIST src/custom.h | tr '\t' ' ' | sed -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | grep 'Default Encoding'`
+MENU_ENCODING_LIST_SIZE=`grep MENU_ENCODING_LIST src/custom.h | sed -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | tr '\t,' ' \n' | grep '"' | wc -l`
+TOGGLE_BG_ORDER_SIZE=`grep    TOGGLE_BG_ORDER    src/custom.h | sed -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | tr '\t,' ' \n' | grep '"' | wc -l`
+MENU_CUSTOM_SIZE=`grep        MENU_CUSTOM        src/custom.h | sed -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | tr '\t,' ' \n' | grep '"' | wc -l`
+UPPER_PROGRAM_NAME=`grep      PROGRAM_NAME       src/custom.h | sed -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1 | cut -d '"' -f 2 | tr '[:lower:]' '[:upper:]'`
 [ "$MENU_DEFAULT_ENCODING" != "" ]    && echo \#define MENU_DEFAULT_ENCODING   1                        >> $CONFFILE
 [ "$MENU_ENCODING_LIST_SIZE" != "0" ] && echo \#define MENU_ENCODING_LIST_SIZE $MENU_ENCODING_LIST_SIZE >> $CONFFILE
 [ "$TOGGLE_BG_ORDER_SIZE" != "0" ]    && echo \#define TOGGLE_BG_ORDER_SIZE    $TOGGLE_BG_ORDER_SIZE    >> $CONFFILE
@@ -52,7 +52,7 @@
 [ "$TOGGLE_BG_NO_BACKGROUND" != "" ] && echo \#define TOGGLE_BG_NO_BACKGROUND 1 >> $CONFFILE
 [ "$TOGGLE_BG_OPACITY" != "" ]       && echo \#define TOGGLE_BG_OPACITY       1 >> $CONFFILE
 
-MENU_CUSTOM_DEFINE=`grep MENU_CUSTOM src/custom.h | sed -e 's/\t/ /g' -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1`
+MENU_CUSTOM_DEFINE=`grep MENU_CUSTOM src/custom.h | sed -e 's/^\( \)*//g' | grep -v ^\/\/ | tail -n 1`
 
 MENU_COPY=`echo $MENU_CUSTOM_DEFINE | grep Copy`
 [ "$MENU_COPY" != "" ] && echo \#define MENU_COPY 1 >> $CONFFILE
