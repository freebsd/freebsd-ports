--- app/lib/sentry.ts.orig	2026-10-06 20:10:47 UTC
+++ app/lib/sentry.ts
@@ -8,7 +8,7 @@
     release = require('@electron/remote').app.getVersion()
 }
 
-if (!process.env.TABBY_DEV) {
+if (process.env.TABBY_CRASH_REPORTING && !process.env.TABBY_DEV) {
     init({
         dsn: SENTRY_DSN,
         release,
