Fixes the build on i386 with clang 6.0:

kernel/qx11embed_x11.cpp:486:20: error: non-constant-expression cannot be narrowed from type 'unsigned int' to 'long' in initializer list [-Wc++11-narrowing]
    long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
                   ^~~~~~~~~~~~~~
kernel/qx11embed_x11.cpp:486:20: note: insert an explicit cast to silence this issue
    long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
                   ^~~~~~~~~~~~~~
                   static_cast<long>( )

--- src/gui/kernel/qx11embed_x11.cpp.orig	2018-01-07 21:44:01 UTC
+++ src/gui/kernel/qx11embed_x11.cpp
@@ -275,7 +275,7 @@ class QHackWidget : public QWidget (public)
     QTLWExtra* topData() { return d_func()->topData(); }
 };
 
-static unsigned int XEMBED_VERSION = 0;
+static quint32 XEMBED_VERSION = 0;
 
 enum QX11EmbedMessageType {
     XEMBED_EMBEDDED_NOTIFY = 0,
@@ -483,7 +483,7 @@ QX11EmbedWidget::QX11EmbedWidget(QWidget *parent)
                     | ExposureMask | StructureNotifyMask
                     | SubstructureNotifyMask | PropertyChangeMask);
 
-    long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
+    quint32 data[] = {XEMBED_VERSION, XEMBED_MAPPED};
     XChangeProperty(x11Info().display(), internalWinId(), ATOM(_XEMBED_INFO),
                     ATOM(_XEMBED_INFO), 32, PropModeReplace,
                     (unsigned char*) data, 2);
@@ -1578,7 +1578,7 @@ void QX11EmbedContainer::showEvent(QShowEvent *)
 {
     Q_D(QX11EmbedContainer);
     if (d->client) {
-        long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
+        quint32 data[] = {XEMBED_VERSION, XEMBED_MAPPED};
 	XChangeProperty(x11Info().display(), d->client, ATOM(_XEMBED_INFO), ATOM(_XEMBED_INFO), 32,
 			PropModeReplace, (unsigned char *) data, 2);
     }
@@ -1594,7 +1594,7 @@ void QX11EmbedContainer::hideEvent(QHideEvent *)
 {
     Q_D(QX11EmbedContainer);
     if (d->client) {
-        long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
+        quint32 data[] = {XEMBED_VERSION, XEMBED_MAPPED};
 	XChangeProperty(x11Info().display(), d->client, ATOM(_XEMBED_INFO), ATOM(_XEMBED_INFO), 32,
 			PropModeReplace, (unsigned char *) data, 2);
     }
