--- build.zig.orig	2026-10-04 07:14:50 UTC
+++ build.zig
@@ -105,7 +105,7 @@ pub fn build(b: *std.Build) !void {
     const zlua = b.dependency("zlua", .{
         .target = target,
         .optimize = optimize,
-        .lang = .luajit,
+        .lang = .lua52,
     });
     exe.root_module.addImport("zlua", zlua.module("zlua"));
 
