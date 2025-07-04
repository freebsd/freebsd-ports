--- src/build/GhosttyResources.zig.orig	2025-06-28 02:43:12 UTC
+++ src/build/GhosttyResources.zig
@@ -19,10 +19,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
     // Terminfo
     terminfo: {
         const os_tag = cfg.target.result.os.tag;
-        const terminfo_share_dir = if (os_tag == .freebsd)
-            "site-terminfo"
-        else
-            "terminfo";
+        const terminfo_share_dir = "terminfo";
 
         // Encode our terminfo
         var str = std.ArrayList(u8).init(b.allocator);
@@ -34,13 +31,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
         const source = wf.add("ghostty.terminfo", str.items);
 
         if (cfg.emit_terminfo) {
-            const source_install = b.addInstallFile(
-                source,
-                if (os_tag == .freebsd)
-                    "share/site-terminfo/ghostty.terminfo"
-                else
-                    "share/terminfo/ghostty.terminfo",
-            );
+            const source_install = b.addInstallFile(source, "share/ghostty/terminfo/ghostty.terminfo");
 
             try steps.append(&source_install.step);
         }
@@ -58,13 +49,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
             const out_source = run_step.captureStdOut();
             _ = run_step.captureStdErr(); // so we don't see stderr
 
-            const cap_install = b.addInstallFile(
-                out_source,
-                if (os_tag == .freebsd)
-                    "share/site-terminfo/ghostty.termcap"
-                else
-                    "share/terminfo/ghostty.termcap",
-            );
+            const cap_install = b.addInstallFile(out_source, "share/ghostty/terminfo/ghostty.termcap");
 
             try steps.append(&cap_install.step);
         }
@@ -80,7 +65,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
 
             // Ensure that `share/terminfo` is a directory, otherwise the `cp
             // -R` will create a file named `share/terminfo`
-            const mkdir_step = RunStep.create(b, "make share/terminfo directory");
+            const mkdir_step = RunStep.create(b, "make share/ghostty/terminfo directory");
             switch (cfg.target.result.os.tag) {
                 // windows mkdir shouldn't need "-p"
                 .windows => mkdir_step.addArgs(&.{"mkdir"}),
@@ -88,7 +73,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
             }
 
             mkdir_step.addArg(b.fmt(
-                "{s}/share/{s}",
+                "{s}/share/ghostty/{s}",
                 .{ b.install_path, terminfo_share_dir },
             ));
 
@@ -100,7 +85,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
             const copy_step = RunStep.create(b, "copy terminfo db");
             copy_step.addArgs(&.{ "cp", "-R" });
             copy_step.addFileArg(path);
-            copy_step.addArg(b.fmt("{s}/share", .{b.install_path}));
+            copy_step.addArg(b.fmt("{s}/share/ghostty", .{b.install_path}));
             copy_step.step.dependOn(&mkdir_step.step);
             try steps.append(&copy_step.step);
         }
@@ -221,7 +206,7 @@ pub fn init(b: *std.Build, cfg: *const Config) !Ghostt
     }
 
     // App (Linux)
-    if (cfg.target.result.os.tag == .linux) try addLinuxAppResources(
+    if (cfg.target.result.os.tag == .freebsd) try addLinuxAppResources(
         b,
         cfg,
         &steps,
@@ -237,7 +222,7 @@ fn addLinuxAppResources(
     cfg: *const Config,
     steps: *std.ArrayList(*std.Build.Step),
 ) !void {
-    assert(cfg.target.result.os.tag == .linux);
+    assert(cfg.target.result.os.tag == .freebsd);
 
     // Background:
     // https://developer.gnome.org/documentation/guidelines/maintainer/integrating.html
