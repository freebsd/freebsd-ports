--- src/src.pro.orig	2018-09-16 20:18:22 UTC
+++ src/src.pro
@@ -249,15 +249,9 @@ headers.files  = $$HEADERS
 INSTALLS      += target headers
 
 html.files     = $${QWT_ROOT}/doc/html/*
-html.path      = $$[QT_INSTALL_DOCS]/html/qwt5-qt$$QT_MAJOR_VERSION
+html.path      = $$PREFIX/share/doc/qwt5-qt$$QT_MAJOR_VERSION
 INSTALLS      += html
 
 qch.files      = $${QWT_ROOT}/doc/qwt-5.2.0.qch
 qch.path       = $$[QT_INSTALL_DOCS]/qch
 INSTALLS      += qch
-
-unix {
-    man.files += $${QWT_ROOT}/doc/man
-    man.path  = /usr/share
-    INSTALLS  += man
-}
