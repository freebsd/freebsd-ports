--- programs/dtappbuilder/src/ab/pal_mainwin.c.orig	2023-02-15 07:51:51.772526000 -0800
+++ programs/dtappbuilder/src/ab/pal_mainwin.c	2023-02-15 07:53:12.114270000 -0800
@@ -275,9 +275,9 @@
         /* Resize Mode */
         n = 0;
         item[n] = cgen->resizemode_rbox_items.Adjustable_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         item[n] = cgen->resizemode_rbox_items.Fixed_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         prop_radiobox_init(&(pms->resize_mode), cgen->resizemode_rbox_label,
                 cgen->resizemode_rbox, n, item, item_ptr,
                 cgen->resizemode_cb);
@@ -309,9 +309,9 @@
         /* Size Policy */
         n = 0;
         item[n] = cgen->size_policy_rbox_items.Fit_Contents_item;
-        item_ptr[n] = SIZE_OF_CONTENTS_KEY; n++;
+        item_ptr[n] = (void *) SIZE_OF_CONTENTS_KEY; n++;
         item[n] = cgen->size_policy_rbox_items.Fixed_item;
-        item_ptr[n] = SIZE_FIXED_KEY; n++;
+        item_ptr[n] = (void *) SIZE_FIXED_KEY; n++;
         prop_radiobox_init(&(pms->size_policy), cgen->size_policy_rbox_label,
                 cgen->size_policy_rbox, n, item, item_ptr,
                 cgen->size_policy_cb);
