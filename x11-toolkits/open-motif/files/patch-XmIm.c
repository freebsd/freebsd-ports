--- lib/Xm/XmIm.c.orig	Fri Sep  7 10:11:01 2001
+++ lib/Xm/XmIm.c	Sat Sep  8 03:44:14 2001
@@ -479,6 +479,7 @@
       im_info->current_widget = w;
       XtVaGetValues(w, XmNbackground, &bg, NULL);
       XtVaSetValues(p, XmNbackground, bg, NULL);
+      ImGeoReq(p);
       draw_separator(p);
     }
   _XmAppUnlock(app);
@@ -1272,6 +1273,7 @@
       XtAddEventHandler(p, (EventMask)mask, False, null_proc, NULL);
     }
     if (XtIsRealized(p)) {
+      im_info->current_widget = w;
       if (XmIsDialogShell(p)) {
 	for (i = 0; 
 	     i < ((CompositeWidget)p)->composite.num_children; 
@@ -1282,7 +1284,6 @@
 	  }
       } else
 	ImGeoReq(p);
-      im_info->current_widget = w;
     }
     /* Is this new XIC supposed to be shared? */
     switch (input_policy)
@@ -2047,10 +2048,18 @@
 	  rect_preedit.height = icp->sp_height;
         } else if ((use_plist = (icp->input_style & XIMPreeditPosition)) != 0)
         {
-          unsigned int  margin = ((XmPrimitiveWidget)im_info->current_widget)
-                                ->primitive.shadow_thickness
-                            + ((XmPrimitiveWidget)im_info->current_widget)
-                                ->primitive.highlight_thickness;
+	  unsigned int	margin;
+	  /*
+	   * im_info->current_widget eventually contains NULL,
+	   * for example, when widget having XIC focus is disposed.
+	   * Thus, we should check this and prevent from touching NULL pointer.
+	   */
+	  if (im_info->current_widget == NULL)
+	    break;
+          margin = ((XmPrimitiveWidget)im_info->current_widget)
+	  	  ->primitive.shadow_thickness
+	      + ((XmPrimitiveWidget)im_info->current_widget)
+	  	  ->primitive.highlight_thickness;
 
           rect_preedit.width = MIN(icp->preedit_width,
                   XtWidth(im_info->current_widget) - 2*margin);
