--- js/ui/sessionMode.js.orig	2014-02-19 20:54:46.000000000 +0000
+++ js/ui/sessionMode.js	2014-03-17 19:23:36.755386539 +0000
@@ -60,7 +60,7 @@
         isLocked: true,
         isGreeter: undefined,
         unlockDialog: undefined,
-        components: ['polkitAgent', 'telepathyClient'],
+        components: ['polkitAgent'],
         panel: {
             left: [],
             center: [],
@@ -72,7 +72,7 @@
     'unlock-dialog': {
         isLocked: true,
         unlockDialog: undefined,
-        components: ['polkitAgent', 'telepathyClient'],
+        components: ['polkitAgent'],
         panel: {
             left: [],
             center: [],
@@ -97,7 +97,7 @@
         components: Config.HAVE_NETWORKMANAGER ?
                     ['networkAgent', 'polkitAgent', 'telepathyClient',
                      'keyring', 'autorunManager', 'automountManager'] :
-                    ['polkitAgent', 'telepathyClient',
+                    ['polkitAgent',
                      'keyring', 'autorunManager', 'automountManager'],
 
         panel: {
