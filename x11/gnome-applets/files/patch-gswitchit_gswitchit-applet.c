--- gswitchit/gswitchit-applet.c.orig	Sun Aug  7 18:07:33 2005
+++ gswitchit/gswitchit-applet.c	Sun Aug  7 18:10:07 2005
@@ -331,6 +331,10 @@ GSwitchItAppletPrepareDrawing (GSwitchIt
 		XklConfigItem configItem;
 		GtkWidget *align, *label;
 		static GHashTable *shortDescrs = NULL;
+		gpointer pcounter = NULL; 
+		char *prevLayoutName = NULL;
+		char *labelTitle = NULL;
+		int counter = 0;
 		if (group == 0)
 			shortDescrs = g_hash_table_new_full (g_str_hash, g_str_equal,
 							     g_free, NULL);
@@ -363,10 +367,6 @@ GSwitchItAppletPrepareDrawing (GSwitchIt
 		if (layoutName == NULL)
 			layoutName = g_strdup ("?");
 
-		gpointer pcounter = NULL; 
-		char *prevLayoutName = NULL;
-		char *labelTitle = NULL;
-		int counter = 0;
 		if (g_hash_table_lookup_extended (shortDescrs, layoutName, 
 						  (gpointer*)&prevLayoutName, &pcounter))
 		{
@@ -599,6 +599,13 @@ GSwitchItAppletCmdPreview (BonoboUICompo
 		groupsLevels, groupsLevels + 1, groupsLevels + 2, groupsLevels + 3 };
 	XklState *xklState = XklGetCurrentState ();
 	gpointer p = g_hash_table_lookup (globals.previewDialogs, GINT_TO_POINTER (xklState->group));
+#ifdef HAVE_XKB
+	GladeXML *gladeData;
+	GtkWidget *dialog;
+	GtkWidget *kbdraw;
+	XkbComponentNamesRec componentNames;
+	XklConfigRec xklData;
+#endif
 	if (p != NULL)
 	{
 		/* existing window */
@@ -606,11 +613,10 @@ GSwitchItAppletCmdPreview (BonoboUICompo
 		return;
 	}
 #ifdef HAVE_XKB
-	GladeXML *gladeData = glade_xml_new (GNOME_GLADEDIR "/gswitchit.glade", "gswitchit_layout_view", NULL);
-        GtkWidget *dialog =
+	gladeData = glade_xml_new (GNOME_GLADEDIR "/gswitchit.glade", "gswitchit_layout_view", NULL);
+        dialog =
         	glade_xml_get_widget (gladeData, "gswitchit_layout_view");
-	GtkWidget *kbdraw = keyboard_drawing_new ();
-	XkbComponentNamesRec componentNames;
+	kbdraw = keyboard_drawing_new ();
 
 	if (xklState->group >= 0 && 
 	    xklState->group < g_slist_length (globals.groupNames))
@@ -624,7 +630,6 @@ GSwitchItAppletCmdPreview (BonoboUICompo
 
   	keyboard_drawing_set_groups_levels (KEYBOARD_DRAWING (kbdraw), pGroupsLevels);
 
-	XklConfigRec xklData;
 	XklConfigRecInit (&xklData);
       	if (XklConfigGetFromServer (&xklData))
 	{
