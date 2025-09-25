--- waypaper/changer.py.orig	2025-02-28 01:09:43 UTC
+++ waypaper/changer.py
@@ -138,9 +138,15 @@ def change_with_swww(image_path: Path, cf: Config, mon
         subprocess.Popen(["swww-daemon"])
         print("Launched swww-daemon")
 
+    version_p = subprocess.run(["swww", "-V"], capture_output=True, text=True)
+    swww_version = [int(x) for x in version_p.stdout.strip().split(" ")[1].split(".")]
+
     command = ["swww", "img", image_path]
     command.extend(["--resize", fill])
-    command.extend(["--fill-color", cf.color])
+    if swww_version >= [0, 11, 0]:
+        command.extend(["--fill-color", cf.color.lstrip("#")])
+    else:
+        command.extend(["--fill-color", cf.color])
     command.extend(["--transition-type", cf.swww_transition_type])
     command.extend(["--transition-step", str(cf.swww_transition_step)])
     command.extend(["--transition-angle", str(cf.swww_transition_angle)])
