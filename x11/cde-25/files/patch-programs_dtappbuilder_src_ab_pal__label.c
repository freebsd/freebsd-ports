--- programs/dtappbuilder/src/ab/pal_label.c.orig	2023-02-15 07:51:51.746059000 -0800
+++ programs/dtappbuilder/src/ab/pal_label.c	2023-02-15 07:53:12.105899000 -0800
@@ -257,9 +257,9 @@
         /* Label Type */
         n = 0;
         item[n] = cgen->labeltype_rbox_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_rbox_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         prop_options_init(&(pls->label_type), cgen->labeltype_rbox_label,
                         cgen->labeltype_rbox, cgen->labeltype_rbox_menu,
 			n, item, item_ptr,
@@ -274,11 +274,11 @@
         /* Label Align */
         n = 0;
         item[n] = cgen->labelalign_opmenu_items.Left_item;
-        item_ptr[n] = AB_ALIGN_LEFT; n++;
+        item_ptr[n] = (void *) AB_ALIGN_LEFT; n++;
         item[n] = cgen->labelalign_opmenu_items.Centered_item;
-        item_ptr[n] = AB_ALIGN_CENTER; n++;
+        item_ptr[n] = (void *) AB_ALIGN_CENTER; n++;
         item[n] = cgen->labelalign_opmenu_items.Right_item;
-        item_ptr[n] = AB_ALIGN_RIGHT; n++;
+        item_ptr[n] = (void *) AB_ALIGN_RIGHT; n++;
         prop_options_init(&(pls->label_align), cgen->labelalign_opmenu_label,
                 cgen->labelalign_opmenu, cgen->labelalign_opmenu_menu,
                 n, item, item_ptr,
@@ -287,9 +287,9 @@
         /* Size Policy */
         n = 0;
         item[n] = cgen->szpolicy_rbox_items.Size_of_Label_item;
-        item_ptr[n] = SIZE_OF_CONTENTS_KEY; n++;
+        item_ptr[n] = (void *) SIZE_OF_CONTENTS_KEY; n++;
         item[n] = cgen->szpolicy_rbox_items.Fixed_item;
-        item_ptr[n] = SIZE_FIXED_KEY; n++;
+        item_ptr[n] = (void *) SIZE_FIXED_KEY; n++;
         prop_radiobox_init(&(pls->size_policy), cgen->szpolicy_rbox_label,
                 cgen->szpolicy_rbox, n, item, item_ptr,
                 cgen->szpolicy_cb);
