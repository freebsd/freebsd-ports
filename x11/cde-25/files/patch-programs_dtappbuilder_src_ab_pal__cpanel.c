--- programs/dtappbuilder/src/ab/pal_cpanel.c.orig	2023-02-15 07:51:51.807704000 -0800
+++ programs/dtappbuilder/src/ab/pal_cpanel.c	2023-02-15 07:53:12.124476000 -0800
@@ -281,15 +281,15 @@
         /* Border Frame Setting */
         n = 0;
         item[n] = cgen->bframe_opmenu_items.None_item;
-        item_ptr[n] = AB_LINE_NONE; n++;
+        item_ptr[n] = (void *) AB_LINE_NONE; n++;
         item[n] = cgen->bframe_opmenu_items.Shadow_Out_item;
-        item_ptr[n] = AB_LINE_SHADOW_OUT; n++;
+        item_ptr[n] = (void *) AB_LINE_SHADOW_OUT; n++;
         item[n] = cgen->bframe_opmenu_items.Shadow_In_item;
-        item_ptr[n] = AB_LINE_SHADOW_IN; n++;
+        item_ptr[n] = (void *) AB_LINE_SHADOW_IN; n++;
         item[n] = cgen->bframe_opmenu_items.Etched_Out_item;
-        item_ptr[n] = AB_LINE_ETCHED_OUT; n++;
+        item_ptr[n] = (void *) AB_LINE_ETCHED_OUT; n++;
         item[n] = cgen->bframe_opmenu_items.Etched_In_item;
-        item_ptr[n] = AB_LINE_ETCHED_IN; n++;
+        item_ptr[n] = (void *) AB_LINE_ETCHED_IN; n++;
         prop_options_init(&(pcs->frame), cgen->bframe_opmenu_label,
                             cgen->bframe_opmenu, cgen->bframe_opmenu_menu,
                             n, item, item_ptr,
@@ -309,9 +309,9 @@
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
