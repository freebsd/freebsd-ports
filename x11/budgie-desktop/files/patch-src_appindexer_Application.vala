--- src/appindexer/Application.vala.orig	2023-01-29 15:27:27 UTC
+++ src/appindexer/Application.vala
@@ -41,8 +41,6 @@ namespace Budgie {
 		 */
 		public signal void launch_failed(string startup_notify_id);
 
-		private Switcheroo switcheroo;
-
 		/**
 		* Create a new application from a `DesktopAppInfo`.
 		*/
@@ -71,7 +69,6 @@ namespace Budgie {
 		}
 
 		construct {
-			this.switcheroo = new Switcheroo();
 		}
 
 		/**
@@ -125,9 +122,6 @@ namespace Budgie {
 					context.launch_failed.connect((startup_id) => {
 						this.launch_failed(startup_id);
 					});
-
-					// Try to apply a GPU profile if necessary for multiple GPU setups
-					switcheroo.apply_gpu_profile(context, this.prefers_default_gpu);
 
 					// Launch the application
 					new DesktopAppInfo(this.desktop_id).launch(null, context);
