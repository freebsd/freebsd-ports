--- compile_lib.sh	2009-01-21 20:18:56.000000000 -0500
+++ compile_lib.sh	2009-01-21 20:20:21.000000000 -0500
@@ -7,18 +7,16 @@
 # do configure and gmake in that Qt4 dir
 
 NAME=libqt4intf.so
-QTDIR=../qt-x11-opensource-src-4.4.3
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
-  g++ -D BINUX $INCLUDE_PATH qtpas.cpp -o libqt4intf.so -shared -fPIC -lQtCore -lQtGui  -Xlinker -soname=$NAME -Xlinker --library-path -Xlinker $LIB_PATH
-  echo Showing used Qt libraries when LD_LIBRARY_PATH=$LD_LIBRARY_PATH
-  ldd $NAME | grep libQt
+  %%CXX%% -D BINUX $INCLUDE_PATH qtpas.cpp -o libqt4intf.so -shared -fPIC -lQtCore -lQtGui  -Xlinker -soname=$NAME -Xlinker --library-path -Xlinker $LIB_PATH
   echo stripping library
-  strip --strip-all $NAME
+  %%STRIP_CMD%% --strip-all $NAME
   echo Done
 else
   echo "Please Modify location of Qt4 in this script"
