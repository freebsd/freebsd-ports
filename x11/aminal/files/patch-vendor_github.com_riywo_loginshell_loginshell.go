--- vendor/github.com/riywo/loginshell/loginshell.go.orig	2018-12-15 01:47:38 UTC
+++ vendor/github.com/riywo/loginshell/loginshell.go
@@ -15,6 +15,8 @@ func Shell() (string, error) {
     switch runtime.GOOS {
         case "linux":
           return LinuxShell()
+        case "freebsd":
+          return LinuxShell()
         case "darwin":
           return DarwinShell()
     }
