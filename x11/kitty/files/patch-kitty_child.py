--- kitty/child.py.orig	2021-11-10 21:33:51 UTC
+++ kitty/child.py
@@ -45,7 +45,7 @@ else:
             return list(filter(None, f.read().decode('utf-8').split('\0')))
 
     def cwd_of_process(pid: int) -> str:
-        ans = '/proc/{}/cwd'.format(pid)
+        ans = subprocess.run(["pwdx", pid], capture_output=True).stdout.split()[1].decode("utf-8")
         return os.path.realpath(ans)
 
     def _environ_of_process(pid: int) -> str:
