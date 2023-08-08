--- programs/dtappbuilder/src/ab/pal_drawp.c.orig	2023-02-15 07:51:51.791478000 -0800
+++ programs/dtappbuilder/src/ab/pal_drawp.c	2023-02-15 07:53:12.120282000 -0800
@@ -273,11 +273,11 @@
 	/* Scrolling */
         n = 0;
         item[n] = cgen->scrolldisp_rbox_items.Never_item;
-        item_ptr[n] = AB_SCROLLBAR_NEVER; n++;
+        item_ptr[n] = (void *) AB_SCROLLBAR_NEVER; n++;
         item[n] = cgen->scrolldisp_rbox_items.Always_item;
-        item_ptr[n] = AB_SCROLLBAR_ALWAYS; n++;
+        item_ptr[n] = (void *) AB_SCROLLBAR_ALWAYS; n++;
         item[n] = cgen->scrolldisp_rbox_items.When_Needed_item;
-        item_ptr[n] = AB_SCROLLBAR_WHEN_NEEDED; n++;
+        item_ptr[n] = (void *) AB_SCROLLBAR_WHEN_NEEDED; n++;
         prop_radiobox_init(&(pds->scrolling), cgen->scrolldisp_rbox_label,
                 cgen->scrolldisp_rbox, n, item, item_ptr,
                 cgen->scroll_cb);
@@ -289,15 +289,15 @@
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
         prop_options_init(&(pds->frame), cgen->bframe_opmenu_label,
                             cgen->bframe_opmenu, cgen->bframe_opmenu_menu,
                             n, item, item_ptr,
