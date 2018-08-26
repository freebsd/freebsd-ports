--- kio/kfile/kpropertiesdialog.cpp.orig	2018-08-26 08:56:17 UTC
+++ kio/kfile/kpropertiesdialog.cpp
@@ -3306,7 +3306,7 @@ void KDesktopPropsPlugin::slotAdvanced()
 
     if (preferredTerminal == "konsole")
     {
-        terminalCloseBool = (d->m_terminalOptionStr.contains( "--noclose" ) > 0);
+        terminalCloseBool = bool(d->m_terminalOptionStr.contains( "--noclose" ));
         w.terminalCloseCheck->setChecked(terminalCloseBool);
         d->m_terminalOptionStr.remove( "--noclose");
     }
