Revert b7ae07c34bb9172b8aba964023c2febc178f7f97, see
https://github.com/fvwmorg/fvwm3/issues/873

--- fvwm/ewmh_names.c.orig	2023-07-06 21:03:44 UTC
+++ fvwm/ewmh_names.c
@@ -125,14 +125,15 @@ int EWMH_WMIconName(
 {
 	int size = 0;
 	char *val;
-	char *text;
+	char *tmp_str;
+	FlocaleCharset *fc = NULL;
 
 	if (!FiconvSupport)
 	{
 		return 0;
 	}
 
-	text = val = ewmh_AtomGetByName(
+	val = ewmh_AtomGetByName(
 		FW_W(fw), "_NET_WM_ICON_NAME",
 		EWMH_ATOM_LIST_PROPERTY_NOTIFY, &size);
 
@@ -141,25 +142,28 @@ int EWMH_WMIconName(
 		SET_HAS_EWMH_WM_ICON_NAME(fw,0);
 		return 0;
 	}
-	if (IS_ICON_FONT_LOADED(fw) && fw->icon_font != NULL && fw->icon_font->fftf.fftfont[0] == NULL)
+	if (IS_ICON_FONT_LOADED(fw) && fw->icon_font != NULL)
 	{
-		text = FiconvUtf8ToCharset(dpy, fw->icon_font->str_fc, val, size);
-		free(val);
+		fc = fw->icon_font->str_fc;
 	}
-	if (text == NULL)
+
+	tmp_str = (char *)FiconvUtf8ToCharset(
+		dpy, fc, (const char *) val, size);
+	free(val);
+	if (tmp_str == NULL)
 	{
 		SET_HAS_EWMH_WM_ICON_NAME(fw, 0);
 		return 0;
 	}
-	if (strlen(text) > MAX_ICON_NAME_LEN)
+	if (strlen(tmp_str) > MAX_ICON_NAME_LEN)
 	{
-		text[MAX_ICON_NAME_LEN] = 0;
+		tmp_str[MAX_ICON_NAME_LEN] = 0;
 	}
 	SET_HAS_EWMH_WM_ICON_NAME(fw, 1);
-	if (fw->icon_name.name && strcmp(text, fw->icon_name.name) == 0)
+	if (fw->icon_name.name && strcmp(tmp_str, fw->icon_name.name) == 0)
 	{
 		/* migo: some apps update their names every second */
-		free(text);
+		free(tmp_str);
 		return 0;
 	}
 
@@ -169,7 +173,7 @@ int EWMH_WMIconName(
 		free_window_names(fw, False, True);
 	}
 
-	fw->icon_name.name = text;
+	fw->icon_name.name = tmp_str;
 
 	SET_WAS_ICON_NAME_PROVIDED(fw, 1);
 
@@ -189,13 +193,14 @@ int EWMH_WMName(
 {
 	int size = 0;
 	char *val;
-	char *text;
+	char *tmp_str;
+	FlocaleCharset *fc = NULL;
 	int what_changed;
 
 	if (!FiconvSupport)
 		return 0;
 
-	text = val = ewmh_AtomGetByName(
+	val = ewmh_AtomGetByName(
 		FW_W(fw), "_NET_WM_NAME",
 		EWMH_ATOM_LIST_PROPERTY_NOTIFY, &size);
 
@@ -204,25 +209,28 @@ int EWMH_WMName(
 		SET_HAS_EWMH_WM_NAME(fw,0);
 		return 0;
 	}
-	if (IS_WINDOW_FONT_LOADED(fw) && fw->title_font != NULL && fw->title_font->fftf.fftfont[0] == NULL)
+	if (IS_WINDOW_FONT_LOADED(fw) && fw->title_font != NULL)
 	{
-		text = FiconvUtf8ToCharset(dpy, fw->title_font->str_fc, val, size);
-		free(val);
+		fc = fw->title_font->str_fc;
 	}
-	if (text == NULL)
+
+	tmp_str = (char *)FiconvUtf8ToCharset(
+		dpy, fc, (const char *) val, size);
+	free(val);
+	if (tmp_str == NULL)
 	{
 		SET_HAS_EWMH_WM_NAME(fw,0);
 		return 0;
 	}
-	if (strlen(text) > MAX_WINDOW_NAME_LEN)
+	if (strlen(tmp_str) > MAX_WINDOW_NAME_LEN)
 	{
-		text[MAX_WINDOW_NAME_LEN] = 0;
+		tmp_str[MAX_WINDOW_NAME_LEN] = 0;
 	}
 	SET_HAS_EWMH_WM_NAME(fw, 1);
-	if (fw->name.name && strcmp(text, fw->name.name) == 0)
+	if (fw->name.name && strcmp(tmp_str, fw->name.name) == 0)
 	{
 		/* migo: some apps update their names every second */
-		free(text);
+		free(tmp_str);
 		return 0;
 	}
 
@@ -232,7 +240,7 @@ int EWMH_WMName(
 		free_window_names(fw, True, False);
 	}
 
-	fw->name.name = text;
+	fw->name.name = tmp_str;
 
 	if (ev == NULL)
 	{
