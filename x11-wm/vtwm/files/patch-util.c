Index: util.c
@@ -1211,7 +1211,7 @@
 	if (!font->name)
 	    font->name = Scr->DefaultFont.name;
 	if ((basename2 = (char *)malloc(strlen(font->name) + 3)))
-	    sprintf(basename2, "%s,*", font->name);
+	    sprintf(basename2, "%s*", font->name);
 	else
 	    basename2 = font->name;
 	if ((font->fontset = XCreateFontSet(dpy, basename2,
@@ -1223,7 +1223,7 @@
 
 	    if ((basename3 = (char *)realloc(basename2,
 					strlen(Scr->DefaultFont.name) + 3)))
-		sprintf(basename3, "%s,*", Scr->DefaultFont.name);
+		sprintf(basename3, "%s*", Scr->DefaultFont.name);
 	    else
 	    {
 		basename3 = Scr->DefaultFont.name;
@@ -1249,8 +1249,8 @@
 	    free(basename2);
 
 	for (i = 0; i < missing_charset_count_return; i++)
-	    fprintf(stderr, "%s: font for charset %s is lacking\n",
-		   ProgramName, missing_charset_list_return[i]);
+	    fprintf(stderr, "%s: font(%s) for charset %s is lacking\n",
+		   ProgramName, font->name, missing_charset_list_return[i]);
 
 	font_extents = XExtentsOfFontSet(font->fontset);
 	fnum = XFontsOfFontSet(font->fontset, &xfonts, &font_names);
