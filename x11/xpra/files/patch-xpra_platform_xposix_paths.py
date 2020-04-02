--- xpra/platform/xposix/paths.py.orig	2019-09-24 13:54:00 UTC
+++ xpra/platform/xposix/paths.py
@@ -177,12 +177,12 @@ def do_get_default_log_dirs():
 def do_get_sound_command():
     from xpra.platform.paths import get_xpra_command
     if SOUND_PYTHON3:
-        return ["python3"]+get_xpra_command()
+        return ["python%i.%i" % (sys.version_info.major, sys.version_info.minor)]+get_xpra_command()
     return get_xpra_command()
 
 def do_get_xpra_command():
     #try to use the same "xpra" executable that launched this server,
     #whilst also preserving the python interpreter version:
     if sys.argv and sys.argv[0].lower().endswith("/xpra"):
-        return ["python%i" % sys.version_info[0], sys.argv[0]]
+        return ["python%i.%i" % (sys.version_info.major, sys.version_info.minor), sys.argv[0]]
     return ["xpra"]
