--- kdoctools/xslt.cpp	Mon Jul 30 17:11:20 2001
+++ kdoctools/xslt.cpp.new	Tue Aug 28 20:09:34 2001
@@ -86,9 +86,7 @@
     INFO(i18n("Reading document"));
     QFile xmlFile( pat );
     xmlFile.open(IO_ReadOnly);
-    QCString contents;
-    contents.assign(xmlFile.readAll());
-    contents.truncate(xmlFile.size());
+    QCString contents(xmlFile.readAll(), xmlFile.size() + 1);
     xmlFile.close();
     /* if (contents.left(5) != "<?xml") {
         fprintf(stderr, "xmlizer\n");
