--- kdoctools/xml2man.cpp	Sat Jul 28 23:55:05 2001
+++ kdoctools/xml2man.cpp.new	Wed Aug 29 18:10:54 2001
@@ -63,9 +63,7 @@
     QString pat = args->arg( 0 );
     QFile xmlFile( pat );
     xmlFile.open(IO_ReadOnly);
-    QCString contents;
-    contents.assign(xmlFile.readAll());
-    contents.truncate(xmlFile.size());
+    QCString contents(xmlFile.readAll(), xmlFile.size() + 1);
     xmlFile.close();
 
     contents.replace( QRegExp( "<!--[^-]*-->" ), "" );
