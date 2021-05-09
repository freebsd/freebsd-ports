This is a cut-down version of https://bazaar.launchpad.net/~ctwm/ctwm/trunk/revision/558
which passed through vtwm and Reddit before arriving in FreeBSD ports.

--- src/add_window.c.orig	2020-06-14 23:58:19 UTC
+++ src/add_window.c
@@ -238,6 +238,9 @@ AddWindow(Window w, int iconm, IconMgr *iconp)
 
     tmp_win->wmhints = XGetWMHints(dpy, tmp_win->w);
 
+    if (!tmp_win->wmhints) {
+        tmp_win->wmhints = gen_synthetic_wmhints(tmp_win);
+    }
     if (tmp_win->wmhints) {
         if (restore_iconified) {
             tmp_win->wmhints->initial_state = IconicState;
