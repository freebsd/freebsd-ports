--- lib/Xm/MenuShell.c.orig	2017-12-05 12:46:16 UTC
+++ lib/Xm/MenuShell.c
@@ -988,6 +988,7 @@ ForceMenuPaneOnScreen(
    if (bottomEdgeOfMenu >= (Position)dispHeight)
    {
       if (pulldown_button && XtParent(pulldown_button) &&
+		XmIsRowColumn(XtParent(pulldown_button)) &&
 	  (RC_Type(XtParent(pulldown_button)) == XmMENU_BAR))
       {
 	 Position y_temp = *y;
