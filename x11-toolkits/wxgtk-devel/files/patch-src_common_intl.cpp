--- src/common/intl.cpp.orig	Sat Oct  4 23:10:24 2003
+++ src/common/intl.cpp	Sun Oct  5 21:35:30 2003
@@ -743,8 +742,18 @@
     }
     if ( !retloc )
     {
+        wxString langFull;
+        if (wxGetEnv(wxT("LC_ALL"), &langFull)|| 
+            wxGetEnv(wxT("LC_MESSAGES"), &langFull) ||
+            wxGetEnv(wxT("LANG"), &langFull))
+	{
+	    retloc = wxSetlocale(LC_ALL, langFull);
+	}
+    }
+    if ( !retloc )
+    {
         wxLogError(wxT("Cannot set locale to '%s'."), locale.c_str());
-        return FALSE;
+        //return FALSE;
     }
 #elif defined(__WIN32__)
 
