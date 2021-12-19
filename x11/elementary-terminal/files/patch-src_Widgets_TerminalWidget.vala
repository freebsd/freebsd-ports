--- src/Widgets/TerminalWidget.vala.orig	2021-12-13 18:31:36 UTC
+++ src/Widgets/TerminalWidget.vala
@@ -68,13 +68,6 @@ namespace Terminal {
         }
 
         public int default_size;
-        const string SEND_PROCESS_FINISHED_BASH = "dbus-send --type=method_call " +
-                                                  "--session --dest=io.elementary.terminal " +
-                                                  "/io/elementary/terminal " +
-                                                  "io.elementary.terminal.ProcessFinished " +
-                                                  "string:$PANTHEON_TERMINAL_ID " +
-                                                  "string:\"$(history 1 | cut -c 8-)\" " +
-                                                  "int32:\$__bp_last_ret_value >/dev/null 2>&1";
 
         /* Following strings are used to build RegEx for matching URIs */
         const string USERCHARS = "-[:alnum:]";
@@ -364,14 +357,7 @@ namespace Terminal {
 
             envv = {
                 // Export ID so we can identify the terminal for which the process completion is reported
-                "PANTHEON_TERMINAL_ID=" + terminal_id,
-
-                // Export callback command a BASH-specific variable, see "man bash" for details
-                "PROMPT_COMMAND=" + SEND_PROCESS_FINISHED_BASH + Environment.get_variable ("PROMPT_COMMAND"),
-
-                // ZSH callback command will be read from ZSH config file supplied by us, see data/
-
-                // TODO: support FISH, see https://github.com/fish-shell/fish-shell/issues/1382
+                "PANTHEON_TERMINAL_ID=" + terminal_id
             };
 
             /* We need opening uri to be available asap when constructing window with working directory
@@ -454,12 +440,49 @@ namespace Terminal {
             return this.match_check_event (event, null);
         }
 
+        private string? extract_cwd (string data) {
+            string[] tokens;
+            string result = null;
+
+            tokens = data.split (" ");
+            if (tokens.length > 0) {
+                result = tokens[(tokens.length - 1)];
+            }
+            return result;
+        }
+
         public string get_shell_location () {
+            string[] spawn_env = GLib.Environ.get ();
+            string[] procstat_cmd = {"/usr/bin/pwdx", "--libxo:T",};
+            string standard_output = null;
+            bool res;
+            string cwd = null;
+
             int pid = (!) (this.child_pid);
 
+            /* Update procstat(1) argument */
+            procstat_cmd += pid.to_string ();
+
             try {
-                return GLib.FileUtils.read_link ("/proc/%d/cwd".printf (pid));
-            } catch (GLib.FileError error) {
+                res = GLib.Process.spawn_sync (null, procstat_cmd,
+                                               spawn_env,
+                                               GLib.SpawnFlags.STDERR_TO_DEV_NULL,
+                                               null,
+                                               out standard_output,
+                                               null, null);
+                if (res) {
+                    cwd = extract_cwd (standard_output.strip ());
+                    if (cwd != null) {
+                        return cwd;
+                    }
+                    else {
+                        return GLib.Environment.get_current_dir ();
+                    }
+                }
+                else {
+                    return GLib.Environment.get_current_dir ();
+                }
+            } catch (GLib.SpawnError error) {
                 /* Tab name disambiguation may call this before shell location available. */
                 /* No terminal warning needed */
                 return "";
