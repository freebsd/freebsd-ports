--- emain/emain-ipc.ts.orig	2026-02-11 23:55:44 UTC
+++ emain/emain-ipc.ts
@@ -337,7 +337,7 @@ export function initIpcHandlers() {
             const color = fac.prepareResult(fac.getColorFromArray4(png.data));
             const ww = getWaveWindowByWebContentsId(event.sender.id);
             ww.setTitleBarOverlay({
-                color: unamePlatform === "linux" ? color.rgba : "#00000000",
+                color: unamePlatform === "linux" || unamePlatform === "freebsd" ? color.rgba : "#00000000",
                 symbolColor: color.isDark ? "white" : "black",
             });
         } catch (e) {
