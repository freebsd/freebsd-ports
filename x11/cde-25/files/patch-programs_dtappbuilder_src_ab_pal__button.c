--- programs/dtappbuilder/src/ab/pal_button.c.orig	2023-02-15 07:51:51.770554000 -0800
+++ programs/dtappbuilder/src/ab/pal_button.c	2023-02-15 07:53:12.113232000 -0800
@@ -294,11 +294,11 @@
         /* Button Type */
         n = 0;
         item[n] = cgen->buttontype_rbox_items.Push_item;
-        item_ptr[n] = AB_BUT_PUSH; n++;
+        item_ptr[n] = (void *) AB_BUT_PUSH; n++;
         item[n] = cgen->buttontype_rbox_items.Drawn_item;
-        item_ptr[n] = AB_BUT_DRAWN; n++;
+        item_ptr[n] = (void *) AB_BUT_DRAWN; n++;
         item[n] = cgen->buttontype_rbox_items.Menu_item;
-        item_ptr[n] = AB_BUT_MENU; n++;
+        item_ptr[n] = (void *) AB_BUT_MENU; n++;
         prop_radiobox_init(&(pbs->button_type), cgen->buttontype_rbox_label,
                                 cgen->buttontype_rbox, n, item, item_ptr,
                                 cgen->buttontype_cb);
@@ -309,11 +309,11 @@
         /* Label Type */
         n = 0;
         item[n] = cgen->labeltype_rbox_items.String_item;
-        item_ptr[n] = AB_LABEL_STRING; n++;
+        item_ptr[n] = (void *) AB_LABEL_STRING; n++;
         item[n] = cgen->labeltype_rbox_items.Graphic_item;
-        item_ptr[n] = AB_LABEL_GLYPH; n++;
+        item_ptr[n] = (void *) AB_LABEL_GLYPH; n++;
         item[n] = cgen->labeltype_rbox_items.Arrow_item;
-        item_ptr[n] = AB_LABEL_ARROW_DOWN; n++;
+        item_ptr[n] = (void *) AB_LABEL_ARROW_DOWN; n++;
         prop_options_init(&(pbs->label_type), cgen->labeltype_rbox_label,
                         cgen->labeltype_rbox, cgen->labeltype_rbox_menu,
 			n, item, item_ptr,
@@ -346,11 +346,11 @@
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
         prop_options_init(&(pbs->label_align), cgen->labelalign_opmenu_label,
                 cgen->labelalign_opmenu, cgen->labelalign_opmenu_menu,
                 n, item, item_ptr,
@@ -359,13 +359,13 @@
         /* Arrow Direction */
         n = 0;
         item[n] = cgen->arrowdir_opmenu_items.Up_item;
-        item_ptr[n] = AB_LABEL_ARROW_UP; n++;
+        item_ptr[n] = (void *) AB_LABEL_ARROW_UP; n++;
         item[n] = cgen->arrowdir_opmenu_items.Down_item;
-        item_ptr[n] = AB_LABEL_ARROW_DOWN; n++;
+        item_ptr[n] = (void *) AB_LABEL_ARROW_DOWN; n++;
         item[n] = cgen->arrowdir_opmenu_items.Right_item;
-        item_ptr[n] = AB_LABEL_ARROW_RIGHT; n++;
+        item_ptr[n] = (void *) AB_LABEL_ARROW_RIGHT; n++;
         item[n] = cgen->arrowdir_opmenu_items.Left_item;
-        item_ptr[n] = AB_LABEL_ARROW_LEFT; n++;
+        item_ptr[n] = (void *) AB_LABEL_ARROW_LEFT; n++;
         prop_options_init(&(pbs->arrow_dir), cgen->arrowdir_opmenu_label,
                 cgen->arrowdir_opmenu, cgen->arrowdir_opmenu_menu,
                 n, item, item_ptr,
@@ -380,9 +380,9 @@
         /* Size Policy */
         n = 0;
         item[n] = cgen->sizepolicy_rbox_items.Size_of_Label_item;
-        item_ptr[n] = SIZE_OF_CONTENTS_KEY; n++;
+        item_ptr[n] = (void *) SIZE_OF_CONTENTS_KEY; n++;
         item[n] = cgen->sizepolicy_rbox_items.Fixed_item;
-        item_ptr[n] = SIZE_FIXED_KEY; n++;
+        item_ptr[n] = (void *) SIZE_FIXED_KEY; n++;
         prop_radiobox_init(&(pbs->size_policy), cgen->sizepolicy_rbox_label,
                 cgen->sizepolicy_rbox, n, item, item_ptr,
                 cgen->sizepolicy_cb);
