--- src/gui/kernel/qevent.h.orig	2024-08-30 14:45:12 UTC
+++ src/gui/kernel/qevent.h
@@ -104,15 +104,15 @@ class Q_GUI_EXPORT QMouseEvent : public QInputEvent (p
 class Q_GUI_EXPORT QMouseEvent : public QInputEvent
 {
 public:
-    QMouseEvent(Type type, const QPointF &localPos, Qt::MouseButton button,
+    QMouseEvent(QEvent::Type type, const QPointF &localPos, Qt::MouseButton button,
                 Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
-    QMouseEvent(Type type, const QPointF &localPos, const QPointF &screenPos,
+    QMouseEvent(QEvent::Type type, const QPointF &localPos, const QPointF &screenPos,
                 Qt::MouseButton button, Qt::MouseButtons buttons,
                 Qt::KeyboardModifiers modifiers);
-    QMouseEvent(Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos,
+    QMouseEvent(QEvent::Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos,
                 Qt::MouseButton button, Qt::MouseButtons buttons,
                 Qt::KeyboardModifiers modifiers);
-    QMouseEvent(Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos,
+    QMouseEvent(QEvent::Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos,
                 Qt::MouseButton button, Qt::MouseButtons buttons,
                 Qt::KeyboardModifiers modifiers, Qt::MouseEventSource source);
     ~QMouseEvent();
@@ -154,7 +154,7 @@ class Q_GUI_EXPORT QHoverEvent : public QInputEvent (p
 class Q_GUI_EXPORT QHoverEvent : public QInputEvent
 {
 public:
-    QHoverEvent(Type type, const QPointF &pos, const QPointF &oldPos, Qt::KeyboardModifiers modifiers = Qt::NoModifier);
+    QHoverEvent(QEvent::Type type, const QPointF &pos, const QPointF &oldPos, Qt::KeyboardModifiers modifiers = Qt::NoModifier);
     ~QHoverEvent();
 
 #ifndef QT_NO_INTEGER_EVENT_COORDINATES
@@ -282,12 +282,12 @@ class Q_GUI_EXPORT QTabletEvent : public QInputEvent (
 #if QT_DEPRECATED_SINCE(5, 15)
     // Actually deprecated since 5.4, in docs
     QT_DEPRECATED_VERSION_X_5_15("Use the other QTabletEvent constructor")
-    QTabletEvent(Type t, const QPointF &pos, const QPointF &globalPos,
+    QTabletEvent(QEvent::Type t, const QPointF &pos, const QPointF &globalPos,
                  int device, int pointerType, qreal pressure, int xTilt, int yTilt,
                  qreal tangentialPressure, qreal rotation, int z,
                  Qt::KeyboardModifiers keyState, qint64 uniqueID); // ### remove in Qt 6
 #endif
-    QTabletEvent(Type t, const QPointF &pos, const QPointF &globalPos,
+    QTabletEvent(QEvent::Type t, const QPointF &pos, const QPointF &globalPos,
                  int device, int pointerType, qreal pressure, int xTilt, int yTilt,
                  qreal tangentialPressure, qreal rotation, int z,
                  Qt::KeyboardModifiers keyState, qint64 uniqueID,
@@ -377,9 +377,9 @@ class Q_GUI_EXPORT QKeyEvent : public QInputEvent (pub
 class Q_GUI_EXPORT QKeyEvent : public QInputEvent
 {
 public:
-    QKeyEvent(Type type, int key, Qt::KeyboardModifiers modifiers, const QString& text = QString(),
+    QKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, const QString& text = QString(),
               bool autorep = false, ushort count = 1);
-    QKeyEvent(Type type, int key, Qt::KeyboardModifiers modifiers,
+    QKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers,
               quint32 nativeScanCode, quint32 nativeVirtualKey, quint32 nativeModifiers,
               const QString &text = QString(), bool autorep = false, ushort count = 1);
     ~QKeyEvent();
@@ -399,7 +399,7 @@ class Q_GUI_EXPORT QKeyEvent : public QInputEvent (pub
 
     // Functions for the extended key event information
 #if QT_DEPRECATED_SINCE(5, 0)
-    static inline QKeyEvent *createExtendedKeyEvent(Type type, int key, Qt::KeyboardModifiers modifiers,
+    static inline QKeyEvent *createExtendedKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers,
                                              quint32 nativeScanCode, quint32 nativeVirtualKey,
                                              quint32 nativeModifiers,
                                              const QString& text = QString(), bool autorep = false,
@@ -682,7 +682,7 @@ class Q_GUI_EXPORT QDragMoveEvent : public QDropEvent 
 {
 public:
     QDragMoveEvent(const QPoint &pos, Qt::DropActions actions, const QMimeData *data,
-                   Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Type type = DragMove);
+                   Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QEvent::Type type = QEvent::DragMove);
     ~QDragMoveEvent();
 
     inline QRect answerRect() const { return rect; }
