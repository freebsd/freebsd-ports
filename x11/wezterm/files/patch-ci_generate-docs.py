--- ci/generate-docs.py.orig	2025-07-30 18:57:51 UTC
+++ ci/generate-docs.py
@@ -340,18 +340,6 @@ TOC = [
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
-            Page("NetBSD", "install/netbsd.md"),
-            Page("Build from source", "install/source.md"),
-        ],
-    ),
-    Page(
         "Configuration",
         "config/files.md",
         children=[
