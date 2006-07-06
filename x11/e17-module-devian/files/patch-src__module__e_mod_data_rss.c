--- src/module/e_mod_data_rss.c.orig	Thu Jul  6 23:30:02 2006
+++ src/module/e_mod_data_rss.c	Thu Jul  6 23:30:29 2006
@@ -280,7 +280,7 @@
         snprintf(buf, sizeof(buf),
                  _("<hilight>Rss '%s' is aready in use !</hilight><br><br>"
                    "You can't set a rss document to more than one dEvian<br><br>" "Url: %s"), doc->name, doc->url);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return -1;
      }
 
@@ -561,7 +561,7 @@
                              "<underline=on underline_color=#000>Url :</> %s<br>"
                              "<underline=on underline_color=#000>Begining of the document dEvian get :</><br>%100.100s"),
                            doc->name, doc->url, feed->buffer);
-                  e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+                  e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
                }
              else
                {
@@ -572,7 +572,7 @@
                              "<underline=on underline_color=#000>Url :</> %s<br>"
                              "<underline=on underline_color=#000>Begining of the document dEvian get :</><br>%100.100s<br>"
                              "%100.100s"), doc->name, doc->url, feed->buffer, p);
-                  e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+                  e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
                }
           }
         DEVIANF(container_loading_state_change) (feed->source->devian, 0);
@@ -1009,7 +1009,7 @@
      {
         snprintf(buf, sizeof(buf),
                  _("<hilight>Unable to open link</hilight><br><br>" "Article '%s' has no link associated !"), article->title);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return;
      }
 
@@ -1029,7 +1029,7 @@
                  _("<hilight>Viewer %s not found !</hilight><br><br>"
                    "You can change the viewer for http in dEvian configuration panel\
  (Advanced view)"), DEVIANM->conf->viewer_http);
-        e_module_dialog_show(_(MODULE_NAME " Module Error"), buf);
+        e_module_dialog_show(DEVIANM->module, _(MODULE_NAME " Module Error"), buf);
         return;
      }
 
