--- src/theme.cpp.orig	2018-09-20 14:07:09 UTC
+++ src/theme.cpp
@@ -156,10 +156,11 @@ void MainDialog::on_install_theme_clicke
 }
 
 void MainDialog::on_theme_archive_clicked() {
-  QString filename = QFileDialog::getSaveFileName(this,
-                                                  tr("Choose an Openbox theme"),
-                                                  QString(),
-                                                  "Openbox theme archives (*.obt);;");
+    QFileDialog* dialog = new QFileDialog();
+    dialog->setFileMode(QFileDialog::Directory);
+    QString filename="";
+    if(dialog->exec())
+         filename= dialog->selectedFiles()[0];
   if(!filename.isEmpty()) {
     archive_create(filename.toLocal8Bit().constData());
   }
