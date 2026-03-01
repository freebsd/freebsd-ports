--- emain/emain-builder.ts.orig	2025-12-22 08:36:57 UTC
+++ emain/emain-builder.ts
@@ -59,7 +59,7 @@ export async function createBuilderWindow(appId: strin
         minHeight: MinWindowHeight,
         titleBarStyle: unamePlatform === "darwin" ? "hiddenInset" : "default",
         icon:
-            unamePlatform === "linux"
+            unamePlatform === "linux" || unamePlatform === "freebsd"
                 ? path.join(getElectronAppBasePath(), "public/logos/wave-logo-dark.png")
                 : undefined,
         show: false,
