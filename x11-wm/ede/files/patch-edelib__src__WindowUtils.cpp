--- ../edelib/src/WindowUtils.cpp.orig	2014-06-21 23:24:07.000000000 +0200
+++ ../edelib/src/WindowUtils.cpp	2015-07-06 08:22:40.598815934 +0200
@@ -1,5 +1,5 @@
 /*
- * $Id: WindowUtils.cpp 3106 2011-10-21 20:26:08Z karijes $
+ * $Id: WindowUtils.cpp 3592 2014-12-02 12:48:07Z karijes $
  *
  * Window utils
  * Copyright (c) 1998-2006 by Bill Spitzak and others
@@ -33,8 +33,10 @@
  * These are defined in FLTK as hidden variables for some internal hacks, but are used here.
  * XXX: possible changes in future FLTK versions
  */
+#if 0
 extern char fl_show_iconic;
 extern int  fl_disable_transient_for;
+#endif 
 
 EDELIB_NS_BEGIN
 
@@ -165,7 +167,7 @@ void window_xid_create(Fl_Window* win, v
 			XChangeProperty(fl_display, xp->xid, XA_WM_CLASS, XA_STRING, 8, 0, (unsigned char *)buffer, p-buffer-1);
 		}
 
-		if(win->non_modal() && xp->next && !fl_disable_transient_for) {
+		if(win->non_modal() && xp->next /* && !fl_disable_transient_for */) {
 			// find some other window to be "transient for":
 			Fl_Window* wp = xp->next->w;
 			while(wp->parent()) 
@@ -193,13 +195,14 @@ void window_xid_create(Fl_Window* win, v
 		XWMHints *hints = XAllocWMHints();
 		hints->input = True;
 		hints->flags = InputHint;
-
+#if 0 
 		if(fl_show_iconic) {
 			hints->flags |= StateHint;
 			hints->initial_state = IconicState;
 			fl_show_iconic = 0;
 			showit = 0;
 		}
+#endif 
 
 		// This is not removed so it can be used with windows inherited from Fl_Window
 		if(win->icon()) {
