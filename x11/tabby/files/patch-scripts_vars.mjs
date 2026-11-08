--- scripts/vars.mjs.orig	2026-10-06 20:10:47 UTC
+++ scripts/vars.mjs
@@ -10,9 +10,7 @@ const electronInfo = JSON.parse(fs.readFileSync(path.r
 
 const electronInfo = JSON.parse(fs.readFileSync(path.resolve(__dirname, '../node_modules/electron/package.json')))
 
-export let version = childProcess.execSync('git describe --tags', { encoding:'utf-8' })
-version = version.substring(1).trim()
-version = version.replace('-', '-c')
+export let version = process.env.TABBY_VERSION
 
 if (version.includes('-c')) {
     version = semver.inc(version, 'prepatch').replace('-0', `-nightly.${process.env.REV ?? 0}`)
@@ -73,7 +71,7 @@ export const keygenConfig = {
             armv7l: '50ae0a82-7f47-4fa4-b0a8-b0d575ce9409',
             armhf: '7df5aa12-04ab-4075-a0fe-93b0bbea9643',
         }[process.env.ARCH],
-    }[process.platform],
+    }[process.platform === 'freebsd' ? 'linux' : process.platform],
 }
 
 if (!keygenConfig.product) {
