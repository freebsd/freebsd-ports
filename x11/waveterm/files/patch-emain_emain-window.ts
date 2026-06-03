--- emain/emain-window.ts.orig	2026-04-16 15:33:19 UTC
+++ emain/emain-window.ts
@@ -183,7 +183,7 @@ export class WaveBrowserWindow extends BaseWindow {
             } else {
                 winOpts.backgroundColor = "#222222";
             }
-        } else if (opts.unamePlatform === "linux") {
+        } else if (opts.unamePlatform === "linux" || opts.unamePlatform === "freebsd") {
             winOpts.titleBarStyle = settings["window:nativetitlebar"] ? "default" : "hidden";
             winOpts.titleBarOverlay = {
                 symbolColor: "white",
