--- kdecore/kcharsets.cpp.orig	Mon Oct 16 19:06:25 2000
+++ kdecore/kcharsets.cpp	Wed Nov 22 14:30:14 2000
@@ -66,7 +66,7 @@
     "set-gbk",
     "set-zh",
     "set-zh-tw",
-    "set-big5",
+    "big5",
     "tscii",
     "utf-8",
     "utf-16",
@@ -101,7 +101,7 @@
     "tis620.2533-1",
     "gb2312.1980-0",
     "gb2312.1980-0",
-	"big5-0",
+    "cns11643.1986-*",
     "big5-0",
     "tscii-0",
     "utf8",
@@ -136,8 +136,8 @@
     QFont::Set_Th_TH,
     QFont::Set_GBK,
     QFont::Set_Zh,
-    QFont::Set_Big5,
     QFont::Set_Zh_TW,
+    QFont::Set_Big5,
     QFont::TSCII,
     QFont::Unicode,
     QFont::Unicode,
@@ -552,6 +552,7 @@
 	case QFont::Set_Zh:
 	    return "set-gbk";
     case QFont::Set_Zh_TW:
+	return "cns11643.1986-*";
     case QFont::Set_Big5:
 	return "big5-0";
     case QFont::AnyCharSet:
