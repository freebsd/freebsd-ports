Run sddm-greeter via the session command (Xsession script) so it also gets X
resources and a ConsoleKit and D-Bus session.  The ConsoleKit session has its
session-class set to "user" instead of "greeter" because ck-launch-session
doesn't provide a way to change this.  ConsoleKit doesn't do anything with
this value though so it is believed to be harmless.  The XDG_SESSION_CLASS
environment variable does have the value "greeter".

Remove double quotes because we fixed the use of "$@" in the script.

--- src/helper/UserSession.cpp.orig	2017-12-05 16:00:16 UTC
+++ src/helper/UserSession.cpp
@@ -45,10 +45,8 @@ namespace SDDM {
     bool UserSession::start() {
         QProcessEnvironment env = qobject_cast<HelperApp*>(parent())->session()->processEnvironment();
 
-        if (env.value(QStringLiteral("XDG_SESSION_CLASS")) == QLatin1String("greeter")) {
-            QProcess::start(m_path);
-        } else if (env.value(QStringLiteral("XDG_SESSION_TYPE")) == QLatin1String("x11")) {
-            const QString cmd = QStringLiteral("%1 \"%2\"").arg(mainConfig.X11.SessionCommand.get()).arg(m_path);
+        if (env.value(QStringLiteral("XDG_SESSION_TYPE")) == QLatin1String("x11")) {
+            const QString cmd = QStringLiteral("%1 %2").arg(mainConfig.X11.SessionCommand.get()).arg(m_path);
             qInfo() << "Starting:" << cmd;
             QProcess::start(cmd);
         } else if (env.value(QStringLiteral("XDG_SESSION_TYPE")) == QLatin1String("wayland")) {
