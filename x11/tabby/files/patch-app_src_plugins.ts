--- app/src/plugins.ts.orig	2026-10-06 20:10:47 UTC
+++ app/src/plugins.ts
@@ -17,7 +17,7 @@ function normalizePath (p: string): string {
     return p
 }
 
-const builtinPluginsPath = process.env.TABBY_DEV ? path.dirname(remote.app.getAppPath()) : path.join((process as any).resourcesPath, 'builtin-plugins')
+const builtinPluginsPath = process.env.TABBY_DEV ? path.dirname(remote.app.getAppPath()) : process.env.TABBY_BUILTIN_PLUGINS ?? path.join((process as any).resourcesPath, 'builtin-plugins')
 
 const cachedBuiltinModules = {
     '@angular/animations': require('@angular/animations'),
