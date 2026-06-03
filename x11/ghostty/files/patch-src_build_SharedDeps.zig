--- src/build/SharedDeps.zig.orig	2026-03-09 15:48:36 UTC
+++ src/build/SharedDeps.zig
@@ -149,7 +149,7 @@ pub fn add(
         );

         if (b.systemIntegrationOption("freetype", .{})) {
-            step.linkSystemLibrary2("bzip2", dynamic_link_opts);
+            step.linkSystemLibrary2("bz2", dynamic_link_opts);
             step.linkSystemLibrary2("freetype2", dynamic_link_opts);
         } else {
             step.linkLibrary(freetype_dep.artifact("freetype"));
