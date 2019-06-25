From 2233b6f998b2e8ca05761aaeefa59a77f3bf1b64
From: Kent Engstrom <kent@nsc.liu.se>
Date: Mon, 17 Jun 2019 11:15:17 +0200
Subject: [PATCH] Refix CTRL+SPACE behaviour on QT5.

As per discussion in Swordfish90/cool-retro-term issue #165, revert
later change back to the state after commit 490eeaf, "Fix CTRL+SPACE
behaviour on QT5."

--- qmltermwidget/lib/Vt102Emulation.cpp.orig
+++ qmltermwidget/lib/Vt102Emulation.cpp
@@ -1230,7 +1230,7 @@ void Vt102Emulation::sendKeyEvent( QKeyEvent* origEvent )
         }
         else if ( !entry.text().isEmpty() )
         {
-            textToSend += _codec->fromUnicode(QString::fromUtf8(entry.text(true,modifiers)));
+            textToSend += entry.text(true,modifiers);
         }
         else if((modifiers & Qt::ControlModifier) && event->key() >= 0x40 && event->key() < 0x5f) {
             textToSend += (event->key() & 0x1f);
