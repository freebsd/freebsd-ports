--- kdesu/su.cpp	2004/03/26 23:26:45	1.32.2.2
+++ kdesu/su.cpp	2004/04/13 13:32:27	1.32.2.3
@@ -78,9 +78,9 @@ int SuProcess::exec(const char *password
 	args += "root";
     else
 	args += m_User;
-    args += "-";
     args += "-c";
     args += QCString(__KDE_BINDIR) + "/kdesu_stub";
+    args += "-";
 
     QCString command = __PATH_SU;
     if (::access(__PATH_SU, X_OK) != 0)
