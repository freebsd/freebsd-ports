--- src/helper/Backend.cpp.orig	2019-03-13 09:22:35 UTC
+++ src/helper/Backend.cpp
@@ -29,6 +29,10 @@
 #include <QtCore/QProcessEnvironment>
 
 #include <pwd.h>
+#if defined(Q_OS_FREEBSD)
+#include <sys/types.h>
+#include <login_cap.h>
+#endif /* defined(Q_OS_FREEBSD) */
 
 namespace SDDM {
     Backend::Backend(HelperApp* parent)
@@ -70,6 +74,34 @@ namespace SDDM {
                         .arg(mainConfig.X11.UserAuthFile.get());
                 env.insert(QStringLiteral("XAUTHORITY"), value);
             }
+#if defined(Q_OS_FREEBSD)
+	    /* get additional environment variables via setclassenvironment();
+	       this needs to be done here instead of in UserSession::setupChildProcess
+	       as the environment for execve() is prepared here;
+	       save and restore SDDM's environment because setclassenvironment() mangles it */
+	    login_cap_t *lc;
+
+        auto savedEnv = QProcessEnvironment::systemEnvironment();
+
+	    if ((lc = login_getpwclass(pw)) != NULL) {
+		setclassenvironment(lc, pw, 1);		/* path variables */
+		setclassenvironment(lc, pw, 0);		/* non-path variables */
+		login_close(lc);
+	    }
+	    if ((lc = login_getuserclass(pw)) != NULL) {
+		setclassenvironment(lc, pw, 1);		/* path variables */
+		setclassenvironment(lc, pw, 0);		/* non-path variables */
+		login_close(lc);
+	    }
+		/* copy all environment variables that are now set */
+        QString savedLang = env.value(QStringLiteral("LANG"));
+		env.insert(QProcessEnvironment::systemEnvironment());
+        if (qobject_cast<HelperApp*>(parent())->user() == QStringLiteral("sddm"))
+            env.insert(QStringLiteral("LANG"), savedLang);
+        /* restore original environment */
+        QProcessEnvironment::systemEnvironment().clear();
+        QProcessEnvironment::systemEnvironment().insert(savedEnv);
+#endif /* defined(Q_OS_FREEBSD) */
             // TODO: I'm fairly sure this shouldn't be done for PAM sessions, investigate!
             m_app->session()->setProcessEnvironment(env);
         }
