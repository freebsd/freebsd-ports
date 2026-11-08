Description: has_server() probed xpra.server.util, which no longer exists,
  so it always returned False and the launcher's Start button tooltip
  read "Start a new remote xpra session" even with the server installed.
  Look for xpra.server.core instead, without importing it.
Issue ID: https://github.com/Xpra-org/xpra/pull/5100
Changeset: none (the v6.5.x branch and master still probe xpra.server.util)
TODO: Drop once a release includes it.

--- xpra/gtk/dialogs/gui.py.orig	2026-09-27 11:24:27 UTC
+++ xpra/gtk/dialogs/gui.py
@@ -31,9 +31,10 @@ def has_mdns() -> bool:
 
 
 def has_server() -> bool:
+    # xpra.server.util no longer exists: look for the server package itself
+    from importlib.util import find_spec
     try:
-        from xpra.server import util
-        return bool(util)
+        return find_spec("xpra.server.core") is not None
     except ImportError:
         return False
 
