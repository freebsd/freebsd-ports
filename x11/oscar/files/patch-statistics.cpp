--- statistics.cpp
+++ statistics.cpp
@@ -1315,7 +1315,7 @@ void Statistics::printReport(QWidget * parent) {
 
     QPrinter printer(QPrinter::ScreenResolution); // ScreenResolution required for graphics sizing
 
-#ifdef Q_OS_LINUX
+#if defined (Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     printer.setPrinterName("Print to File (PDF)");
     printer.setOutputFormat(QPrinter::PdfFormat);
     QString name = "Statistics";
