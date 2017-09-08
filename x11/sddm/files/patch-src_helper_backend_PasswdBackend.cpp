Implement password authentication on FreeBSD.
This needs review :)

--- src/helper/backend/PasswdBackend.cpp.orig	2016-07-06 14:00:10 UTC
+++ src/helper/backend/PasswdBackend.cpp
@@ -27,8 +27,13 @@
 
 #include <sys/types.h>
 #include <pwd.h>
+#if defined(Q_OS_LINUX)
 #include <shadow.h>
 #include <crypt.h>
+#endif
+#if defined(Q_OS_FREEBSD)
+#include <unistd.h>
+#endif
 
 namespace SDDM {
     PasswdBackend::PasswdBackend(HelperApp *parent)
@@ -72,6 +77,17 @@ namespace SDDM {
             return false;
         }
 
+#if defined(Q_OS_FREEBSD)
+        if (!*pw->pw_passwd)
+        {
+            //empty password
+            return true;
+        }
+        char *crypted = crypt(qPrintable(password), pw->pw_passwd);
+        if (0 == strcmp(crypted, pw->pw_passwd)) {
+            return true;
+        }
+#else
         struct spwd *spw = getspnam(pw->pw_name);
         if (!spw) {
             qWarning() << "[Passwd] Could get passwd but not shadow";
@@ -85,7 +101,7 @@ namespace SDDM {
         if (0 == strcmp(crypted, spw->sp_pwdp)) {
             return true;
         }
-
+#endif
         m_app->error(QStringLiteral("Wrong user/password combination"), Auth::ERROR_AUTHENTICATION);
         return false;
     }
