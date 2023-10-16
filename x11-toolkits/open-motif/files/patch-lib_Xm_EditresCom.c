--- lib/Xm/EditresCom.c.orig	2023-02-15 16:42:34.000000000 -0800
+++ lib/Xm/EditresCom.c	2023-10-16 20:14:52.602297000 -0700
@@ -183,6 +183,39 @@
 }
 #endif
 
+#define HAVE_XMU_GET_WIDGET_INFO_RESOLVE 1
+#ifdef HAVE_XMU_GET_WIDGET_INFO_RESOLVE
+static Boolean GetWidgetInfo(ProtocolStream *stream, WidgetInfo *info) {
+  return _XEditResGetWidgetInfoResolve(stream, info);
+}
+#else
+static Boolean GetWidgetInfo(ProtocolStream *stream, WidgetInfo *info) {
+  return _XEditResGetWidgetInfo(stream, info);
+}
+#endif
+
+#define HAVE_XMU_PUT_WIDGET_INFO_UNRESOLVE 1
+#ifdef HAVE_XMU_PUT_WIDGET_INFO_UNRESOLVE
+static void PutWidgetInfo(ProtocolStream *stream, WidgetInfo *info) {
+  _XEditResPutWidgetInfoUnresolve(stream, info);
+}
+#else
+static Boolean PutWidgetInfo(ProtocolStream *stream, WidgetInfo *info) {
+  _XEditResPutWidgetInfo(stream, info);
+}
+#endif
+
+#define HAVE_XMU_PUT_WIDGET_UNRESOLVE 1
+#ifdef HAVE_XMU_PUT_WIDGET_UNRESOLVE
+static void PutWidget(ProtocolStream *stream, Widget widget) {
+  _XEditResPutWidgetUnresolve(stream, widget);
+}
+#else
+static void PutWidget(ProtocolStream *stream, Widget widget) {
+  _XEditResPut32(stream, widget);
+}
+#endif
+
 /************************************************************
  *
  * Resource Editor Communication Code
@@ -352,7 +385,7 @@
 		XtCalloc(sizeof(WidgetInfo), sv_event->num_entries);
 	    
 	    for (i = 0; i < sv_event->num_entries; i++) {
-		if (!_XEditResGetWidgetInfo(stream, sv_event->widgets + i))
+		if (!GetWidgetInfo(stream, sv_event->widgets + i))
 		    goto done;
 	    }
 	}
@@ -364,7 +397,7 @@
 	    find_event->widgets = (WidgetInfo *) 
 		                  XtCalloc(sizeof(WidgetInfo), 1);
 
-	    if (!(_XEditResGetWidgetInfo(stream, find_event->widgets) &&
+	    if (!(GetWidgetInfo(stream, find_event->widgets) &&
 		  _XEditResGetSigned16(stream, &(find_event->x)) &&
 		  _XEditResGetSigned16(stream, &(find_event->y))))
 	    {
@@ -384,7 +417,7 @@
 	    get_event->widgets = (WidgetInfo *)
 		XtCalloc(sizeof(WidgetInfo), get_event->num_entries);
 	    for (i = 0; i < get_event->num_entries; i++) {
-		if (!_XEditResGetWidgetInfo(stream, get_event->widgets + i)) 
+		if (!GetWidgetInfo(stream, get_event->widgets + i))
 		    goto done;
 	    }
 	}
@@ -397,7 +430,7 @@
             _XEditResGet16(stream, &(gv_event->num_entries));
 	    gv_event->widgets = (WidgetInfo *)
 		XtCalloc(sizeof(WidgetInfo), gv_event->num_entries);
-            _XEditResGetWidgetInfo(stream, gv_event->widgets);
+            GetWidgetInfo(stream, gv_event->widgets);
         }
         break;	
 
@@ -846,7 +879,7 @@
 
     for (i = 0 ; i < sv_event->num_entries; i++) {
 	if ((str = VerifyWidget(w, &(sv_event->widgets[i]))) != NULL) {
-	    _XEditResPutWidgetInfo(stream, &(sv_event->widgets[i]));
+	    PutWidgetInfo(stream, &(sv_event->widgets[i]));
 	    _XEditResPutString8(stream, str);
 	    XtFree(str);
 	    count++;
@@ -973,7 +1006,7 @@
      */ 
 
     (*(info->count))++;
-    _XEditResPutWidgetInfo(info->stream, info->entry);
+    PutWidgetInfo(info->stream, info->entry);
     _XEditResPutString8(info->stream, pbuf);
     if (pbuf != buf)
 	XtFree(pbuf);
@@ -1174,7 +1207,7 @@
 	 * Send out the widget id. 
 	 */
 
-	_XEditResPutWidgetInfo(stream, &(geom_event->widgets[i]));
+	PutWidgetInfo(stream, &(geom_event->widgets[i]));
 	if ((str = VerifyWidget(w, &(geom_event->widgets[i]))) != NULL) {
 	    _XEditResPutBool(stream, True); /* an error occured. */
 	    _XEditResPutString8(stream, str);	/* set message. */
@@ -1420,7 +1453,7 @@
 	/* 
 	 * Send out the widget id. 
 	 */
-	_XEditResPutWidgetInfo(stream, &(res_event->widgets[i]));
+	PutWidgetInfo(stream, &(res_event->widgets[i]));
 	if ((str = VerifyWidget(w, &(res_event->widgets[i]))) != NULL) {
 	    _XEditResPutBool(stream, True); /* an error occured. */
 	    _XEditResPutString8(stream, str);	/* set message. */
@@ -1766,10 +1799,11 @@
 	
     _XEditResPut16(stream, num_widgets);	/* insert number of widgets. */
     for (i = 0; i < num_widgets; i++) /* insert Widgets themselves. */
-	_XEditResPut32(stream, widget_list[i]);
+	PutWidget(stream, (Widget)widget_list[i]);
     
     XtFree((char *)widget_list);
 }
+
 
 #if 0
 /************************************************************
