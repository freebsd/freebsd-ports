--- src/platform/xdg/desktopentryparser.cpp.orig	2025-07-13 18:27:36 UTC
+++ src/platform/xdg/desktopentryparser.cpp
@@ -7,6 +7,11 @@ using namespace std;
 using namespace albert::detail;
 using namespace std;
 
+#if defined(__FreeBSD__)
+#    include <libintl.h>
+#    define dgettext(package, str) gettext(str)
+#endif
+
 DesktopEntryParser::DesktopEntryParser(const QString &path)
 {
     if (QFile file(path); file.open(QIODevice::ReadOnly| QIODevice::Text))
