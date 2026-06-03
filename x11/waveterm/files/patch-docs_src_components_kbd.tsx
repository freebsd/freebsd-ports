--- docs/src/components/kbd.tsx.orig	2025-12-17 04:59:41 UTC
+++ docs/src/components/kbd.tsx
@@ -44,7 +44,7 @@ function convertKey(platform: Platform, key: string): 
 }
 
 // Custom KBD component
-const KbdInternal = ({ k, windows, mac, linux }: { k: string; windows?: string; mac?: string; linux?: string }) => {
+const KbdInternal = ({ k, windows, mac, linux, freebsd }: { k: string; windows?: string; mac?: string; linux?: string; freebsd?: string }) => {
     const { platform } = useContext(PlatformContext);
 
     // Determine which key binding to use based on platform overrides
@@ -55,6 +55,8 @@ const KbdInternal = ({ k, windows, mac, linux }: { k: 
         keyBinding = mac;
     } else if (platform === "linux" && linux) {
         keyBinding = linux;
+    } else if (platform === "freebsd" && freebsd) {
+        keyBinding = linux;
     }
 
     if (keyBinding == "N/A") {
@@ -73,10 +75,10 @@ const KbdInternal = ({ k, windows, mac, linux }: { k: 
     return <div className="kbd-group">{keyElems}</div>;
 };
 
-export const Kbd = ({ k, windows, mac, linux }: { k: string; windows?: string; mac?: string; linux?: string }) => {
+export const Kbd = ({ k, windows, mac, linux, freebsd }: { k: string; windows?: string; mac?: string; linux?: string; freebsd?: string }) => {
     return (
         <BrowserOnly fallback={<kbd>{k}</kbd>}>
-            {() => <KbdInternal k={k} windows={windows} mac={mac} linux={linux} />}
+            {() => <KbdInternal k={k} windows={windows} mac={mac} linux={linux} freebsd={freebsd} />}
         </BrowserOnly>
     );
 };
