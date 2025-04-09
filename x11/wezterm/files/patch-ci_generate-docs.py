--- ci/generate-docs.py.orig	2025-02-13 20:33:49 UTC
+++ ci/generate-docs.py
@@ -340,17 +340,6 @@ TOC = [
         ],
     ),
     Page(
-        "Download",
-        "installation.md",
-        children=[
-            Page("Windows", "install/windows.md"),
-            Page("macOS", "install/macos.md"),
-            Page("Linux", "install/linux.md"),
-            Page("FreeBSD", "install/freebsd.md"),
-            Page("Build from source", "install/source.md"),
-        ],
-    ),
-    Page(
         "Configuration",
         "config/files.md",
         children=[
