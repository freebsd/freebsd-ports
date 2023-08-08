--- src/terminalprovider.cpp.orig	2023-02-05 13:24:46 UTC
+++ src/terminalprovider.cpp
@@ -32,7 +32,7 @@ static QString userShell()
 }
 
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 
 struct ExecutableTerminal : public Terminal
