--- fvwm/icons.c.orig	Wed Mar 17 09:42:54 2004
+++ fvwm/icons.c	Tue Oct 19 16:13:55 2004
@@ -2251,7 +2251,7 @@
  */
 void DeIconify(FvwmWindow *fw)
 {
-	FvwmWindow *t,*tmp;
+	FvwmWindow *t, *tmp, *ofw;
 	FvwmWindow *sf = get_focus_window();
 	rectangle icon_rect;
 	XWindowAttributes winattrs = {0};
@@ -2276,15 +2276,18 @@
 		SET_ICONIFY_AFTER_MAP(fw, 0);
 		return;
 	}
-	while (IS_ICONIFIED_BY_PARENT(fw))
+	for (ofw = NULL; fw != ofw && IS_ICONIFIED_BY_PARENT(fw); )
 	{
-		for (t = Scr.FvwmRoot.next; t != NULL; t = t->next)
+		t = get_transientfor_fvwmwindow(fw);
+		if (t != NULL)
 		{
-			if (t != fw && FW_W_TRANSIENTFOR(fw) == FW_W(t))
-			{
-				fw = t;
-			}
+			ofw = fw;
+			fw = t;
 		}
+	}
+	if (IS_ICONIFIED_BY_PARENT(fw))
+	{
+		SET_ICONIFIED_BY_PARENT(fw, 0);
 	}
 
 	/* AS dje  RaiseWindow(fw); */
