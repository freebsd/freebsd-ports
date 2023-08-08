--- programs/dtappbuilder/src/ab/pal_textp.c.orig	2023-02-15 07:51:51.773254000 -0800
+++ programs/dtappbuilder/src/ab/pal_textp.c	2023-02-15 07:53:12.115353000 -0800
@@ -270,9 +270,9 @@
 	/* Scrolling */
         n = 0;
         item[n] = cgen->scroll_rbox_items.Never_item;
-        item_ptr[n] = AB_SCROLLBAR_NEVER; n++;
+        item_ptr[n] = (void *) AB_SCROLLBAR_NEVER; n++;
         item[n] = cgen->scroll_rbox_items.Always_item;
-        item_ptr[n] = AB_SCROLLBAR_ALWAYS; n++;
+        item_ptr[n] = (void *) AB_SCROLLBAR_ALWAYS; n++;
         prop_radiobox_init(&(pts->scrolling), cgen->scroll_rbox_label,
                 cgen->scroll_rbox, n, item, item_ptr,
                 cgen->scroll_cb);
@@ -280,15 +280,15 @@
         /* Border Frame */
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
         prop_options_init(&(pts->frame), cgen->bframe_opmenu_label,
                             cgen->bframe_opmenu, cgen->bframe_opmenu_menu,
                             n, item, item_ptr,
@@ -297,9 +297,9 @@
         /* Operation */
         n = 0;
         item[n] = cgen->op_rbox_items.Editable_item;
-        item_ptr[n] = False; n++;
+        item_ptr[n] = (void *) False; n++;
         item[n] = cgen->op_rbox_items.Read_Only_item;
-        item_ptr[n] = True; n++;
+        item_ptr[n] = (void *) True; n++;
         prop_radiobox_init(&(pts->op), cgen->op_rbox_label,
                 cgen->op_rbox, n, item, item_ptr,
                 cgen->op_cb);
@@ -343,9 +343,9 @@
 
 	n = 0;
 	item[n] = cgen->size_opmenu_items.Characters_item;
-	item_ptr[n] = SIZE_IN_CHARS_KEY; n++;
+	item_ptr[n] = (void *) SIZE_IN_CHARS_KEY; n++;
 	item[n] = cgen->size_opmenu_items.Pixels_item;
-	item_ptr[n] = SIZE_IN_PIXELS_KEY; n++;
+	item_ptr[n] = (void *) SIZE_IN_PIXELS_KEY; n++;
 	prop_options_init(&(pts->size_metric), cgen->size_opmenu_label,
 			   cgen->size_opmenu,
 			   cgen->size_opmenu_menu,
