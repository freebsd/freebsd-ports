--- xpra/scripts/server.py.orig	2026-10-05 07:38:32 UTC
+++ xpra/scripts/server.py
@@ -63,7 +63,7 @@ from xpra.platform.dotxpra import DotXpr
 DESKTOP_GREETER = envbool("XPRA_DESKTOP_GREETER", True)
 SHARED_XAUTHORITY = envbool("XPRA_SHARED_XAUTHORITY", True)
 PROGRESS_TO_STDERR = envbool("XPRA_PROGRESS_TO_STDERR", False)
-SYSTEM_DBUS_SOCKET = "/run/dbus/system_bus_socket"
+SYSTEM_DBUS_SOCKET = "/var/run/dbus/system_bus_socket"
 
 
 def get_logger():
@@ -532,16 +532,8 @@ def start_dbus() -> None:
     SYSTEM_DBUS = envbool("XPRA_SYSTEM_DBUS", ROOT)
     SYSTEM_DBUS_TIMEOUT = envint("XPRA_SYSTEM_DBUS_TIMEOUT", 5)
     if SYSTEM_DBUS and not wait_for_socket(SYSTEM_DBUS_SOCKET, SYSTEM_DBUS_TIMEOUT):
-        ensure_machine_id()
-        trymkdir("/run/dbus")
-        dbus_daemon = which("dbus-daemon")
-        if not dbus_daemon:
-            error("Error: unable to start the system dbus daemon")
-            error(" `dbus-daemon` command not found")
-            error(" install dbus, or use `XPRA_SYSTEM_DBUS=0` to skip it")
-            return
         try:
-            Popen([dbus_daemon, "--system", "--fork"]).wait()
+            Popen(["service", "dbus", "onestart"]).wait()
         except OSError as e:
             error("Error: failed to start the system dbus daemon")
             error(f" {e}")
