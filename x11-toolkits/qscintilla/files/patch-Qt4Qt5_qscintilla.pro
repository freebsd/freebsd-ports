--- Qt4Qt5/qscintilla.pro.orig	2012-12-08 10:25:28.000000000 +0100
+++ Qt4Qt5/qscintilla.pro	2013-02-05 11:33:55.000000000 +0100
@@ -42,28 +42,24 @@
 #DEFINES += SCI_NAMESPACE
 
 # Handle both Qt v4 and v3.
-target.path = $$[QT_INSTALL_LIBS]
 isEmpty(target.path) {
-	target.path = $(QTDIR)/lib
+	target.path = %%PREFIX%%/lib/qt4
 }
 
-header.path = $$[QT_INSTALL_HEADERS]
 header.files = Qsci
 isEmpty(header.path) {
-	header.path = $(QTDIR)/include/Qsci
+	header.path = %%PREFIX%%/include/qt4/Qsci
 	header.files = Qsci/qsci*.h
 }
 
-trans.path = $$[QT_INSTALL_TRANSLATIONS]
 trans.files = qscintilla_*.qm
 isEmpty(trans.path) {
-	trans.path = $(QTDIR)/translations
+	trans.path = %%DATADIR%%/translations
 }
 
-qsci.path = $$[QT_INSTALL_DATA]
 qsci.files = ../qsci
 isEmpty(qsci.path) {
-	qsci.path = $(QTDIR)
+	qsci.path = %%DATADIR%%
 }
 
 INSTALLS += header trans qsci target
