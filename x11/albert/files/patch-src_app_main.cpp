--- src/app/main.cpp.orig	2018-12-31 18:07:36 UTC
+++ src/app/main.cpp
@@ -296,15 +296,21 @@ int main(int argc, char **argv) {
         if ( parser.isSet("plugin-dirs") )
             pluginDirs = parser.value("plugin-dirs").split(',');
         else {
-#if defined __linux__
+#if defined __linux__ || defined __FreeBSD__
             QStringList dirs = {
 #if defined MULTIARCH_TUPLE
                 QFileInfo("/usr/lib/" MULTIARCH_TUPLE).canonicalFilePath(),
 #endif
+#if defined __linux__
                 QFileInfo("/usr/lib/").canonicalFilePath(),
                 QFileInfo("/usr/lib64/").canonicalFilePath(),
                 QFileInfo("/usr/local/lib/").canonicalFilePath(),
                 QFileInfo("/usr/local/lib64/").canonicalFilePath(),
+#endif
+#if defined __FreeBSD__
+                QFileInfo("/usr/lib/").canonicalFilePath(),
+                QFileInfo("/usr/local/lib/").canonicalFilePath(),
+#endif
                 QDir::home().filePath(".local/lib/"),
                 QDir::home().filePath(".local/lib64/")
             };
