VirtualTerminal for Wayland is only present on Linux at the moment.
As we are only interested in an X11 session at the moment, we therefore
can hide it behind a Q_OS_LINUX.

--- src/daemon/Display.cpp.orig	2016-08-28 11:54:03 UTC
+++ src/daemon/Display.cpp
@@ -30,7 +30,9 @@
 #include "Greeter.h"
 #include "Utils.h"
 #include "SignalHandler.h"
+#if defined(Q_OS_LINUX)
 #include "VirtualTerminal.h"
+#endif
 
 #include <QDebug>
 #include <QFile>
@@ -280,8 +282,10 @@ namespace SDDM {
 
         // create new VT for Wayland sessions otherwise use greeter vt
         int vt = terminalId();
+#if defined(Q_OS_LINUX)
         if (session.xdgSessionType() == QLatin1String("wayland"))
             vt = VirtualTerminal::setUpNewVt();
+#endif
         m_lastSession.setVt(vt);
 
         QProcessEnvironment env;
@@ -321,9 +325,11 @@ namespace SDDM {
                 stateConfig.Last.Session.setDefault();
             stateConfig.save();
 
+#if defined(Q_OS_LINUX)
             // switch to the new VT for Wayland sessions
             if (m_lastSession.xdgSessionType() == QLatin1String("wayland"))
                 VirtualTerminal::jumpToVt(m_lastSession.vt());
+#endif
 
             if (m_socket)
                 emit loginSucceeded(m_socket);
