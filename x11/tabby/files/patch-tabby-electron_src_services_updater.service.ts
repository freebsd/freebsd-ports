--- tabby-electron/src/services/updater.service.ts.orig	2026-10-06 20:10:47 UTC
+++ tabby-electron/src/services/updater.service.ts
@@ -22,7 +22,7 @@ export class ElectronUpdaterService extends UpdaterSer
         super()
         this.logger = log.create('updater')
 
-        if (process.platform === 'linux' || process.env.PORTABLE_EXECUTABLE_FILE) {
+        if (['linux', 'freebsd'].includes(process.platform) || process.env.PORTABLE_EXECUTABLE_FILE) {
             this.electronUpdaterAvailable = false
             return
         }
