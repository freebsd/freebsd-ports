--- src/appindexer/Application.vala.orig	2025-09-07 12:35:19 UTC
+++ src/appindexer/Application.vala
@@ -42,8 +42,6 @@ namespace Budgie {
 		 */
 		public signal void launch_failed(string startup_notify_id);
 
-		private Switcheroo switcheroo;
-
 		/**
 		* Create a new application from a `DesktopAppInfo`.
 		*/
@@ -73,7 +71,6 @@ namespace Budgie {
 		}
 
 		construct {
-			this.switcheroo = new Switcheroo();
 		}
 
 		/**
@@ -127,9 +124,6 @@ namespace Budgie {
 					context.launch_failed.connect((startup_id) => {
 						this.launch_failed(startup_id);
 					});
-
-					// Try to apply a GPU profile if necessary for multiple GPU setups
-					switcheroo.apply_gpu_profile(context, this.prefers_default_gpu);
 
 					// Launch the application
 					new DesktopAppInfo(this.desktop_id).launch(null, context);
