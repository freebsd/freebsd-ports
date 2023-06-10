Add explicit <triple> subdir for --target from USES=cargo

--- cargo_build.py.orig	2021-09-10 16:56:00 UTC
+++ cargo_build.py
@@ -6,6 +6,7 @@ instead of the source tree.
 """
 
 from pathlib import Path
+import os
 import shlex
 import subprocess
 import sys
@@ -43,7 +44,7 @@ if out_path:
     out_basename = out_path.name
     filename = filename or out_basename
     subprocess.run(['cp', '-a',
-        './{}/{}'.format(binary_dir, filename),
+        os.path.join('.', os.getenv('CARGO_BUILD_TARGET', ''), binary_dir, filename),
         out_path],
         check=True)
 
