--- kxkb/rules.cpp	(revision 504758)
+++ kxkb/rules.cpp	(working copy)
@@ -300,7 +300,7 @@
  */
 const QString KeyRules::getLayout(const QString &layvar) const
 {
-  static const char* LAYOUT_PATTERN = "[a-z0-9_-]*";
+  static const char* LAYOUT_PATTERN = "[a-zA-Z0-9_-]*";
   QString varLine = layvar.stripWhiteSpace();
   QRegExp rx(LAYOUT_PATTERN);
   int pos = rx.search(varLine, 0);
@@ -318,7 +318,7 @@
  */
 const QString KeyRules::getVariant(const QString &layvar) const
 {
-  static const char* VARIANT_PATTERN = "\\([a-z0-9_-]*\\)";
+  static const char* VARIANT_PATTERN = "\\([a-zA-Z0-9_-]*\\)";
   QString varLine = layvar.stripWhiteSpace();
   QRegExp rx(VARIANT_PATTERN);
   int pos = rx.search(varLine, 0);
