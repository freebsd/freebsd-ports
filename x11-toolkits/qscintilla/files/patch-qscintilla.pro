--- qscintilla.pro.orig	Sat Aug  2 18:52:07 2003
+++ qscintilla.pro	Sat Aug  2 18:52:11 2003
@@ -25,7 +25,6 @@
 
 TEMPLATE = lib
 TARGET = qscintilla
-DESTDIR = $(QTDIR)/lib
 CONFIG += qt warn_off release dll thread
 INCLUDEPATH = . ../include ../src
 DEFINES = QEXTSCINTILLA_MAKE_DLL QT SCI_LEXER
