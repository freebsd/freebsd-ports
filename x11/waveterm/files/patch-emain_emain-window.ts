--- emain/emain-window.ts.orig	2026-02-11 23:55:44 UTC
+++ emain/emain-window.ts
@@ -172,7 +172,7 @@ export class WaveBrowserWindow extends BaseWindow {
             } else {
                 winOpts.backgroundColor = "#222222";
             }
-        } else if (opts.unamePlatform === "linux") {
+        } else if (opts.unamePlatform === "linux" || opts.unamePlatform === "freebsd") {
             winOpts.titleBarStyle = settings["window:nativetitlebar"] ? "default" : "hidden";
             winOpts.titleBarOverlay = {
                 symbolColor: "white",
