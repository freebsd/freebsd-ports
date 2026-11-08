--- app/lib/window.ts.orig	2026-10-06 20:10:47 UTC
+++ app/lib/window.ts
@@ -208,7 +208,7 @@
                     console.error('Failed to set window blur', error)
                 }
             }
-        } else if (process.platform === 'linux') {
+        } else if (['linux', 'freebsd'].includes(process.platform)) {
             this.window.setBackgroundColor(enabled ? '#00000000' : '#131d27')
             this.window.setBlur?.(enabled)
         } else {
