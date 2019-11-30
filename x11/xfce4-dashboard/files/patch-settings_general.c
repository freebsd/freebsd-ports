--- settings/general.c.orig	2019-11-15 13:13:14 UTC
+++ settings/general.c
@@ -105,7 +105,7 @@ static GParamSpec* XfdashboardSettingsGeneralPropertie
 #define DEFAULT_ALLOW_SUBWINDOWS							TRUE
 
 #define ENABLE_ANIMATIONS_XFCONF_PROP						"/enable-animations"
-#define DEFAULT_ENABLE_ANIMATIONS							TRUE
+#define DEFAULT_ENABLE_ANIMATIONS							FALSE
 
 
 typedef struct _XfdashboardSettingsGeneralNameValuePair		XfdashboardSettingsGeneralNameValuePair;
@@ -638,6 +638,7 @@ static void _xfdashboard_settings_general_set_builder(
 							G_TYPE_BOOLEAN,
 							priv->widgetEnableAnimations,
 							"active");
+	gtk_widget_hide(GTK_WIDGET(priv->widgetEnableAnimations));
 }
 
 /* IMPLEMENTATION: GObject */
