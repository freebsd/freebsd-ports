--- reports.cpp
+++ reports.cpp
@@ -74,7 +74,7 @@ void Report::PrintReport(gGraphView *gv, QString name, QDate date)
 
     printer = new QPrinter(QPrinter::HighResolution);
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QString username = p_profile->Get(QString("_{") + QString(STR_UI_UserName) + "}_");
     printer->setPrinterName("Print to File (PDF)");
     printer->setOutputFormat(QPrinter::PdfFormat);
