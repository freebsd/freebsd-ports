--- src/module/e_mod_data_file.c.orig	Thu Jul  6 23:30:59 2006
+++ src/module/e_mod_data_file.c	Thu Jul  6 23:31:07 2006
@@ -33,7 +33,7 @@
         snprintf(buf, sizeof(buf),
                  _("<hilight>Can't open file %s</hilight><br><br>"
                    "You can change the file in the dEvian's config panel"), source->devian->conf->file_path);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
      }
 
    /* create the textblock */
