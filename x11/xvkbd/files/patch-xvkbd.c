diff -urN -x .svn ../../vendor/xvkbd/xvkbd.c ./xvkbd.c
--- ../../vendor/xvkbd/xvkbd.c	2008-05-28 23:43:41.000000000 +0300
+++ ./xvkbd.c	2008-05-29 00:38:40.000000000 +0300
@@ -346,7 +346,7 @@
   { "keyFile", "KeyFile", XtRString, sizeof(char *),
     Offset(key_file), XtRImmediate, ".xvkbd" },
   { "dictFile", "DictFile", XtRString, sizeof(char *),
-    Offset(dict_file), XtRImmediate, "/usr/dict/words" },
+    Offset(dict_file), XtRImmediate, "/usr/share/dict/words" },
   { "customizations", "Customizations", XtRString, sizeof(char *),
     Offset(customizations), XtRImmediate, "default" },
   { "editableFunctionKeys", "EditableFunctionKeys", XtRInt, sizeof(int),
@@ -1154,7 +1154,7 @@
  * via xvkbd can be listed, and choosing one of them will send the
  * suffix to the clients.
  * Words for completion will be read from dictionary file specified
- * with xvkbd.dictFile resource, such as /usr/dict/words.
+ * with xvkbd.dictFile resource, such as /usr/share/dict/words.
  */
 static Widget completion_panel = None;
 static Widget completion_entry = None;
@@ -1350,11 +1350,12 @@
 	if ('1' <= *cp && *cp <= '9') {
 	  usleep((*cp - '0') * 100000);
 	} else {
-          fprintf(stderr, "%s: no digit after \"\\m\"\n",
+          fprintf(stderr, "%s: no digit after \"\\D\"\n",
                   PROGRAM_NAME);
 	}
 	break;
       case 'm':  /* simulate click mouse button */
+#ifdef USE_XTEST
 	cp++;
 	if ('1' <= *cp && *cp <= '9') {
 	  if (appres.debug) fprintf(stderr, "XTestFakeButtonEvent(%d)\n", *cp - '0');
@@ -1365,10 +1366,18 @@
           fprintf(stderr, "%s: no digit after \"\\m\"\n",
                   PROGRAM_NAME);
 	}
+#else
+      fprintf(stderr, "%s: this binary is compiled without XTEST support\n",
+	      PROGRAM_NAME);
+#endif
 	break;
       case 'x':
       case 'y':  /* move mouse pointer */
-	sscanf(cp + 1, "%d", &val);
+	if (sscanf(cp + 1, "%d", &val) != -1) {
+	  fprintf(stderr, "%s: no number after \"\\%c\"\n",
+                  PROGRAM_NAME, *cp);
+	  break;
+	}
 	target_root = RootWindow(target_dpy, DefaultScreen(target_dpy));
 	XQueryPointer(target_dpy, target_root, &junk_w, &child,
 		      &cur_x, &cur_y, &junk_i, &junk_i, &junk_u);
@@ -1436,7 +1445,7 @@
   char name1[50];
   Widget w;
 
-  sprintf(name1, "*%s", name);
+  snprintf(name1, sizeof(name1), "*%s", name);
   w = XtNameToWidget(toplevel, name1);
   if (w != None) {
     if (strstr(name, "Focus") != NULL) {
@@ -1660,7 +1669,7 @@
 
   XtVaGetValues(w, XtNx, &x0, XtNy, &y0, NULL);
   XGetGeometry(dpy, XtWindow(w), &root, &x1, &y1, &wd, &ht, &bd, &dp);
-  sprintf(geom, "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
+  snprintf(geom, sizeof(geom), "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
 
   return geom;
 }
@@ -1680,7 +1689,7 @@
 
   if (strcmp(key, "default") != 0) {
     sscanf(key, "%29[^/]/%29s", customization, lang);
-    sprintf(name, "XVkbd-%s", customization);
+    snprintf(name, sizeof(name), "XVkbd-%s", customization);
     xenv = XtResolvePathname(dpy, "app-defaults", name, NULL, NULL, NULL, 0, NULL);
     if (xenv == NULL) {
       fprintf(stderr, "%s: app-default file \"%s\" not installed\n",
@@ -1940,7 +1949,7 @@
   focused_subwindow = None;
   if (target_dpy != NULL && target_dpy != dpy) XCloseDisplay(target_dpy);
 
-  strncpy(name, (display_name == NULL) ? "" : display_name, sizeof(name));
+  snprintf(name, sizeof(name), "%s", (display_name == NULL) ? "" : display_name);
   for (cp = name; isascii(*cp) && isprint(*cp); cp++) ;
   *cp = '\0';
 
@@ -2423,7 +2432,7 @@
   XtAddCallback(w, XtNcallback, (XtCallbackProc)KeyPressed, (XtPointer)name);
 
   if (label != NULL) {
-    strncpy(str, label, sizeof(str) - 1);
+    snprintf(str, sizeof(str), "%s", label);
     if (strcmp(str, "space") == 0) strcpy(str, "");
     len = strlen(str);
     if (3 <= len) {
@@ -2495,9 +2504,9 @@
 	       || (strncmp(keypad_shift[row][col], "KP_", 3) == 0
 		   && isdigit(keypad_shift[row][col][3])))
 	color = appres.general_background;
-      strcpy(name, keypad[row][col]);
+      snprintf(name, sizeof(name), "%s", keypad[row][col]);
       if (strcmp(name, "Focus") != 0 && strcmp(name, "Num_Lock") != 0)
-	sprintf(name, "pad%d,%d", row, col);
+	snprintf(name, sizeof(name), "pad%d,%d", row, col);
       key = MakeKey(keypad_box, XtNewString(name),
 		    keypad_label[row][col], color);
       XtVaSetValues(key, XtNfont, font, NULL);
@@ -2622,7 +2631,7 @@
   first_row = appres.function_key ? 0 : 1;
   if (!appres.keypad_only) {
     for (row = first_row; row < NUM_KEY_ROWS; row++) {
-      sprintf(name, "row%d", row);
+      snprintf(name, sizeof(name), "row%d", row);
       key_box[row] = XtVaCreateManagedWidget(name, formWidgetClass, form, NULL);
       if (row != first_row)
         XtVaSetValues(key_box[row], XtNfromVert, key_box[row - 1], NULL);
@@ -2631,7 +2640,7 @@
         
       left = None;
       for (col = 0; keys_normal[row][col] != NULL; col++) {
-        strcpy(name, keys_normal[row][col]);
+	snprintf(name, sizeof(name), "%s", keys_normal[row][col]);
 	if (strcmp(name, "MainMenu") == 0) {
 	  Widget iconify_button = None;
 
@@ -2673,7 +2682,7 @@
 	    color = appres.general_background;
 	    font = appres.general_font;
 	    if (isalpha(name[0])) font = appres.letter_font;
-	    if (strcmp(name, "space") != 0) sprintf(name, "%d,%d", row, col);
+	    if (strcmp(name, "space") != 0) snprintf(name, sizeof(name), "%d,%d", row, col);
 	  }
 	  key = MakeKey(key_box[row], XtNewString(name), label, color);
 	  XtVaGetValues(key, XtNwidth, &wd, NULL);
@@ -2834,17 +2843,18 @@
   home = getenv("HOME");
   if (appres.key_file[0] != '/' && home != NULL
       && strlen(home) + strlen(appres.key_file) + 1 < sizeof(fkey_filename))
-    sprintf(fkey_filename, "%s/%s", home, appres.key_file);
+    snprintf(fkey_filename, sizeof(fkey_filename), "%s/%s", home, appres.key_file);
   else
-    strncpy(fkey_filename, appres.key_file, sizeof(fkey_filename));
+    snprintf(fkey_filename, sizeof(fkey_filename), "%s", appres.key_file);
 
   fp = fopen(fkey_filename, "r");
   if (fp == NULL) return;
 
   while (fgets(str, sizeof(str) - 1, fp)) {
     if (str[0] == '#') {
-      sscanf(&str[1], "%s %d", key, &val);
-      if (strcmp(key, "quick_modifiers") == 0)
+      if (sscanf(&str[1], "%s %d", key, &val) != 2)
+	fprintf(stderr, "%s: bad function key '%s'\n", PROGRAM_NAME, str + 1);
+      else if (strcmp(key, "quick_modifiers") == 0)
 	appres.quick_modifiers = val;
       else if (strcmp(key, "shift_lock") == 0)
 	appres.shift_lock = val;
@@ -2913,9 +2923,9 @@
   if (key == NULL)
     strcpy(key2, "");
   else if (strncmp(key, "Shift-", strlen("Shift-")) == 0)
-    sprintf(key2, "s:%s", &key[strlen("Shift-")]);
+    snprintf(key2, sizeof(key2), "s:%s", &key[strlen("Shift-")]);
   else
-    strcpy(key2, key);
+    snprintf(key2, sizeof(key2), "%s", key);
 
   if (strcmp(cur_fkey, key2) != 0) {
     if (strlen(cur_fkey) != 0) {
@@ -2958,10 +2968,10 @@
       FKeyValueMenuSelected(None, (value[0] == '!') ? "command" : "string");
 
       if (value[0] == '!' || value[0] == '\\') value = value + 1;
-      strncpy(fkey_value, value, sizeof(fkey_value) - 1);
+      snprintf(fkey_value, sizeof(fkey_value), "%s", value);
       XtVaSetValues(fkey_value_entry, XtNstring, fkey_value, NULL);
 
-      strcpy(cur_fkey, key2);
+      snprintf(cur_fkey, sizeof(cur_fkey), "%s", key2);
     }
   }
 }
@@ -3020,9 +3030,9 @@
     for (j = 0; j <= 1; j++) {
       for (i = 1; i <= appres.editable_function_keys; i++) {
 	if (j == 0)
-	  sprintf(label, "F%d", i);
+	  snprintf(label, sizeof(label), "F%d", i);
 	else 
-	  sprintf(label, "Shift-F%d", i);
+	  snprintf(label, sizeof(label), "Shift-F%d", i);
 	key = XtNewString(label);
 	menu_entry = XtVaCreateManagedWidget(key, smeBSBObjectClass, menu, NULL);
 	XtAddCallback(menu_entry, XtNcallback, (XtCallbackProc)FKeyMenuSelected,
@@ -3084,8 +3094,8 @@
     else if (shift_state & ControlMask) prefix = 'c';
     else if (shift_state & ShiftMask) prefix = 's';
   }
-  if (prefix == '\0') sprintf(label, "%s", key);
-  else sprintf(label, "%c:%s", prefix, key);
+  if (prefix == '\0') snprintf(label, sizeof(label), "%s", key);
+  else snprintf(label, sizeof(label), "%c:%s", prefix, key);
   len = strlen(label);
   
   for (sp = fkey_list; sp != NULL; sp = sp->next) {
@@ -3143,8 +3153,10 @@
 {
   StopAutoclick();
 
+#ifdef USE_XTEST
   XTestFakeButtonEvent(target_dpy, 1, True, CurrentTime);
   XTestFakeButtonEvent(target_dpy, 1, False, CurrentTime);
+#endif
 }
 
 static void ShowBalloon(Widget w, XEvent *event, String *pars, Cardinal *n_pars)
@@ -3447,7 +3459,7 @@
     } else {
       s = locale;
     }
-    strncpy(cur_locale, s, sizeof(cur_locale) - 1);
+    snprintf(cur_locale, sizeof(cur_locale), "%s", s);
     return old_locale;
   } else {
     return cur_locale;
