--- emain/emain-ipc.ts.orig	2026-04-16 15:33:19 UTC
+++ emain/emain-ipc.ts
@@ -363,7 +363,7 @@ export function initIpcHandlers() {
             const ww = getWaveWindowByWebContentsId(event.sender.id);
             if (ww == null) return;
             ww.setTitleBarOverlay({
-                color: unamePlatform === "linux" ? color.rgba : "#00000000",
+                color: unamePlatform === "linux" || unamePlatform === "freebsd" ? color.rgba : "#00000000",
                 symbolColor: color.isDark ? "white" : "black",
             });
         } catch (e) {
