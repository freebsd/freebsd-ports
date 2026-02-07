--- org/eclipse/swt/widgets/Shell.java.orig	2021-09-06 01:22:24 UTC
+++ org/eclipse/swt/widgets/Shell.java
@@ -1507,6 +1507,8 @@ long gtk_button_press_event (long widget, long event) 
 long gtk_configure_event (long widget, long event) {
 	int [] x = new int [1], y = new int [1];
 	GTK3.gtk_window_get_position (shellHandle, x, y);
+	int scale = GTK.gtk_widget_get_scale_factor (shellHandle);
+	x[0] /= scale; y[0] /= scale;
 
 	if (!isVisible ()) {
 		return 0; //We shouldn't handle move/resize events if shell is hidden.
@@ -3351,6 +3353,8 @@ Rectangle getBoundsInPixels () {
 			// TODO: GTK4 GtkWindow no longer has the ability to get position
 		} else {
 			GTK3.gtk_window_get_position (shellHandle, x, y);
+			int scale = GTK.gtk_widget_get_scale_factor (shellHandle);
+			x[0] /= scale; y[0] /= scale;
 		}
 	} else {
 		if (GTK.GTK4) {
