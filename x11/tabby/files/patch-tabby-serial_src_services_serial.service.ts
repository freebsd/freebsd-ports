--- tabby-serial/src/services/serial.service.ts.orig	2026-10-06 20:10:47 UTC
+++ tabby-serial/src/services/serial.service.ts
@@ -1,4 +1,5 @@
 import { Injectable } from '@angular/core'
+import * as fs from 'fs/promises'
 import WSABinding from 'serialport-binding-webserialapi'
 import AbstractBinding from '@serialport/binding-abstract'
 import { autoDetect } from '@serialport/bindings-cpp'
@@ -16,6 +17,17 @@
     }
 
     async listPorts (): Promise<SerialPortInfo[]> {
+        if (process.platform === 'freebsd') {
+            try {
+                return (await fs.readdir('/dev'))
+                    .filter(x => /^cua[a-zA-Z]+[0-9]+$/.test(x))
+                    .sort()
+                    .map(x => ({ name: `/dev/${x}` }))
+            } catch (err) {
+                console.error('Failed to list serial ports', err)
+                return []
+            }
+        }
         try {
             return (await this.detectBinding().list()).map(x => ({
                 name: x.path,
