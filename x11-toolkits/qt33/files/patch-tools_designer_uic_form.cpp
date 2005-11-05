--- tools/designer/uic/form.cpp
+++ tools/designer/uic/form.cpp
@@ -731,6 +731,13 @@
             while ( !n2.isNull() ) {
                 if ( n2.tagName() == "includehint" ) {
                     QString file = n2.firstChild().toText().data();
+                    int colons = file.find("::");
+
+                    if (colons != -1)
+                    {
+                        file = file.right(file.length() - colons - 2);
+                    }
+
                     localIncludes += file;
                 }
                 n2 = n2.nextSibling().toElement();
