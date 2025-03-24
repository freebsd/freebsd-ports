--- src/panel/applets/icon-tasklist/animation.vala.orig	2025-03-22 02:28:21 UTC
+++ src/panel/applets/icon-tasklist/animation.vala
@@ -27,7 +27,6 @@ namespace BudgieTaskList {
 	* Utility to struct to enable easier animations
 	* Inspired by Clutter.
 	*/
-	[Compact]
 	public class Animation : GLib.Object {
 		public int64 start_time; /**<Start time (microseconds) of animation */
 		public int64 length; /**<Length of animation in microseconds */
