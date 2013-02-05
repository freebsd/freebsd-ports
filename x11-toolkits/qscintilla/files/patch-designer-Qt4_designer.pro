--- designer-Qt4/designer.pro.orig	2011-06-13 14:16:23.000000000 +0200
+++ designer-Qt4/designer.pro	2013-02-05 11:25:33.000000000 +0100
@@ -9,7 +9,9 @@
 HEADERS = qscintillaplugin.h
 SOURCES = qscintillaplugin.cpp
 
-target.path = $$[QT_INSTALL_PLUGINS]/designer
-INSTALLS += target
 
-LIBS += -lqscintilla2
+LIBS += -L../Qt4Qt5 -lqscintilla2
+INCLUDEPATH = . ../Qt4Qt5
+
+target.path = %%PREFIX%%/lib/qt4/plugins/designer
+INSTALLS += target
