--- src/build/SharedDeps.zig.orig	2025-06-28 02:43:12 UTC
+++ src/build/SharedDeps.zig
@@ -122,7 +122,7 @@ pub fn add(
             );
 
             if (b.systemIntegrationOption("freetype", .{})) {
-                step.linkSystemLibrary2("bzip2", dynamic_link_opts);
+                step.linkSystemLibrary2("bz2", dynamic_link_opts);
                 step.linkSystemLibrary2("freetype2", dynamic_link_opts);
             } else {
                 step.linkLibrary(freetype_dep.artifact("freetype"));
