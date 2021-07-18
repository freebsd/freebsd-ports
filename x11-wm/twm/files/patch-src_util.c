This is a cut-down version of https://bazaar.launchpad.net/~ctwm/ctwm/trunk/revision/558
which passed through vtwm and Reddit before arriving in FreeBSD ports.

--- src/util.c.orig	2020-06-14 23:58:19 UTC
+++ src/util.c
@@ -1033,3 +1033,44 @@ Bell(int type _X_UNUSED, int percent, Window win _X_UN
 #endif
     return;
 }
+
+/*
+ * Create synthetic WM_HINTS info for windows.  When a window specifies
+ * stuff, we should probably pay attention to it (though we don't
+ * always; x-ref comments in AddWindow() especially about focus).
+ * However, when it doesn't tell us anything at all, we should assume
+ * something useful.  "Window managers are free to assume convenient
+ * values for all fields of the WM_HINTS property if a window is mapped
+ * without one."  (ICCCM Ch. 4,
+ * <https://www.x.org/releases/X11R7.7/doc/xorg-docs/icccm/icccm.html#Client_Properties>).
+ *
+ * Specifically, we assume it wants us to give it focus.  It's fairly
+ * bogus for a window not to tell us anything, but e.g current versions
+ * of Chrome do (don't do) just that.  So we better make up something
+ * useful.
+ *
+ * Should probably be some configurability for this, so make the func
+ * take the window, even though we don't currently do anything useful
+ * with it...
+ */
+XWMHints *
+gen_synthetic_wmhints(TwmWindow *win)
+{
+	XWMHints *hints;
+
+	hints = XAllocWMHints();
+	if(!hints) {
+		return NULL;
+	}
+
+	/*
+	 * Reasonable defaults.  Takes input, in normal state.
+	 *
+	 * XXX Make configurable?
+	 */
+	hints->flags = InputHint | StateHint;
+	hints->input = True;
+	hints->initial_state = NormalState;
+
+	return hints;
+}
