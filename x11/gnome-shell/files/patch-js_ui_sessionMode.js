--- js/ui/sessionMode.js.orig	2013-04-28 19:50:35.808911032 +0000
+++ js/ui/sessionMode.js	2013-04-28 19:51:07.527210205 +0000
@@ -50,7 +50,7 @@
         isLocked: true,
         isGreeter: undefined,
         unlockDialog: undefined,
-        components: ['polkitAgent', 'telepathyClient'],
+        components: ['polkitAgent'],
         panel: {
             left: ['userMenu'],
             center: [],
@@ -61,7 +61,7 @@
     'unlock-dialog': {
         isLocked: true,
         unlockDialog: undefined,
-        components: ['polkitAgent', 'telepathyClient'],
+        components: ['polkitAgent'],
         panel: {
             left: ['userMenu'],
             center: [],
@@ -91,13 +91,13 @@
         isLocked: false,
         isPrimary: true,
         unlockDialog: imports.ui.unlockDialog.UnlockDialog,
-        components: ['networkAgent', 'polkitAgent', 'telepathyClient',
+        components: ['polkitAgent',
                      'keyring', 'recorder', 'autorunManager', 'automountManager'],
         panel: {
             left: ['activities', 'appMenu'],
             center: ['dateMenu'],
             right: ['a11y', 'keyboard', 'volume', 'bluetooth',
-                    'network', 'battery', 'userMenu']
+                    'battery', 'userMenu']
         }
     }
 };
