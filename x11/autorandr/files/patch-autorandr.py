--- autorandr.py.orig	2024-03-03 12:37:50 UTC
+++ autorandr.py
@@ -150,6 +150,8 @@ def is_closed_lid(output):
 def is_closed_lid(output):
     if not re.match(r'(eDP(-?[0-9]\+)*|LVDS(-?[0-9]\+)*)', output):
         return False
+    print("Checking for a closed lid via /proc is not supported on FreeBSD.", file=sys.stderr)
+    return False
     lids = glob.glob("/proc/acpi/button/lid/*/state")
     if len(lids) == 1:
         state_file = lids[0]
@@ -1212,7 +1214,7 @@ def exec_scripts(profile_path, script_name, meta_infor
     if profile_path:
         candidate_directories.append(profile_path)
     candidate_directories.append(user_profile_path)
-    for config_dir in os.environ.get("XDG_CONFIG_DIRS", "/etc/xdg").split(":"):
+    for config_dir in os.environ.get("XDG_CONFIG_DIRS", "%%PREFIX%%/etc/xdg").split(":"):
         candidate_directories.append(os.path.join(config_dir, "autorandr"))
 
     for folder in candidate_directories:
@@ -1299,6 +1301,8 @@ def dispatch_call_to_sessions(argv):
     if 'AUTORANDR_UID_MIN' in os.environ:
       uid_min = int(os.environ['AUTORANDR_UID_MIN'])
 
+    print("/proc is not supported on FreeBSD; aborting.", file=sys.stderr)
+    sys.exit(1)
     for directory in os.listdir("/proc"):
         directory = os.path.join("/proc/", directory)
         if not os.path.isdir(directory):
@@ -1453,7 +1457,7 @@ def main(argv):
     try:
         # Load profiles from each XDG config directory
         # The XDG spec says that earlier entries should take precedence, so reverse the order
-        for directory in reversed(os.environ.get("XDG_CONFIG_DIRS", "/etc/xdg").split(":")):
+        for directory in reversed(os.environ.get("XDG_CONFIG_DIRS", "%%PREFIX%%/etc/xdg").split(":")):
             system_profile_path = os.path.join(directory, "autorandr")
             if os.path.isdir(system_profile_path):
                 profiles.update(load_profiles(system_profile_path))
