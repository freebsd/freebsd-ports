--- lib/awful/spawn.lua.orig	2026-11-04 16:25:26.589907000 -0800
+++ lib/awful/spawn.lua	2026-11-04 16:26:25.959947000 -0800
@@ -225,6 +225,7 @@
 }
 local lgi = require("lgi")
 local Gio = lgi.Gio
+local GioUnix = lgi.GioUnix
 local GLib = lgi.GLib
 local util   = require("awful.util")
 local gtable = require("gears.table")
@@ -411,11 +412,11 @@
         end
     end
     if have_stdout then
-        spawn.read_lines(Gio.UnixInputStream.new(stdout, true),
+        spawn.read_lines(GioUnix.InputStream.new(stdout, true),
                 stdout_callback, step_done, true)
     end
     if have_stderr then
-        spawn.read_lines(Gio.UnixInputStream.new(stderr, true),
+        spawn.read_lines(GioUnix.InputStream.new(stderr, true),
                 stderr_callback, step_done, true)
     end
     assert(stdin == nil)
