-- Replace deprecated qAsConst with std::as_const for Qt 6 compatibility.
-- Qt 6.6+ deprecates qAsConst in favor of std::as_const from <utility>.

--- src/QtColorWidgets/color_palette.cpp.orig	2026-09-28 04:05:33 UTC
+++ src/QtColorWidgets/color_palette.cpp
@@ -11,6 +11,7 @@
 #include <QHash>
 #include <QPainter>
 #include <QFileInfo>
+#include <utility>
 
 using namespace color_widgets;
 
@@ -317,7 +318,11 @@ void ColorPalette::setColors(const QVector<QColor>& co
 void ColorPalette::setColors(const QVector<QColor>& colors)
 {
     p->colors.clear();
+#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
+    for(auto &col: std::as_const(colors))
+#else
     for(auto &col: qAsConst(colors))
+#endif
         p->colors.push_back(qMakePair(col,QString()));
     setDirty(true);
     Q_EMIT colorsChanged(p->colors);
