--- src/module/e_mod_config.c.orig	Thu Jul 20 00:20:27 2006
+++ src/module/e_mod_config.c	Thu Aug  3 23:24:37 2006
@@ -35,6 +35,8 @@
    v = E_NEW(E_Config_Dialog_View, 1);
    if (v)
       {
+	 char buf[4096];
+
          v->create_cfdata = _create_data;
          v->free_cfdata = _free_data;
          v->basic.apply_cfdata = _basic_apply_data;
@@ -42,7 +44,8 @@
          v->advanced.apply_cfdata   = _advanced_apply_data;
          v->advanced.create_widgets = _advanced_create_widgets;
 
-         cfd = e_config_dialog_new(con, "Engage Configuration", NULL, 0, v, eb);
+	 snprintf(buf, sizeof(buf), "%s/module.eap", e_module_dir_get(eb->engage->module));
+         cfd = e_config_dialog_new(con, "Engage Configuration", buf, 0, v, eb);
          eb->cfd = cfd;
       }
 }
