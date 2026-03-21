--- emain/emain-window.ts.orig	2026-03-03 23:22:35 UTC
+++ emain/emain-window.ts
@@ -174,7 +174,7 @@ export class WaveBrowserWindow extends BaseWindow {
             } else {
                 winOpts.backgroundColor = "#222222";
             }
-        } else if (opts.unamePlatform === "linux") {
+        } else if (opts.unamePlatform === "linux" || opts.unamePlatform === "freebsd") {
             winOpts.titleBarStyle = settings["window:nativetitlebar"] ? "default" : "hidden";
             winOpts.titleBarOverlay = {
                 symbolColor: "white",
