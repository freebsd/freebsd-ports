Description: Proxy mode failed with ImportError: instance_base.py imports
  get_server_info and proto_crypto_caps from xpra.server.core, which no
  longer defines them (6.4 moved them away; 6.5.4 and 6.5.5 are both
  affected).  Backport master's fix: import proto_crypto_caps from
  xpra.server.subsystem.encryption, send session-type, machine-id and
  version (plus the hostname with FULL_INFO > 0) as the proxy caps, and
  drop the server info from get_proxy_info().
Issue ID: none
Changeset: https://github.com/Xpra-org/xpra/commit/6de90992426a1e82bf542152aba3475b1bbe8ace
  and https://github.com/Xpra-org/xpra/commit/16835e7611f57dc1d11254028475aac13a78203a
  (master; only the instance_base.py import, proxy caps and
  get_proxy_info() changes); not on the v6.5.x branch
TODO: Drop once a 6.5.x release or a release based on master has it.

--- xpra/server/proxy/instance_base.py.orig	2026-09-27 15:24:27 UTC
+++ xpra/server/proxy/instance_base.py
@@ -21,13 +21,13 @@
 from xpra.net.constants import MAX_PACKET_SIZE, ConnectionMessage
 from xpra.net.digest import get_salt, gendigest, get_caps as get_digest_caps
 from xpra.util.parsing import str_to_bool, parse_number
-from xpra.os_util import get_hex_uuid, gi_import
+from xpra.os_util import get_hex_uuid, gi_import, get_machine_id
 from xpra.exit_codes import ExitValue
 from xpra.util.objects import typedict
 from xpra.util.str_fn import csv, Ellipsizer, strtobytes, nicestr
 from xpra.util.env import envint, envbool
 from xpra.util.version import XPRA_VERSION, vparts
-from xpra.server.core import get_server_info, proto_crypto_caps
+from xpra.server.subsystem.encryption import proto_crypto_caps
 from xpra.log import Logger
 
 GLib = gi_import("GLib")
@@ -82,7 +82,11 @@
     # replace the network caps with the proxy's own:
     pcaps |= get_network_caps() | proto_crypto_caps(proto) | get_digest_caps()
     # then add the proxy info:
-    si = get_server_info()
+    si = {
+        "session-type": "proxy",
+        "machine-id": get_machine_id(),
+        "version": vparts(XPRA_VERSION, FULL_INFO + 1),
+    }
     if FULL_INFO > 0:
         si["hostname"] = socket.gethostname()
     pcaps["proxy"] = si
@@ -223,7 +227,6 @@
     ################################################################################
 
     def get_proxy_info(self, proto) -> dict[str, Any]:
-        sinfo = get_server_info()
         linfo = {}
         if self.client_last_ping_latency:
             linfo["client"] = round(self.client_last_ping_latency)
@@ -232,7 +235,6 @@
         return {
             "proxy": {
                 "version": vparts(XPRA_VERSION, FULL_INFO + 1),
-                "": sinfo,
                 "latency": linfo,
             },
         }
