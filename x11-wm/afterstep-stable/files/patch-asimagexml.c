$FreeBSD$

--- libAfterImage/asimagexml.c.orig	Wed May  4 14:13:19 2005
+++ libAfterImage/asimagexml.c	Wed May  4 14:13:54 2005
@@ -268,7 +268,7 @@
 	ASImage* im = NULL;
 	xml_elem_t* doc;
 	ASImageManager *my_imman = imman, *old_as_xml_imman = _as_xml_image_manager ;
-	ASFontManager  *my_fontman = fontman, *old_as_xml_fontman = _as_xml_font_manager ; ;
+	ASFontManager  *my_fontman = fontman, *old_as_xml_fontman = _as_xml_font_manager ;
 	int my_imman_curr_dir_path_idx = MAX_SEARCH_PATHS ;
 
     asxml_var_init();
