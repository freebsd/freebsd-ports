--- programs/dtappbuilder/src/ab/pal_fchooser.c.orig	2023-02-15 07:51:51.784136000 -0800
+++ programs/dtappbuilder/src/ab/pal_fchooser.c	2023-02-15 07:53:12.118430000 -0800
@@ -282,11 +282,11 @@
         /* Search Pattern Type */
         n = 0;
         item[n] = cgen->pattern_type_rbox_items.Files_item;
-        item_ptr[n] = AB_FILE_REGULAR; n++;
+        item_ptr[n] = (void *) AB_FILE_REGULAR; n++;
         item[n] = cgen->pattern_type_rbox_items.Directories_item;
-        item_ptr[n] = AB_FILE_DIRECTORY; n++;
+        item_ptr[n] = (void *) AB_FILE_DIRECTORY; n++;
         item[n] = cgen->pattern_type_rbox_items.Both_item;
-        item_ptr[n] = AB_FILE_ANY; n++;
+        item_ptr[n] = (void *) AB_FILE_ANY; n++;
         prop_radiobox_init(&(pcs->pattern_type), cgen->pattern_type_rbox_label,
                 cgen->pattern_type_rbox, n, item, item_ptr,
                 cgen->pattern_type_cb);
