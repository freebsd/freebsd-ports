--- widgets/Dashboard.cpp.orig	2018-10-08 07:20:46 UTC
+++ widgets/Dashboard.cpp
@@ -62,7 +62,7 @@ void Dashboard::updateContents()
         this->ui->relroEdit->setText(relro);
     }
 
-    this->ui->baddrEdit->setText("0x" + QString::number(Core()->get_baddr(), 16));
+    this->ui->baddrEdit->setText(RAddressString(item2["baddr"].toVariant().toULongLong()));
 
     if (item2["va"].toBool() == true) {
         this->ui->vaEdit->setText("True");
