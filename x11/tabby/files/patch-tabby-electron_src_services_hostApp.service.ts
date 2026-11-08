--- tabby-electron/src/services/hostApp.service.ts.orig	2026-10-06 20:10:47 UTC
+++ tabby-electron/src/services/hostApp.service.ts
@@ -14,6 +14,7 @@ export class ElectronHostAppService extends HostAppSer
             win32: Platform.Windows,
             darwin: Platform.macOS,
             linux: Platform.Linux,
+            freebsd: Platform.Linux,
         }[process.platform]
     }
 
