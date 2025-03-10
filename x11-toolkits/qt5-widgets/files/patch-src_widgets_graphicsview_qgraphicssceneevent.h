--- src/widgets/graphicsview/qgraphicssceneevent.h.orig	2024-08-30 14:45:12 UTC
+++ src/widgets/graphicsview/qgraphicssceneevent.h
@@ -82,7 +82,7 @@ class Q_WIDGETS_EXPORT QGraphicsSceneMouseEvent : publ
 class Q_WIDGETS_EXPORT QGraphicsSceneMouseEvent : public QGraphicsSceneEvent
 {
 public:
-    explicit QGraphicsSceneMouseEvent(Type type = None);
+    explicit QGraphicsSceneMouseEvent(QEvent::Type type = QEvent::None);
     ~QGraphicsSceneMouseEvent();
 
     QPointF pos() const;
@@ -136,7 +136,7 @@ class Q_WIDGETS_EXPORT QGraphicsSceneWheelEvent : publ
 class Q_WIDGETS_EXPORT QGraphicsSceneWheelEvent : public QGraphicsSceneEvent
 {
 public:
-    explicit QGraphicsSceneWheelEvent(Type type = None);
+    explicit QGraphicsSceneWheelEvent(QEvent::Type type = QEvent::None);
     ~QGraphicsSceneWheelEvent();
 
     QPointF pos() const;
@@ -171,7 +171,7 @@ class Q_WIDGETS_EXPORT QGraphicsSceneContextMenuEvent 
 public:
     enum Reason { Mouse, Keyboard, Other };
 
-    explicit QGraphicsSceneContextMenuEvent(Type type = None);
+    explicit QGraphicsSceneContextMenuEvent(QEvent::Type type = QEvent::None);
     ~QGraphicsSceneContextMenuEvent();
 
     QPointF pos() const;
@@ -198,7 +198,7 @@ class Q_WIDGETS_EXPORT QGraphicsSceneHoverEvent : publ
 class Q_WIDGETS_EXPORT QGraphicsSceneHoverEvent : public QGraphicsSceneEvent
 {
 public:
-    explicit QGraphicsSceneHoverEvent(Type type = None);
+    explicit QGraphicsSceneHoverEvent(QEvent::Type type = QEvent::None);
     ~QGraphicsSceneHoverEvent();
 
     QPointF pos() const;
@@ -231,7 +231,7 @@ class Q_WIDGETS_EXPORT QGraphicsSceneHelpEvent : publi
 class Q_WIDGETS_EXPORT QGraphicsSceneHelpEvent : public QGraphicsSceneEvent
 {
 public:
-    explicit QGraphicsSceneHelpEvent(Type type = None);
+    explicit QGraphicsSceneHelpEvent(QEvent::Type type = QEvent::None);
     ~QGraphicsSceneHelpEvent();
 
     QPointF scenePos() const;
@@ -249,7 +249,7 @@ class Q_WIDGETS_EXPORT QGraphicsSceneDragDropEvent : p
 class Q_WIDGETS_EXPORT QGraphicsSceneDragDropEvent : public QGraphicsSceneEvent
 {
 public:
-    explicit QGraphicsSceneDragDropEvent(Type type = None);
+    explicit QGraphicsSceneDragDropEvent(QEvent::Type type = QEvent::None);
     ~QGraphicsSceneDragDropEvent();
 
     QPointF pos() const;
