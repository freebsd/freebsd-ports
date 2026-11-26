--- install/user/mise-work.sh	2026-09-29 09:19:48.167196526 -0700
+++ install/user/mise-work.sh	2026-09-29 09:19:48.186266582 -0700
@@ -39,5 +39,9 @@
     mise use -g node@"$NODE_VERSION"
   fi
 else
-  mise use -g node@latest
+  # Node.js publishes no FreeBSD builds for mise to install, so Node comes
+  # from the www/node package (pulled in by x11-wm/omarchy-desktop).
+  if ! command -v node >/dev/null; then
+    echo "Warning: Node.js is not installed; install it with: omarchy pkg add nodejs" >&2
+  fi
 fi
