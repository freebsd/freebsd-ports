--- app/node_modules/russh/lib/native.js.orig	2026-11-07 14:58:12 UTC
+++ app/node_modules/russh/lib/native.js
@@ -13,6 +13,10 @@ const nativeModule = process.env.RUST_TARGET_TRIPLE ||
         x64: 'linux-x64-gnu',
         arm: 'linux-arm-gnueabihf',
         arm64: 'linux-arm64-gnu'
+    },
+    freebsd: {
+        x64: 'freebsd-x64',
+        arm64: 'freebsd-arm64'
     }
 }[process.platform][process.arch]
 
