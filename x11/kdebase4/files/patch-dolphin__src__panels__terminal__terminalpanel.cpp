--- dolphin/src/panels/terminal/terminalpanel.cpp~	2011-02-26 00:33:12.000000000 +0200
+++ dolphin/src/panels/terminal/terminalpanel.cpp	2011-03-14 17:41:58.000000000 +0200
@@ -19,6 +19,8 @@
 
 #include "terminalpanel.h"
 
+#include <signal.h>
+
 #include <kpluginloader.h>
 #include <kpluginfactory.h>
 #include <kde_terminal_interface_v2.h>
@@ -111,16 +113,12 @@
 
 void TerminalPanel::sendCdToTerminal(const QString& dir)
 {
-    if (!m_clearTerminal) {
+    if (!m_clearTerminal)
         // The TerminalV2 interface does not provide a way to delete the
         // current line before sending a new input. This is mandatory,
         // otherwise sending a 'cd x' to a existing 'rm -rf *' might
-        // result in data loss. As workaround Ctrl+C is send.
-        QString cancel;
-        cancel.append(QChar(3));
-        cancel.append(QChar('c'));
-        m_terminal->sendInput(cancel);
-    }
+        // result in data loss. As workaround SIGINT is send.
+        ::kill(m_terminal->terminalProcessId(), SIGINT);
 
     m_terminal->sendInput("cd " + KShell::quoteArg(dir) + '\n');
 
