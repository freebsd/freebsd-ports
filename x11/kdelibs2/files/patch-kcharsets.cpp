diff -ur kdecore/kcharsets.cpp kdecore/kcharsets.cpp
--- kdecore/kcharsets.cpp	Tue Oct 24 19:57:36 2000
+++ kdecore/kcharsets.cpp	Tue Oct 24 20:10:19 2000
@@ -37,9 +37,9 @@
 template class QList<QFont::CharSet>;
 
 #if QT_VERSION > 220
-#define CHARSETS_COUNT 30
+#define CHARSETS_COUNT 32
 #else
-#define CHARSETS_COUNT 29
+#define CHARSETS_COUNT 32
 #endif
 
 static const char * const charsetsStr[CHARSETS_COUNT] = {
@@ -60,6 +60,9 @@
     "iso-8859-14",
     "iso-8859-15",
     "koi8r",
+    "koi8u",
+    "cp1251",
+    "pt154",
     "eucjp",
     "euckr",
     "set-th-th",
@@ -71,9 +74,6 @@
     "utf-8",
     "utf-16",
     "iso-8859-11",
-#if QT_VERSION > 220
-    "koi8u",
-#endif
     "Any"
 };
 
@@ -96,6 +96,9 @@
     "iso8859-14",
     "iso8859-15",
     "koi8-r",
+    "koi8-u",
+    "microsoft-cp1251",
+    "paratype-cp154",
     "jisx0208.1983-0",
     "ksc5601.1987-0",
     "tis620.2533-1",
@@ -107,9 +110,6 @@
     "utf8",
     "utf16",
     "tis620-*",
-#if QT_VERSION > 220
-    "koi8-u",
-#endif
     ""  // this will always return true...
 };
 
@@ -131,6 +131,9 @@
     QFont::ISO_8859_14,
     QFont::ISO_8859_15,
     QFont::KOI8R,
+    QFont::KOI8U,
+    QFont::CP_1251,
+    QFont::PT_154,
     QFont::Set_Ja,
     QFont::Set_Ko,
     QFont::Set_Th_TH,
@@ -142,9 +145,6 @@
     QFont::Unicode,
     QFont::Unicode,
     QFont::ISO_8859_11,
-#if QT_VERSION > 220
-    QFont::KOI8U,
-#endif
     QFont::AnyCharSet
 };
 
@@ -536,10 +536,12 @@
         return "iso8859-15";
     case QFont::KOI8R:
         return "koi8-r";
-#if QT_VERSION > 220
     case QFont::KOI8U:
         return "koi8-u";
-#endif
+    case QFont::CP_1251:
+        return "microsoft-cp1251";
+    case QFont::PT_154:
+        return "paratype-cp154";
     case QFont::Set_Ko:
         return "ksc5601.1987-0";
     case QFont::Set_Ja:
