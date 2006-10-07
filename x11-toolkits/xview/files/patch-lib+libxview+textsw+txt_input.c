--- lib/libxview/textsw/txt_input.c.orig	Thu Oct  5 19:18:11 2006
+++ lib/libxview/textsw/txt_input.c	Thu Oct  5 19:59:29 2006
@@ -57,6 +57,17 @@
 Pkg_private     void textsw_implicit_commit_doit();
 #endif
 
+static int textsw_do_newline();
+
+static int textsw_scroll_event();
+static int textsw_function_key_event();
+static int textsw_mouse_event();
+static int textsw_edit_function_key_event();
+static int textsw_caret_motion_event();
+static int textsw_field_event();
+static int textsw_file_operation();
+static int textsw_erase_action();
+
 #define SPACE_CHAR 0x20
 
 Pkg_private int
@@ -200,14 +211,14 @@
     Notify_arg      arg;
 {
     Pkg_private void     textsw_update_scrollbars();
-    static int      textsw_scroll_event();
-    static int      textsw_function_key_event();
-    static int      textsw_mouse_event();
-    static int      textsw_edit_function_key_event();
-    static int      textsw_caret_motion_event();
-    static int      textsw_field_event();
-    static int      textsw_file_operation();
-    static int      textsw_erase_action();
+    int      textsw_scroll_event();
+    int      textsw_function_key_event();
+    int      textsw_mouse_event();
+    int      textsw_edit_function_key_event();
+    int      textsw_caret_motion_event();
+    int      textsw_field_event();
+    int      textsw_file_operation();
+    int      textsw_erase_action();
 
     int             caret_was_up;
     int             result = TEXTSW_PE_USED;
