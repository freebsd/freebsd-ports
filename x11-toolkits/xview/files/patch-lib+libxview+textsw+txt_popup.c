--- ./lib/libxview/textsw/txt_popup.c.orig	Tue Jun 29 07:17:38 1993
+++ ./lib/libxview/textsw/txt_popup.c	Sat Apr  1 18:25:29 2000
@@ -95,6 +95,10 @@ Pkg_private int      FC_PARENT_KEY;
 static int      TEXTSW_POPUP_KEY;  /* key data holding one of the above
 				      key names */
 
+static void add_exten_item();
+static int  fc_exten_func();
+static void show_dot_files_proc();
+
 Panel_item      store_panel_items[MAX_FILE_PANEL_ITEMS];
 Panel_item      load_panel_items[MAX_FILE_PANEL_ITEMS];
 Panel_item      include_panel_items[MAX_FILE_PANEL_ITEMS];
@@ -135,7 +139,6 @@ textsw_create_popup_frame(view, popup_ty
     Frame           popup_frame, base_frame;
     Panel           panel = NULL;
     char           *label;
-    void            add_exten_item();
 #ifdef OW_I18N
     int		    win_use_im = ((popup_type != TEXTSW_MENU_SEL_MARK_TEXT) &&
 				  (popup_type != TEXTSW_MENU_NORMALIZE_LINE));
@@ -502,8 +505,6 @@ add_exten_item( fc )
     int frame_width;
     int frame_height;
     Panel_item item;
-    void show_dot_files_proc();
-    int  fc_exten_func();
  
     
     panel = xv_get(fc, FRAME_CMD_PANEL);
