--- plugin-kbindicator/src/x11/kbdlayout.cpp.orig	2018-08-01 13:39:24 UTC
+++ plugin-kbindicator/src/x11/kbdlayout.cpp
@@ -245,10 +245,10 @@ private:
         static LangInfo def{"Unknown", "??", "None"};
         static QHash<QString, LangInfo> names;
         if (names.empty()){
-            if(QFile::exists("/usr/share/X11/xkb/rules/evdev.xml")){
+            if(QFile::exists("/usr/local/share/X11/xkb/rules/evdev.xml")){
                 QDomDocument doc;
 
-                QFile file("/usr/share/X11/xkb/rules/evdev.xml");
+                QFile file("/usr/local/share/X11/xkb/rules/evdev.xml");
                 if (file.open(QIODevice::ReadOnly)){
                     if (doc.setContent(&file)) {
                         QDomElement docElem = doc.documentElement();
