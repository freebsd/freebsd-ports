--- kio/kfile/kopenwithdialog.cpp.orig	2018-08-26 09:15:08 UTC
+++ kio/kfile/kopenwithdialog.cpp
@@ -713,7 +713,7 @@ void KOpenWithDialog::slotHighlighted(const QString& e
         // ### indicate that default value was restored
         d->terminal->setChecked(d->curService->terminal());
         QString terminalOptions = d->curService->terminalOptions();
-        d->nocloseonexit->setChecked((terminalOptions.contains(QLatin1String("--noclose")) > 0));
+        d->nocloseonexit->setChecked(bool(terminalOptions.contains(QLatin1String("--noclose"))));
         d->m_terminaldirty = false; // slotTerminalToggled changed it
     }
 }
