--- man/wleave.json.5.scd.orig	2026-01-23 07:24:32 UTC
+++ man/wleave.json.5.scd
@@ -13,14 +13,14 @@ Button layout is specified in the extra *"button"* fie
 	See section *LAYOUT* for structure
 
 *"button-layout"*: <*"grid"*>
-    Specify the way buttons should be laid out, "grid" being the default. Currently, only "grid" is supported.
+	Specify the way buttons should be laid out, "grid" being the default. Currently, only "grid" is supported.
 
 *"css"*: <string>
 	Specify a custom CSS file instead of the default one
 
 *"service"*: <boolean>
-    Run the application as a service, with all instances of wleave opening this one. Allows faster startup at the
-    cost of running in the background. ++
+	Run the application as a service, with all instances of wleave opening this one. Allows faster startup at the
+	cost of running in the background. ++
 *Default*: false
 
 *"buttons-per-row"*: <string>
@@ -94,8 +94,8 @@ The action field can be an object with exactly one of 
 - *"circular"* (*optional*, boolean, default false)
 
 The action field can be an object with exactly one of `shell` or `executable` properties set. The `shell` action executes
-the given command in the system shell, while the `executable` action executes the specified binary, assuming it in `$PATH`.
-`executable` actions get filtered if the specified executable does not exist, allowing multiple possible options.
+the given command in the system shell, while the `executable` action executes the specified binary, assuming it in `$PATH`. `executable`
+actions get filtered if the specified executable does not exist, allowing multiple possible options.
 
 Any extra properties in the `action` objects are interpreted as filters. Currently, only environment variable filtering
 is implemented, where the values fields prefixed with `$` are matched as conditions for the given action.
