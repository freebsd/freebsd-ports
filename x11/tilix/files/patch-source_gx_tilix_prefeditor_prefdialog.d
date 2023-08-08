--- source/gx/tilix/prefeditor/prefdialog.d.orig	2023-04-22 04:00:09 UTC
+++ source/gx/tilix/prefeditor/prefdialog.d
@@ -957,7 +957,7 @@ class ShortcutPreferences : Box { (private)
             return;
         }
 
-        import std.xml: DocumentParser, ElementParser, Element, XMLException;
+        import undead.xml: DocumentParser, ElementParser, Element, XMLException;
 
         try {
             DocumentParser parser = new DocumentParser(ui);
