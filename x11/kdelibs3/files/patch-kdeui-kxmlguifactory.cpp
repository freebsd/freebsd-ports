Index: kxmlguifactory.cpp
===================================================================
RCS file: /home/kde/kdelibs/kdeui/kxmlguifactory.cpp,v
retrieving revision 1.149
retrieving revision 1.151
diff -u -3 -p -r1.149 -r1.151
--- kxmlguifactory.cpp	19 Jun 2004 21:35:02 -0000	1.149
+++ kdeui/kxmlguifactory.cpp	22 Jun 2004 15:56:16 -0000	1.151
@@ -124,7 +124,14 @@ QString KXMLGUIFactory::readConfigFile( 
             return QString::null;
     }
 
+#if QT_VERSION <= 0x030302
+    // Work around bug in QString::fromUtf8 (which calls strlen).
+    QByteArray buffer(file.size() + 1);
+    buffer = file.readAll();
+    buffer[ buffer.size() - 1 ] = '\0';
+#else
     QByteArray buffer(file.readAll());
+#endif
     return QString::fromUtf8(buffer.data(), buffer.size());
 }
 
