--- lib/libxview/panel/p_list.c.orig	Tue Jun 29 14:16:48 1993
+++ lib/libxview/panel/p_list.c	Sun Jan 10 01:47:42 1999
@@ -1239,7 +1239,7 @@
 	return ((Xv_opaque) dp->choose_one);
 
       case PANEL_ITEM_NTH_WINDOW:
-	if (*(int *) valist == 0)
+	if (va_arg(valist, int) == 0)
 	    return (Xv_opaque) dp->list_sb;
 	else
 	    return (Xv_opaque) NULL;
@@ -1266,7 +1266,7 @@
 	return (Xv_opaque) dp->list_sb;
 
       case PANEL_LIST_SELECTED:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	return (node ? (Xv_opaque) node->f.selected : (Xv_opaque) XV_ERROR);
 
@@ -1278,7 +1278,7 @@
 	return -1;	/* no rows selected */
 	
       case PANEL_LIST_NEXT_SELECTED:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	if (!node)
 	    return -1;	/* specified row doesn't exist */
@@ -1289,7 +1289,7 @@
 	return -1;	/* no subsequent row selected */
 
       case PANEL_LIST_CLIENT_DATA:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	return (node ? (Xv_opaque) node->client_data : (Xv_opaque) XV_ERROR);
 
@@ -1297,7 +1297,7 @@
 #ifdef OW_I18N
       case PANEL_LIST_STRING_WCS:
 #endif
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 #ifdef OW_I18N
 	if (node != NULL)
@@ -1312,7 +1312,7 @@
 #endif /* OW_I18N */
 
       case PANEL_LIST_GLYPH:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	return (node ? (Xv_opaque) node->glyph : (Xv_opaque) XV_ERROR);
 
@@ -1328,7 +1328,7 @@
 #endif /* OW_I18N */
 
       case PANEL_LIST_FONT:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	return (node ? (Xv_opaque) node->font : (Xv_opaque) XV_ERROR);
 
@@ -1352,7 +1352,7 @@
 
 
     case PANEL_LIST_INACTIVE:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	return (node ? (Xv_opaque) node->f.row_inactive : (Xv_opaque) XV_ERROR);
 
@@ -1407,7 +1407,7 @@
     }
 
     case PANEL_LIST_EXTENSION_DATA:
-	row = *(int *) valist;
+	row = va_arg(valist, int);
 	node = find_or_create_nth_row(dp, row, FALSE);
 	return (node ? (Xv_opaque) node->exten_data : (Xv_opaque) XV_ERROR);
 
@@ -3789,7 +3789,7 @@
 
     /* weigh timeval's against multiclick-timeout resource */
     is_multiclick = panel_is_multiclick(ip->panel, 
-					dp->last_click_row->click_time,
+					&dp->last_click_row->click_time,
 					&event_time(event)
 					);
 
