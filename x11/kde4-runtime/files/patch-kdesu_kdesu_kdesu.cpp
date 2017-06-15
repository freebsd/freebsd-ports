Fix for https://www.kde.org/info/security/advisory-20160930-1.txt
--- kdesu/kdesu/kdesu.cpp.orig	2014-10-30 23:50:20 UTC
+++ kdesu/kdesu/kdesu.cpp
@@ -141,6 +141,10 @@ int main(int argc, char *argv[])
     {
         KMessageBox::sorry(0, i18n("Cannot execute command '%1'.", QString::fromLocal8Bit(command)));
     }
+    if (result == -2)
+    {
+        KMessageBox::sorry(0, i18n("Cannot execute command '%1'. It contains invalid characters.", QString::fromLocal8Bit(command)));
+    }
 
     return result;
 }
@@ -367,6 +371,12 @@ static int startApp()
         kDebug() << "Don't need password!!\n";
     }
 
+    for (const QChar character : QString::fromLocal8Bit(command)) {
+        if (!character.isPrint() && character.category() != QChar::Other_Surrogate) {
+            return -2;
+        }
+    }
+
     // Start the dialog
     QString password;
     if (needpw)
