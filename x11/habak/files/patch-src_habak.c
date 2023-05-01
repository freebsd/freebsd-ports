--- src/habak.c.orig	2022-08-30 10:28:37 UTC
+++ src/habak.c
@@ -22,7 +22,7 @@ struct stat file_info;
 double xco,yco;
 DATA32 *raw_data;
 
-int i, multy;
+int multy;
 Imlib_Image workspace;
 habak_t template_habak;
 
@@ -197,7 +197,7 @@ template_habak.text=DEFAULT_TEXT;
 
 if (argc==1) {print_help(0);}
 
-for (i=1;i<argc;i++) {
+for (int i=1;i<argc;i++) {
 	if (!strcmp(argv[i],"-mC")) {
 		d("parse center");
 		template_habak.center=MOD_CENTER;
@@ -515,7 +515,7 @@ switch (current_list_item->data.type) {
 	imlib_context_set_image(current_list_item->data.image);
 	imlib_image_set_has_alpha(1);
 	imlib_context_set_color(current_list_item->data.red,current_list_item->data.green,current_list_item->data.blue,current_list_item->data.alpha);
-	for (i=0;i<scr->height;i+=2) {
+	for (int i=0;i<scr->height;i+=2) {
 		imlib_image_draw_line(0,i,current_list_item->data.width,i,0);
 	}
 	/* OK, mamy gotowy obraz. Poniewa¿ jest to teraz tak naprawdê _obraz_, to
@@ -533,7 +533,7 @@ switch (current_list_item->data.type) {
 	imlib_context_set_image(current_list_item->data.image);
 	imlib_image_set_has_alpha(1);
 	imlib_context_set_color(current_list_item->data.red,current_list_item->data.green,current_list_item->data.blue,current_list_item->data.alpha);
-	for (i=1;i<scr->height;i+=2) {imlib_image_draw_line(0,i,current_list_item->data.width,i,0);}
+	for (int i=1;i<scr->height;i+=2) {imlib_image_draw_line(0,i,current_list_item->data.width,i,0);}
 	/* OK, mamy gotowy obraz. Poniewa¿ jest to teraz tak naprawdê _obraz_, to
 	 * mo¿na zmieniæ jego typ na "IMAGE_HABAK"
 	 */
@@ -561,7 +561,7 @@ switch (current_list_item->data.type) {	
 	imlib_context_set_font(current_list_item->data.font);
 	multxt=current_list_item->data.text;
 	multy=current_list_item->data.y;
-	while (multxt10=strchr(multxt,10)) {
+	while ((multxt10=strchr(multxt,10))) {
 		*multxt10=0;
 		imlib_text_draw(current_list_item->data.x,multy,multxt);
 		*multxt10=10;
