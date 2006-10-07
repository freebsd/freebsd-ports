--- lib/libxview/window/window_set.c.orig	Thu Oct  5 20:15:03 2006
+++ lib/libxview/window/window_set.c	Thu Oct  5 20:16:04 2006
@@ -53,6 +53,8 @@
 static     Xv_opaque 	window_set_avlist_tier2();
 static     Xv_opaque 	window_set_avlist_tier3();
 
+static void window_set_softkey_labels();
+
 static Defaults_pairs setinput_pairs[] = {
     "select",		FALSE,
     "followmouse",	TRUE,
@@ -1072,7 +1074,7 @@
 
       case WIN_SOFT_FNKEY_LABELS: {
         register Xv_Drawable_info 	*info;
-        static void                   	 window_set_softkey_labels();
+        void                   	 	window_set_softkey_labels();
 
         DRAWABLE_INFO_MACRO(win_public, info);
         win->softkey_flag = TRUE;
