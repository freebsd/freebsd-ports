--- m4/qt-validate-moc.m4.orig	2026-08-06 19:53:11 UTC
+++ m4/qt-validate-moc.m4
@@ -53,6 +53,7 @@ AC_DEFUN([QT6_VALIDATE_MOC], [
     dnl Try to find a Qt 6 'moc'
     AS_IF([test "x$MOCCMD" = "x"],
         [for mocpath in "moc" "qtchooser -run-tool=moc -qt=6" "moc-qt6" \
+                        "%%QT6MOC%%" \
                         "/usr/lib/qt6/moc" "/usr/lib/qt6/libexec/moc" \
                         "/usr/lib64/qt6/moc" "/usr/lib64/qt6/libexec/moc" \
                         "$prefix/lib/qt6/moc" "$prefix/lib/qt6/libexec/moc" \
