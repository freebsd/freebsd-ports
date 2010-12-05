--- libengine/themer.c.orig	2009-10-13 20:56:23.000000000 -0400
+++ libengine/themer.c	2010-11-24 15:34:34.000000000 -0500
@@ -461,7 +461,7 @@ gboolean get_bool(SettingItem * item)
 }
 gdouble get_float(SettingItem * item)
 {
-    if(!strcmp(GTK_OBJECT_TYPE_NAME(item->widget),"GtkSpinButton")) {
+    if(!strcmp(G_OBJECT_TYPE_NAME(item->widget),"GtkSpinButton")) {
          return gtk_spin_button_get_value((GtkSpinButton *)item->widget);
     }
     else {
@@ -647,7 +647,7 @@ void set_bool(SettingItem * item, gboole
 }
 void set_float(SettingItem * item, gdouble f)
 {
-    if(!strcmp(GTK_OBJECT_TYPE_NAME(item->widget),"GtkSpinButton")) {
+    if(!strcmp(G_OBJECT_TYPE_NAME(item->widget),"GtkSpinButton")) {
          gtk_spin_button_set_value((GtkSpinButton *)item->widget, f);
     } 
     else {
@@ -874,7 +874,7 @@ static void append_engine(gchar * dlname
     err = dlerror();
     if (!hand || err)
     {
-        g_warning(err);
+        g_warning("%s", err);
         if (hand)
             dlclose(hand);
         return;
@@ -885,7 +885,7 @@ static void append_engine(gchar * dlname
         layout_settings_proc lay;
         lay = dlsym(hand,"layout_engine_settings");
         if ((err=dlerror()))
-            g_warning(err);
+            g_warning("%s", err);
         if (lay)
         {
             get_meta_info_proc meta;
@@ -896,7 +896,7 @@ static void append_engine(gchar * dlname
                 "<i><small>%s</small></i>";
             meta = dlsym(hand,"get_meta_info");
             if ((err=dlerror()))
-                g_warning(err);
+                g_warning("%s", err);
                 d->meta.description=g_strdup("No Description");
                 d->meta.version=g_strdup("0.0");
                 d->meta.last_compat=g_strdup("0.0");
