--- tabby-core/src/services/hotkeys.util.ts.orig	2026-10-06 20:10:47 UTC
+++ tabby-core/src/services/hotkeys.util.ts
@@ -3,12 +3,14 @@ export const metaKeyName = {
     darwin: '⌘',
     win32: 'Win',
     linux: 'Super',
+    freebsd: 'Super',
 }[process.platform]
 
 export const altKeyName = {
     darwin: '⌥',
     win32: 'Alt',
     linux: 'Alt',
+    freebsd: 'Alt',
 }[process.platform]
 
 export interface KeyEventData {
