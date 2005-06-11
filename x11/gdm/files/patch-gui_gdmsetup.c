--- gui/gdmsetup.c.orig	Fri Jun 10 13:45:13 2005
+++ gui/gdmsetup.c	Sat Jun 11 16:13:11 2005
@@ -335,12 +335,12 @@ xservers_get_servers (GtkListStore *stor
 	for (li = list; li != NULL; li = li->next) {
         char *key = li->data;
 		int vt = atoi(key);
+		GtkTreeIter iter;
 		key = g_strconcat(GDM_KEY_SERVERS, "/", key, NULL);
 		cpy = ve_config_get_string (cfg, key);
 		server = ve_first_word (cpy);
 		options = ve_rest (cpy);
 		
-		GtkTreeIter iter;
 		gtk_list_store_append (store, &iter);
 		gtk_list_store_set (store, &iter,
 		                    XSERVER_COLUMN_VT, vt,
@@ -2075,16 +2075,19 @@ no_sound_cb (GtkWidget *widget, gpointer
 	const char *nosound_button;
 	const char *soundtest_button;
 	char *sound_key, *val, *config_val;
+	GtkWidget *acc_no_sound_file;
+	GtkWidget *acc_sound_test;
+	VeConfig *config;
 	
 	nosound_button = g_strconcat ("acc_nosound_", key, "_button", NULL);
 	soundtest_button = g_strconcat ("acc_soundtest_", key, "_button", NULL);
 
-	GtkWidget *acc_no_sound_file = glade_helper_get (xml, nosound_button,
+	acc_no_sound_file = glade_helper_get (xml, nosound_button,
 	                                                 GTK_TYPE_BUTTON);
-	GtkWidget *acc_sound_test = glade_helper_get (xml, soundtest_button,
+	acc_sound_test = glade_helper_get (xml, soundtest_button,
 	                                              GTK_TYPE_BUTTON);
 
-	VeConfig *config = ve_config_get (GDM_CONFIG_FILE);
+	config = ve_config_get (GDM_CONFIG_FILE);
 	gtk_label_set_text (GTK_LABEL (acc_sound_file_label), _("None"));
 	gtk_widget_set_sensitive (acc_no_sound_file, FALSE);
 	gtk_widget_set_sensitive (acc_sound_test, FALSE);
@@ -2120,17 +2123,20 @@ sound_response (GtkWidget *file_dialog, 
 
 	const char *nosound_button;
 	const char *soundtest_button;
+	GtkWidget *acc_no_sound_file;
+	GtkWidget *acc_sound_test;
 	nosound_button = g_strconcat("acc_nosound_",key,"_button",NULL);
 	soundtest_button = g_strconcat("acc_soundtest_",key,"_button",NULL);
 
-	GtkWidget *acc_no_sound_file = glade_helper_get (xml, nosound_button,
+	acc_no_sound_file = glade_helper_get (xml, nosound_button,
 		GTK_TYPE_BUTTON);
-	GtkWidget *acc_sound_test = glade_helper_get (xml, soundtest_button,
+	acc_sound_test = glade_helper_get (xml, soundtest_button,
 		GTK_TYPE_BUTTON);
 	if (response == GTK_RESPONSE_ACCEPT) {
 		VeConfig *config = ve_config_get (GDM_CONFIG_FILE);
 		char *filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (file_dialog));
 		char *val;
+		char* sound_key;
 
 		gtk_label_set_text (GTK_LABEL (acc_sound_file_label), filename);
 
@@ -2138,7 +2144,6 @@ sound_response (GtkWidget *file_dialog, 
 		gtk_widget_set_sensitive (acc_sound_test, TRUE);
 
 
-		char* sound_key;
 		if (strcmp (key, "ready") == 0 ) {
 			have_sound_ready_file = TRUE;
 			sound_key = g_strdup(GDM_KEY_SOUND_ON_LOGIN_READY_FILE);
@@ -2270,6 +2275,9 @@ setup_accessibility_support (void)
 	gchar *success_key = g_strdup("success");
 	gchar *failure_key = g_strdup("failure");
 	VeConfig *config = ve_config_get (GDM_CONFIG_FILE);
+	gboolean add_gtk_modules;
+	char *modules_list;
+	char *val;
 
 	g_object_set_data (G_OBJECT (acc_sound_ready_file_label), "key",
 	                   ready_key);
@@ -2278,12 +2286,10 @@ setup_accessibility_support (void)
 	g_object_set_data (G_OBJECT (acc_sound_failure_file_label), "key",
 	                   failure_key);
 
-	gboolean add_gtk_modules = ve_config_get_bool (config,
+	add_gtk_modules = ve_config_get_bool (config,
 	                                               GDM_KEY_ADD_GTK_MODULES);
-	char *modules_list = ve_config_get_string (config,
+	modules_list = ve_config_get_string (config,
 	                                           GDM_KEY_GTK_MODULES_LIST);
-	char *val;
-
 	if (add_gtk_modules &&
 	    modules_list_contains (modules_list, "gail") &&
 		modules_list_contains (modules_list, "atk-bridge") &&
@@ -2750,6 +2756,7 @@ selected_toggled (GtkCellRendererToggle 
 		/* Loop through all checkboxes */
 		while (gtk_tree_model_get_iter (model, &iter, path)) {
 			/* If this checkbox was just toggled */
+			gboolean selected = FALSE;
 			if (gtk_tree_path_compare (path, sel_path) == 0) {
 
 			gtk_tree_model_get (model, &selected_iter,
@@ -2766,7 +2773,6 @@ selected_toggled (GtkCellRendererToggle 
 				}
 			}
 	
-			gboolean selected = FALSE;
 			gtk_tree_model_get (model, &iter, THEME_COLUMN_SELECTED_LIST,
 				&selected, THEME_COLUMN_DIR, &theme_name, -1);
 	
@@ -3219,7 +3225,7 @@ theme_install_response (GtkWidget *choos
 		/* HACK! */
 		argv[0] = chown;
 		argv[1] = "-R";
-		argv[2] = "root:root";
+		argv[2] = "root:wheel";
 		argv[3] = quoted;
 		argv[4] = NULL;
 		simple_spawn_sync (argv);
@@ -3439,8 +3445,10 @@ xserver_entry_timeout (GtkWidget *entry)
 	GtkWidget *combobox = glade_helper_get (xml, "xserver_mod_combobox",
 	                                        GTK_TYPE_COMBO_BOX);
 	gchar *section = gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox));
-	section = g_strconcat(GDM_KEY_SERVER_PREFIX, section, "/", NULL);
 	const char *key = g_object_get_data (G_OBJECT (entry), "key");
+	const char *text = gtk_entry_get_text (GTK_ENTRY (entry));
+	VeConfig *cfg;
+	section = g_strconcat(GDM_KEY_SERVER_PREFIX, section, "/", NULL);
 
 	if (strcmp (key, GDM_KEY_SERVER_NAME) == 0)
 		section = g_strconcat(section, GDM_KEY_SERVER_NAME, NULL);
@@ -3448,10 +3456,9 @@ xserver_entry_timeout (GtkWidget *entry)
 		section = g_strconcat(section, GDM_KEY_SERVER_COMMAND, NULL);
 
 	/* Locate this server's section */
-	VeConfig *cfg = ve_config_get (GDM_CONFIG_FILE);
+	cfg = ve_config_get (GDM_CONFIG_FILE);
 
 	/* Update this servers configuration */
-	const char *text = gtk_entry_get_text (GTK_ENTRY (entry));
 	ve_config_set_string (cfg, section, ve_sure_string (text));
 	ve_config_save (cfg, FALSE /* force */);
 	g_free(section);
@@ -3466,8 +3473,10 @@ xserver_toggle_timeout (GtkWidget *toggl
 	GtkWidget *combobox = glade_helper_get (xml, "xserver_mod_combobox",
 	                                        GTK_TYPE_COMBO_BOX);
 	gchar *section = gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox));
-	section = g_strconcat(GDM_KEY_SERVER_PREFIX, section, "/", NULL);
 	const char *key = g_object_get_data (G_OBJECT (toggle), "key");
+	VeConfig *cfg;
+	gboolean val;
+	section = g_strconcat(GDM_KEY_SERVER_PREFIX, section, "/", NULL);
 
 	if (strcmp (key, GDM_KEY_SERVER_HANDLED) == 0)
 		section = g_strconcat(section, GDM_KEY_SERVER_HANDLED, NULL);
@@ -3477,8 +3486,8 @@ xserver_toggle_timeout (GtkWidget *toggl
 		section = g_strconcat(section, GDM_KEY_SERVER_CHOOSER, NULL);
 
 	/* Locate this server's section */
-	VeConfig *cfg = ve_config_get (GDM_CONFIG_FILE);
-	gboolean val = ve_config_get_bool (cfg, section);
+	cfg = ve_config_get (GDM_CONFIG_FILE);
+	val = ve_config_get_bool (cfg, section);
 
 	/* Update this servers configuration */
 	if ( ! ve_bool_equal (val, GTK_TOGGLE_BUTTON (toggle)->active)) {
@@ -3513,6 +3522,7 @@ static void
 xserver_populate_combobox(GtkComboBox* combobox)
 {
     gint i,j;
+    GSList *xservers;
 
 	/* Get number of items in combobox */
 	i = gtk_tree_model_iter_n_children(
@@ -3524,7 +3534,7 @@ xserver_populate_combobox(GtkComboBox* c
     }
 
     /* Populate combobox with list of current servers */
-	GSList *xservers = xservers_get_server_definitions();
+	xservers = xservers_get_server_definitions();
     g_slist_foreach(xservers, (GFunc) xserver_append_combobox, combobox);
 }
 
@@ -3608,13 +3618,14 @@ xserver_remove(gpointer data)
 
 	if (gtk_tree_selection_get_selected (selection, &model, &iter))
 	{
+		char *key;
 		/* Update config */
 		cfg = ve_config_get (GDM_CONFIG_FILE);
 		gtk_tree_model_get (model, &iter, XSERVER_COLUMN_VT, &vt, -1);
 
 
 		g_snprintf (vt_value,  sizeof (vt_value), "%d", vt);
-		char *key = g_object_get_data (G_OBJECT (combo), "key");
+		key = g_object_get_data (G_OBJECT (combo), "key");
 		key = g_strconcat (key, "/", vt_value, "=", NULL);
 		ve_config_delete_key (cfg, key);
     	ve_config_save (cfg, FALSE /* force */);
@@ -3634,6 +3645,8 @@ xserver_add(gpointer data)
 	GtkWidget *spinner, *combo, *entry, *button;
 	gchar *string;
 	char spinner_value[3];
+	char *key;
+	VeConfig *cfg;
 
 	/* Get Widgets from glade */
 	spinner      = glade_helper_get (xml, "xserver_spin_button",
@@ -3646,7 +3659,7 @@ xserver_add(gpointer data)
 		                                    GTK_TYPE_BUTTON);
 
 	/* Section in config to modify */
-	char *key = g_object_get_data (G_OBJECT (combo), "key");
+	key = g_object_get_data (G_OBJECT (combo), "key");
 
 	/* String to add to config */
 	g_snprintf (spinner_value,  sizeof (spinner_value), "%d", 
@@ -3658,7 +3671,7 @@ xserver_add(gpointer data)
 	                      NULL);
 
 	/* Add to config */
-	VeConfig *cfg = ve_config_get (GDM_CONFIG_FILE);
+	cfg = ve_config_get (GDM_CONFIG_FILE);
 	ve_config_set_string (cfg, key, ve_sure_string(string));
     ve_config_save (cfg, FALSE /* force */);
 
@@ -3685,6 +3698,10 @@ xserver_create(gpointer data)
 	GtkWidget *greeter_radio, *chooser_radio;
 	GtkWidget *create_button, *delete_button;
 
+	VeConfig *cfg;
+	gboolean success;
+	gint i;
+
 	/* Get Widgets from glade */
 	frame           = glade_helper_get (xml, "xserver_modify_frame",
 	                                    GTK_TYPE_FRAME);
@@ -3712,8 +3729,8 @@ xserver_create(gpointer data)
 
 	/* TODO: Create a new section for this server */
 	/* TODO: Write this value to the config and update xservers list */
-	VeConfig *cfg = ve_config_get (GDM_CONFIG_FILE);
-	gboolean success = FALSE;
+	cfg = ve_config_get (GDM_CONFIG_FILE);
+	success = FALSE;
 	/* success = ve_config_add_section (cfg, SECTION_NAME); */
 
 	if (success)
@@ -3735,7 +3752,7 @@ xserver_create(gpointer data)
 		                              FALSE);
 
 		/* Select the new server in the combobox */
-		gint i = gtk_tree_model_iter_n_children (
+		i = gtk_tree_model_iter_n_children (
 		   gtk_combo_box_get_model (GTK_COMBO_BOX (modify_combobox)), NULL) - 1;
 		gtk_combo_box_set_active (GTK_COMBO_BOX (modify_combobox), i);
 	}
