--- tabby-electron/src/shells/linuxDefault.ts.orig	2026-10-06 20:10:47 UTC
+++ tabby-electron/src/shells/linuxDefault.ts
@@ -38,7 +38,7 @@ export class LinuxDefaultShellProvider extends ShellP
                 id: 'default',
                 name: this.translate.instant('User default'),
                 command: line.split(':')[6],
-                args: ['--login'],
+                args: ['-l'],
                 hidden: true,
                 env: {},
                 shellType: 'unix',
