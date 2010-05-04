--- src/process.sh.orig	2010-04-06 07:35:41.000000000 +0200
+++ src/process.sh	2010-04-14 01:05:42.000000000 +0200
@@ -24,9 +24,9 @@
   echo \#define MENU_DEFAULT_ENCODING 1 >> $NEWCONFFILE
 fi
 
-MENU_ENCODING_LIST_SIZE=`grep MENU_ENCODING_LIST src/custom.h | tr -s ' ' ' ' | sed 's/^ //' | grep -v ^\/\/ | tail -n 1 | sed 's/,/\n/g' | wc -l`
+MENU_ENCODING_LIST_SIZE=`grep MENU_ENCODING_LIST src/custom.h | tr -s ' ' ' ' | sed 's/^ //' | grep -v ^\/\/ | tail -n 1 | tr ',' '\n' | wc -l`
 TOGGLE_BG_ORDER_SIZE=`grep    TOGGLE_BG_ORDER    src/custom.h | tr -s ' ' ' ' | sed 's/^ //' | grep -v ^\/\/ | tail -n 1 | sed 's/,/\n/g' | wc -l`
-MENU_CUSTOM_SIZE=`grep        MENU_CUSTOM        src/custom.h | tr -s ' ' ' ' | sed 's/^ //' | grep -v ^\/\/ | tail -n 1 | sed 's/,/\n/g' | wc -l`
+MENU_CUSTOM_SIZE=`grep        MENU_CUSTOM        src/custom.h | tr -s ' ' ' ' | sed 's/^ //' | grep -v ^\/\/ | tail -n 1 | tr ',' '\n' | wc -l`
 echo \#define MENU_ENCODING_LIST_SIZE $MENU_ENCODING_LIST_SIZE              >> $NEWCONFFILE
 echo \#define TOGGLE_BG_ORDER_SIZE    $TOGGLE_BG_ORDER_SIZE | grep -v ' 0$' >> $NEWCONFFILE
 echo \#define MENU_CUSTOM_SIZE        $MENU_CUSTOM_SIZE                     >> $NEWCONFFILE
