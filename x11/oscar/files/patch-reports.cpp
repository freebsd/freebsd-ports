--- reports.cpp.orig	2026-10-31 09:48:51 UTC
+++ reports.cpp
@@ -73,7 +73,7 @@ void Report::PrintReport(gGraphView *gv, QString name,
 
     printer = new QPrinter(QPrinter::HighResolution);
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QString username = p_profile->Get(QString("_{") + QString(STR_UI_UserName) + "}_");
     printer->setPrinterName("Print to File (PDF)");
     printer->setOutputFormat(QPrinter::PdfFormat);
