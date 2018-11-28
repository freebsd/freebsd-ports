--- widgets/SidebarWidget.cpp.orig	2018-10-08 07:20:46 UTC
+++ widgets/SidebarWidget.cpp
@@ -188,10 +188,13 @@ void SidebarWidget::fillOffsetInfo(QString off)
     .set("scr.color", COLOR_MODE_DISABLED);
 
     ui->offsetTreeWidget->clear();
-    QString raw = Core()->getOffsetInfo(off);
+    QString raw = Core()->cmd(QString("ao@") + off).trimmed();
     QList<QString> lines = raw.split("\n", QString::SkipEmptyParts);
     for (QString line : lines) {
         QList<QString> eles = line.split(":", QString::SkipEmptyParts);
+        if (eles.length() < 2) {
+            continue;
+        }
         QTreeWidgetItem *tempItem = new QTreeWidgetItem();
         tempItem->setText(0, eles.at(0).toUpper());
         tempItem->setText(1, eles.at(1));
