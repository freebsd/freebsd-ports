--- src/helper/backend/PamBackend.cpp.orig	2025-01-31 09:57:01 UTC
+++ src/helper/backend/PamBackend.cpp
@@ -240,6 +240,9 @@ namespace SDDM {
             m_app->error(m_pam->errorString(), Auth::ERROR_AUTHENTICATION);
             return false;
         }
+        QProcessEnvironment sessionEnv = m_app->session()->processEnvironment();
+        sessionEnv.insert(m_pam->getEnv());
+        m_app->session()->setProcessEnvironment(sessionEnv);
         return true;
     }
 
