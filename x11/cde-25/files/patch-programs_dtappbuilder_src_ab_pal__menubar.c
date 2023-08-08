--- programs/dtappbuilder/src/ab/pal_menubar.c.orig	2023-02-15 07:51:51.790341000 -0800
+++ programs/dtappbuilder/src/ab/pal_menubar.c	2023-02-15 07:53:12.119294000 -0800
@@ -314,9 +314,9 @@
                 cgen->itemlabel_field, cgen->itemlist_cb);
         n = 0;
         item[n] = cgen->itemlabel_opmenu_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->itemlabel_opmenu_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pms->item_label_type), cgen->item_labeltype_label,
                 cgen->itemlabel_opmenu, cgen->itemlabel_opmenu_menu,
                 n, item, item_ptr, cgen->itemlist_cb);
