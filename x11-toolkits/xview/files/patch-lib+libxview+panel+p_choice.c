--- ./lib/libxview/panel/p_choice.c.orig	Tue Jun 29 07:16:57 1993
+++ ./lib/libxview/panel/p_choice.c	Sat Apr  1 18:25:26 2000
@@ -106,6 +106,10 @@ static void     choice_begin_preview(), 
 static int      choice_number();
 static int	choice_x_gap();
 static int	choice_y_gap();
+static int	find_choice();
+static int	modify_choice();
+static int	move_specified();
+static int	re_alloc_choices();
 static unsigned int choice_value();
 static void     choice_create_menu();
 static void	choice_images_to_menu_items();
@@ -120,7 +124,6 @@ static void     update_display();
 static void     update_item_rect();
 static void     update_value_rect();
 static Xv_opaque choice_do_menu_item();
-
 
 static Panel_ops ops = {
     panel_default_handle_event,		/* handle_event() */
