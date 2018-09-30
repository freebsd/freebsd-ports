$OpenBSD: patch-js_ui_screenShield_js,v 1.3 2017/11/04 16:44:50 jasper Exp $

REVERT:
From ddea54a5398c123a4711243e55811c8ba26f8b85 Mon Sep 17 00:00:00 2001
From: Victor Toso <victortoso@redhat.com>
Date: Thu, 12 May 2016 09:25:49 +0200
Subject: ScreenShield: set LockedHint property from systemd

Index: js/ui/screenShield.js
--- js/ui/screenShield.js.orig
+++ js/ui/screenShield.js
@@ -582,9 +582,6 @@ var ScreenShield = new Lang.Class({
         if (prevIsActive != this._isActive)
             this.emit('active-changed');
 
-        if (this._loginSession)
-            this._loginSession.SetLockedHintRemote(active);
-
         this._syncInhibitor();
     },
 
