--- xpra/scripts/server.py.orig	2026-02-01 15:10:38 UTC
+++ xpra/scripts/server.py
@@ -58,7 +58,7 @@ PROGRESS_TO_STDERR = envbool("XPRA_PROGRESS_TO_STDERR"
 DESKTOP_GREETER = envbool("XPRA_DESKTOP_GREETER", True)
 SHARED_XAUTHORITY = envbool("XPRA_SHARED_XAUTHORITY", True)
 PROGRESS_TO_STDERR = envbool("XPRA_PROGRESS_TO_STDERR", False)
-SYSTEM_DBUS_SOCKET = "/run/dbus/system_bus_socket"
+SYSTEM_DBUS_SOCKET = "/var/run/dbus/system_bus_socket"
 
 
 def get_logger():
@@ -609,19 +609,7 @@ def start_dbus() -> None:
     SYSTEM_DBUS_TIMEOUT = envint("XPRA_SYSTEM_DBUS_TIMEOUT", 5)
     MACHINE_ID: Final[str] = "/var/lib/dbus/machine-id"
     if SYSTEM_DBUS and not wait_for_socket(SYSTEM_DBUS_SOCKET, SYSTEM_DBUS_TIMEOUT):
-        if not os.path.exists(MACHINE_ID):
-            try:
-                trymkdir("/var/lib")
-                trymkdir("/var/lib/dbus")
-                import uuid
-                machine_id = uuid.uuid4().hex
-                with open(MACHINE_ID, "w") as f:
-                    f.write(machine_id)
-                warn(f"initialized dbus machine_id {machine_id}\n")
-            except OSError as e:
-                warn(f"unable to create machine_id: {e}\n")
-        trymkdir("/run/dbus")
-        Popen(["dbus-daemon", "--system", "--fork"]).wait()
+        Popen(["service", "dbus", "onestart"]).wait()
         if not wait_for_socket(SYSTEM_DBUS_SOCKET, SYSTEM_DBUS_TIMEOUT):
             warn("dbus-daemon failed to start\n")
         else:
