--- programs/dtappbuilder/src/ab/pal_custdlg.c.orig	2023-02-15 07:51:51.804684000 -0800
+++ programs/dtappbuilder/src/ab/pal_custdlg.c	2023-02-15 07:53:12.122346000 -0800
@@ -303,7 +303,7 @@
         /* Window Parent */
         n = 0;
         item[n] = cgen->winparent_opmenu_items.None_item;
-        item_ptr[n] = 0; n++;
+        item_ptr[n] = (void *) 0; n++;
         prop_obj_options_init(&(pcs->win_parent), cgen->winparent_opmenu_label,
                 cgen->winparent_opmenu, cgen->winparent_opmenu_menu,
                 n, item, item_ptr,
@@ -317,9 +317,9 @@
         /* Resize Mode */
         n = 0;
         item[n] = cgen->resizemode_rbox_items.Adjustable_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         item[n] = cgen->resizemode_rbox_items.Fixed_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         prop_radiobox_init(&(pcs->resize_mode), cgen->resizemode_rbox_label,
                 cgen->resizemode_rbox, n, item, item_ptr,
                 cgen->resizemode_cb);
@@ -338,7 +338,7 @@
  	/* Default Button */
         n = 0;
         item[n] = cgen->defaultb_opmenu_items.None_item;
-        item_ptr[n] = 0; n++;
+        item_ptr[n] = (void *) 0; n++;
 	prop_obj_options_init(&(pcs->default_but), cgen->defaultb_opmenu_label,
 		cgen->defaultb_opmenu, cgen->defaultb_opmenu_menu,
 		n, item, item_ptr,
@@ -348,7 +348,7 @@
  	/* Help Button */
         n = 0;
         item[n] = cgen->helpb_opmenu_items.None_item;
-        item_ptr[n] = 0; n++;
+        item_ptr[n] = (void *) 0; n++;
 	prop_obj_options_init(&(pcs->help_but), cgen->helpb_opmenu_label,
 		cgen->helpb_opmenu, cgen->helpb_opmenu_menu,
 		n, item, item_ptr,
@@ -358,9 +358,9 @@
         /* Size Policy */
         n = 0;
         item[n] = cgen->size_policy_rbox_items.Fit_Contents_item;
-        item_ptr[n] = SIZE_OF_CONTENTS_KEY; n++;
+        item_ptr[n] = (void *) SIZE_OF_CONTENTS_KEY; n++;
         item[n] = cgen->size_policy_rbox_items.Fixed_item;
-        item_ptr[n] = SIZE_FIXED_KEY; n++;
+        item_ptr[n] = (void *) SIZE_FIXED_KEY; n++;
         prop_radiobox_init(&(pcs->size_policy), cgen->size_policy_rbox_label,
                 cgen->size_policy_rbox, n, item, item_ptr,
                 cgen->size_policy_cb);
