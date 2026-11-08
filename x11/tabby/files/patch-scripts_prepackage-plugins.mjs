--- scripts/prepackage-plugins.mjs.orig	2026-10-06 20:10:47 UTC
+++ scripts/prepackage-plugins.mjs
@@ -22,7 +22,7 @@ vars.builtinPlugins.forEach(plugin => {
     sh.cp('-r', path.join('..', plugin), '.')
     sh.rm('-rf', path.join(plugin, 'node_modules'))
     sh.cd(plugin)
-    sh.exec(`yarn install --force --production`, { fatal: true })
+    sh.exec(`yarn install --force --production --offline`, { fatal: true })
 
 
     log.info('rebuild', 'native')
