--- main.c.orig	Wed Jun 23 11:39:35 2004
+++ main.c	Wed Jun 23 11:54:03 2004
@@ -75,15 +75,18 @@
 
 void apply_new_look(gboolean is_preview)
 {
+	FILE *gtkrc_fh;
+	gchar *include_file;
+	gchar *default_files[2];
 	if(!themename) return;
 
 	cleanup_temporary();
 
-	FILE *gtkrc_fh = is_preview
+	gtkrc_fh = is_preview
 		? fdopen(g_file_open_tmp("gtkrc.preview-XXXXXXXX", &tmp_rc, NULL), "w+")
 		: fopen(gtkrc, "w");
 
-	gchar *include_file = g_hash_table_lookup(hash, themename);
+	include_file = g_hash_table_lookup(hash, themename);
 
 	fprintf(gtkrc_fh,
 		"# -- THEME AUTO-WRITTEN DO NOT EDIT\n" "include \"%s\"\n\n",
@@ -101,7 +104,8 @@
 	fprintf(gtkrc_fh, "# -- THEME AUTO-WRITTEN DO NOT EDIT\n");
 	fclose(gtkrc_fh);
 
-	gchar *default_files[] = { is_preview ? tmp_rc : gtkrc, NULL };
+	default_files[0] = is_preview ? tmp_rc : gtkrc;
+	default_files[1] = NULL;
 	gtk_rc_set_default_files(default_files);
 
 	if (is_preview)
