--- org/eclipse/swt/graphics/Device.java.orig	2021-06-11 17:24:22 UTC
+++ org/eclipse/swt/graphics/Device.java
@@ -740,7 +740,7 @@ protected void init () {
 	}
 	systemFont = Font.gtk_new (this, defaultFont);
 
-	overrideThemeValues();
+	//overrideThemeValues();
 }
 
 /**
