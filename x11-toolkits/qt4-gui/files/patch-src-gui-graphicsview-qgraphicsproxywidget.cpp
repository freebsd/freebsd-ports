--- src/gui/graphicsview/qgraphicsproxywidget.cpp
+++ src/gui/graphicsview/qgraphicsproxywidget.cpp
@@ -521,9 +521,8 @@
 {
     Q_D(QGraphicsProxyWidget);
     if (d->widget) {
-        QWidget *w = d->widget;
-        setWidget(0);
-        delete w;
+	QObject::disconnect(d->widget, SIGNAL(destroyed()), this, SLOT(_q_removeWidgetSlot()));
+       delete d->widget;
     }
 }
 

