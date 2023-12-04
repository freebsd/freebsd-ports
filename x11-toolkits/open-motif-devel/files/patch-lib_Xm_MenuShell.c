--- lib/Xm/MenuShell.c.orig	2023-02-15 16:42:34.000000000 -0800
+++ lib/Xm/MenuShell.c	2023-12-04 15:33:32.718284000 -0800
@@ -988,6 +988,7 @@
    if (bottomEdgeOfMenu >= (Position)dispHeight)
    {
       if (pulldown_button && XtParent(pulldown_button) &&
+		XmIsRowColumn(XtParent(pulldown_button)) &&
 	  (RC_Type(XtParent(pulldown_button)) == XmMENU_BAR))
       {
 	 Position y_temp = *y;
