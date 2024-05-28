--- tools/libwacom-update-db.py.orig	2024-06-19 10:34:43 UTC
+++ tools/libwacom-update-db.py
@@ -189,7 +189,7 @@ if __name__ == "__main__":
         "path",
         nargs="?",
         type=Path,
-        default="/etc/libwacom",
+        default="%%PREFIX%%/etc/libwacom",
         help="Directory to load .tablet files from",
     )
     # buildsystem-mode is what we use from meson, it changes the
@@ -203,7 +203,7 @@ if __name__ == "__main__":
     parser.add_argument(
         "--skip-systemd-hwdb-update",
         action="store_true",
-        default=False,
+        default=True,
         help="Do not run systemd-hwdb --update (Note: updates to tablet files will not be reflected in udev)",
     )
     parser.add_argument(
