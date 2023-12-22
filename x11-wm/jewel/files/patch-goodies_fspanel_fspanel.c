--- goodies/fspanel/fspanel.c.orig	2005-01-03 21:54:58 UTC
+++ goodies/fspanel/fspanel.c
@@ -179,7 +179,7 @@ void turn_off_strut()
   	XDeleteProperty(dd, win, net_wm_strut);
 }
 
-void *get_prop_data (Window win, Atom prop, Atom type, int *items)
+unsigned long*get_prop_data (Window win, Atom prop, Atom type, int *items)
 {
 	Atom type_ret;
 	int format_ret;
@@ -195,7 +195,7 @@ void *get_prop_data (Window win, Atom prop, Atom type,
 	if (items)
 		*items = items_ret;
 
-	return prop_data;
+	return (unsigned long *)prop_data;
 }
 
 void get_task_hinticon (task *tk)
@@ -393,7 +393,8 @@ void scale_icon (task *tk)
 
 void scale_icon (task *tk)
 {
-	int xx, yy, x, y, w, h, d, bw;
+	int xx, yy, x, y;
+	unsigned int w, h, d, bw;
 	Pixmap pix, mk = None;
 	XGCValues gcv;
 	GC mgc=None;
@@ -746,7 +747,7 @@ taskbar *gui_create_taskbar (void)
 
 	XMapWindow (dd, win);
 
-	tb = calloc (1, sizeof (taskbar));
+	tb = (taskbar *)calloc (1, sizeof (taskbar));
 	tb->win = win;
 	
 	return tb;
@@ -760,10 +761,10 @@ void add_task (taskbar * tb, Window win, int focus)
 	if (tb->my_desktop != find_desktop (win) || is_hidden (win))
 		return;
 
-	tk = calloc (1, sizeof (task));
+	tk = (task *)calloc (1, sizeof (task));
 	tk->win = win;
 	tk->focused = focus;
-	tk->name = get_prop_data (win, XA_WM_NAME, XA_STRING, 0);
+	tk->name = (char *)(void *)get_prop_data (win, XA_WM_NAME, XA_STRING, 0);
 	tk->iconified = is_iconified (win);
 
 	get_task_kdeicon (tk);
@@ -1075,7 +1076,7 @@ void handle_propertynotify (taskbar * tb, Window win, 
 		/* window's title changed */
 		if (tk->name)
 			XFree (tk->name);
-		tk->name = get_prop_data (tk->win, XA_WM_NAME, XA_STRING, 0);
+		tk->name = (char *)(void *)get_prop_data (tk->win, XA_WM_NAME, XA_STRING, 0);
 		gui_draw_task (tb, tk);
 	} else if (at == atom_WM_STATE)
 	{
