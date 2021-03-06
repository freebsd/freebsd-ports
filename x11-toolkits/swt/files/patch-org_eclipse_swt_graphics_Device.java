--- org/eclipse/swt/graphics/Device.java.orig	2019-03-07 02:31:06 UTC
+++ org/eclipse/swt/graphics/Device.java
@@ -701,7 +701,7 @@ protected void init () {
 	}
 	systemFont = Font.gtk_new (this, defaultFont);
 
-	overrideThemeValues();
+	//overrideThemeValues();
 }
 
 /**
