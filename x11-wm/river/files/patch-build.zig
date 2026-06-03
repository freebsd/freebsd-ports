--- build.zig.orig	2026-04-25 12:20:33 UTC
+++ build.zig
@@ -19,7 +19,7 @@ pub fn build(b: *Build) !void {
 
     const strip = b.option(bool, "strip", "Omit debug information") orelse false;
     const pie = b.option(bool, "pie", "Build a Position Independent Executable") orelse false;
-    const use_llvm = b.option(bool, "llvm", "Force use of Zig's LLVM backend and the lld linker") orelse false;
+    const use_llvm = b.option(bool, "llvm", "Force use of Zig's LLVM backend and the lld linker");
 
     const omit_frame_pointer = switch (optimize) {
         .Debug, .ReleaseSafe => false,
