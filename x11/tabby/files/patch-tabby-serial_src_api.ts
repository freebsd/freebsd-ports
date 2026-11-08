--- tabby-serial/src/api.ts.orig	2026-10-06 20:10:47 UTC
+++ tabby-serial/src/api.ts
@@ -73,7 +73,11 @@
 
     async start (): Promise<void> {
         if (!this.profile.options.port) {
-            this.profile.options.port = (await this.serialService.listPorts())[0].name
+            const ports = await this.serialService.listPorts()
+            if (!ports.length) {
+                throw new Error('No serial ports found')
+            }
+            this.profile.options.port = ports[0].name
         }
 
         const serial = this.serial = new SerialPortStream({
