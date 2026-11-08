--- app/lib/app.ts.orig	2026-10-06 20:10:47 UTC
+++ app/lib/app.ts
@@ -68,7 +68,7 @@
             }
         })
 
-        if (process.platform === 'linux') {
+        if (['linux', 'freebsd'].includes(process.platform)) {
             app.commandLine.appendSwitch('no-sandbox')
             if ((this.configStore.appearance?.opacity || 1) !== 1) {
                 app.commandLine.appendSwitch('enable-transparent-visuals')
@@ -189,7 +189,7 @@
     }
 
     enableTray (): void {
-        if (!!this.tray || process.platform === 'linux' || (this.configStore.hideTray ?? false) === true) {
+        if (!!this.tray || ['linux', 'freebsd'].includes(process.platform) || (this.configStore.hideTray ?? false) === true) {
             return
         }
 
@@ -215,7 +215,7 @@
     }
 
     disableTray (): void {
-        if (process.platform === 'linux') {
+        if (['linux', 'freebsd'].includes(process.platform)) {
             return
         }
         this.tray?.destroy()
@@ -232,7 +232,7 @@
             return !hotkeyMode
         }
 
-        if (process.platform !== 'linux' || !this.isWaylandSession() || !this.isPlasmaSession()) {
+        if (!['linux', 'freebsd'].includes(process.platform) || !this.isWaylandSession() || !this.isPlasmaSession()) {
             return true
         }
 
