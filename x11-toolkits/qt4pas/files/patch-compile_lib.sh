--- ./compile_lib.sh.orig	2009-04-20 17:59:59.000000000 +0400
+++ ./compile_lib.sh	2009-07-12 15:18:58.000000000 +0400
@@ -1,4 +1,4 @@
-#!/bin/env bash
+#!/bin/env sh
 # get latest from http://users.telenet.be/Jan.Van.hijfte/qtforfpc/fpcqt4.html
 # for more info, you can visit the links on above page to FreePascal and Lazarus wiki
 
@@ -7,18 +7,16 @@
 # do configure and gmake in that Qt4 dir
 
 NAME=libqt4intf.so
-QTDIR=../qt-all-opensource-src-4.5.0
-INCLUDE_PATH="-I. -I$QTDIR/include -I$QTDIR/include/Qt -I$QTDIR/include/QtGui -I$QTDIR/include/QtCore -Iqlcl "
-LIB_PATH=$QTDIR/lib
-export LD_LIBRARY_PATH=$LIB_PATH
+QTDIR=%%QT_INCDIR%%
+INCLUDE_PATH="-I. -I$QTDIR -I$QTDIR/Qt -I$QTDIR/QtGui -I$QTDIR/QtCore -Iqlcl "
+LIB_PATH=%%QT_LIBDIR%%
+
 if [ -e "$LIB_PATH/libQtCore.so.4" ]
 then
   echo please wait for compile to finish ...
-  g++ -D BINUX $INCLUDE_PATH qtpas.cpp -o libqt4intf.so -shared -fPIC -lQtCore -lQtGui -lQtNetwork -lQtWebKit  -Xlinker -soname=$NAME -Xlinker --library-path -Xlinker $LIB_PATH
-  echo Showing used Qt libraries when LD_LIBRARY_PATH=$LD_LIBRARY_PATH
-  ldd $NAME | grep libQt
+  %%CXX%% -D BINUX $INCLUDE_PATH qtpas.cpp -o libqt4intf.so -shared -fPIC -lQtCore -lQtGui -lQtNetwork -lQtWebKit  -Xlinker -soname=$NAME -Xlinker --library-path -Xlinker $LIB_PATH
   echo stripping library
-  strip --strip-all $NAME
+  %%STRIP_CMD%% --strip-all $NAME
   echo Done
 else
   echo "Please Modify location of Qt4 in this script"
