--- src/module/e_mod_data_picture.c.orig	Thu Jul  6 23:30:33 2006
+++ src/module/e_mod_data_picture.c	Thu Jul  6 23:30:56 2006
@@ -402,7 +402,7 @@
                    "They can be jpeg or png<br><br>"
                    "After import, if you can remove these files and the pictures still can<br>"
                    "be viewed, but you wont be able to set them as wallpaper anymore<br><br>"), dir);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return 0;
      }
 
@@ -1199,7 +1199,7 @@
        DEVIANM->conf->sources_picture_data_import_thumbs_warn)
      {
         DEVIANM->conf->sources_picture_data_import_thumbs_warn = 0;
-        e_module_dialog_show(_(MODULE_NAME " Module Information"),
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Information"),
                              _("<hilight>Creating thumbs</hilight><br><br>"
                                "Some pictures are being thumbed in a <hilight>background task</hilight>.<br>"
                                "It can take a while, but after, loading will be faster :)<br><br>"
