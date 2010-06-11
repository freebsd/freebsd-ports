Description: Assorted compilation and usage fixes.
 - fix a lot of compiler warnings
 - unbreak the build if XTEST is not selected
 - use snprintf() instead of sprintf() and strcpy(), just in case
 - fix the text of an error message
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-06-11

--- xvkbd.c.orig
+++ xvkbd.c
@@ -460,8 +460,8 @@
 static int altgr_mask = 0;
 static KeySym altgr_keysym = NoSymbol;
 
-static int shift_state = 0;
-static int mouse_shift = 0;
+static unsigned int shift_state = 0;
+static unsigned int mouse_shift = 0;
 
 static Display *target_dpy = NULL;
 
@@ -472,7 +472,7 @@
 static Pixmap xvkbd_pixmap = None;
 
 static int AddKeysym(KeySym keysym, Boolean top);  /* forward */
-static void SendString(const unsigned char *str);
+static void SendString(const char *str);
 static void MakeKeyboard(Boolean remake);
 static void MakeKeypad(Widget form, Widget from_vert, Widget from_horiz);
 static void MakeSunFunctionKey(Widget form, Widget from_vert, Widget from_horiz);
@@ -481,6 +481,8 @@
 static void PopupFunctionKeyEditor(void);
 static void DeleteWindowProc(Widget w, XEvent *event, String *pars, Cardinal *n_pars);
 
+static void SignalUser1(int sig);
+
 /*
  * Search for window which has specified instance name (WM_NAME)
  * or class name (WM_CLASS).
@@ -489,8 +491,7 @@
 {
   Window w;
   Window *children, dummy;
-  unsigned int nchildren;
-  int i;
+  unsigned int nchildren, i;
   XClassHint hint;
   char *win_name;
 
@@ -774,7 +775,9 @@
  */
 static void SendEvent(XKeyEvent *event)
 {
+#ifdef USE_XTEST
   static Boolean first = TRUE;
+#endif
 
   if (!appres.no_sync) {
     XSync(event->display, FALSE);
@@ -1055,11 +1058,11 @@
 
 #ifdef USE_XTEST
   if (appres.xtest) {
-    Window root, child;
+    Window troot, child;
     int root_x, root_y, x, y;
     unsigned int mask;
 
-    XQueryPointer(target_dpy, event.root, &root, &child, &root_x, &root_y, &x, &y, &mask);
+    XQueryPointer(target_dpy, event.root, &troot, &child, &root_x, &root_y, &x, &y, &mask);
 
     event.type = KeyRelease;
     event.state = 0;
@@ -1209,7 +1212,7 @@
 
 static void SetDefaultDictionary(void)
 {
-  strncpy(dict_filename, appres.dict_file, sizeof(dict_filename));
+  snprintf(dict_filename, sizeof(dict_filename), "%s", appres.dict_file);
   XtVaSetValues(props_dict_entry, XtNstring, dict_filename, NULL);
 }
 
@@ -1224,7 +1227,7 @@
   struct WORDLIST *p;
 
   if (strcmp(cur_dict_filename, dict_filename) == 0) return;
-  strcpy(cur_dict_filename, dict_filename);
+  snprintf(cur_dict_filename, sizeof(cur_dict_filename), "%s", dict_filename);
 
   if (!first) {
     int cnt = 0;
@@ -1274,7 +1277,7 @@
 
 static void AddToCompletionText(KeySym keysym)
 {
-  int len;
+  size_t len;
   struct WORDLIST *node_ptr;
 
   if (completion_entry != None) {
@@ -1364,7 +1367,7 @@
 
   ReadCompletionDictionary();
 
-  sprintf(msg, "%d words in the dictionary", n_completion_words);
+  snprintf(msg, sizeof(msg), "%d words in the dictionary", n_completion_words);
   XtVaSetValues(completion_entry, XtNlabel, msg, NULL);
 
   completion_text[0] = '\0';
@@ -1379,11 +1382,11 @@
  */
 static void KeyPressed(Widget w, char *key, char *data);
 
-static void SendString(const unsigned char *str)
+static void SendString(const char *str)
 {
-  const unsigned char *cp, *cp2;  /* I remember "unsigned" might be required for some systems */
+  const char *cp, *cp2;
   char key[50];
-  int len;
+  size_t len;
   int val;
   Window target_root, child, junk_w;
   int junk_i;
@@ -1408,8 +1411,7 @@
         } else {
           len = cp2 - cp - 1;
           if (sizeof(key) <= len) len = sizeof(key) - 1;
-          strncpy(key, cp + 1, len);
-          key[len] = '\0';
+          snprintf(key, sizeof(key), "%s", cp + 1);
           KeyPressed(None, key, NULL);
           cp = cp2;
         }
@@ -1429,11 +1431,12 @@
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
@@ -1444,10 +1447,18 @@
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
@@ -1515,7 +1526,7 @@
   char name1[50];
   Widget w;
 
-  sprintf(name1, "*%s", name);
+  snprintf(name1, sizeof(name1), "*%s", name);
   w = XtNameToWidget(toplevel, name1);
   if (w != None) {
     if (strstr(name, "Focus") != NULL) {
@@ -1544,13 +1555,13 @@
 static void RefreshShiftState(Boolean force)
 {
   static Boolean first = TRUE;
-  static int last_shift_state = 0;
-  static int last_mouse_shift = 0;
+  static unsigned int last_shift_state = 0;
+  static unsigned int last_mouse_shift = 0;
   static int last_num_lock_state = FALSE;
   static Display *last_target_dpy = NULL;
-  static long last_focus = 0;
-  int cur_shift;
-  int changed;
+  static Window last_focus = 0;
+  unsigned int cur_shift;
+  unsigned int changed;
   int first_row, row, col;
   Boolean shifted;
   char *label;
@@ -1641,7 +1652,7 @@
 
     Window root, child;
     int root_x, root_y, x, y;
-    unsigned int mask;
+    unsigned int tmask;
 
     XKeyEvent event;
 
@@ -1657,28 +1668,28 @@
     event.same_screen = TRUE;
     event.state = 0;
 
-    XQueryPointer(target_dpy, event.root, &root, &child, &root_x, &root_y, &x, &y, &mask);
+    XQueryPointer(target_dpy, event.root, &root, &child, &root_x, &root_y, &x, &y, &tmask);
 
     if (strstr(appres.positive_modifiers, "shift") != NULL
-	&& (shift_state & ShiftMask) != (mask & ShiftMask)) {
+	&& (shift_state & ShiftMask) != (tmask & ShiftMask)) {
       event.keycode = XKeysymToKeycode(target_dpy, XK_Shift_L);
       event.type = (shift_state & ShiftMask) ? KeyPress : KeyRelease;
       SendEvent(&event);
     }
     if (strstr(appres.positive_modifiers, "control") != NULL
-	&& (shift_state & ControlMask) != (mask & ControlMask)) {
+	&& (shift_state & ControlMask) != (tmask & ControlMask)) {
       event.keycode = XKeysymToKeycode(target_dpy, XK_Control_L);
       event.type = (shift_state & ControlMask) ? KeyPress : KeyRelease;
       SendEvent(&event);
     }
     if (strstr(appres.positive_modifiers, "alt") != NULL
-	&& (shift_state & alt_mask) != (mask & alt_mask)) {
+	&& (shift_state & alt_mask) != (tmask & alt_mask)) {
       event.keycode = XKeysymToKeycode(target_dpy, XK_Alt_L);
       event.type = (shift_state & alt_mask) ? KeyPress : KeyRelease;
       SendEvent(&event);
     }
     if (strstr(appres.positive_modifiers, "meta") != NULL
-	&& (shift_state & meta_mask) != (mask & meta_mask)) {
+	&& (shift_state & meta_mask) != (tmask & meta_mask)) {
       event.keycode = XKeysymToKeycode(target_dpy, XK_Meta_L);
       event.type = (shift_state & meta_mask) ? KeyPress : KeyRelease;
       SendEvent(&event);
@@ -1739,7 +1750,7 @@
 
   XtVaGetValues(w, XtNx, &x0, XtNy, &y0, NULL);
   XGetGeometry(dpy, XtWindow(w), &root, &x1, &y1, &wd, &ht, &bd, &dp);
-  sprintf(geom, "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
+  snprintf(geom, sizeof(geom), "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
 
   return geom;
 }
@@ -1801,7 +1812,7 @@
   if (key != NULL) {
     if (strcmp(key, "default") != 0) {
       sscanf(key, "%29[^/]/%29s", customization, lang);
-      sprintf(name, "XVkbd-%s", customization);
+      snprintf(name, sizeof(name), "XVkbd-%s", customization);
       xenv = XtResolvePathname(dpy, "app-defaults", name, NULL, NULL, NULL, 0, NULL);
       if (xenv == NULL) {
 	fprintf(stderr, "%s: app-default file \"%s\" not installed\n",
@@ -1809,12 +1820,10 @@
       }
     }
 
-    env_lang = malloc(strlen("LC_ALL=") + strlen(lang) + 1);
-    sprintf(env_lang, "LC_ALL=%s", lang);
+    asprintf(&env_lang, "LC_ALL=%s", lang);
     putenv(env_lang);
     if (xenv != NULL) {
-      env_xenv = malloc(strlen("XENVIRONMENT=") + strlen(xenv) + 1);
-      sprintf(env_xenv, "XENVIRONMENT=%s", xenv);
+      asprintf(&env_xenv, "XENVIRONMENT=%s", xenv);
       putenv(env_xenv);
     } else if (getenv("XENVIRONMENT") != NULL) {
       putenv("XENVIRONMENT=");
@@ -1923,6 +1932,7 @@
   XtVaGetValues(XtNameToWidget(props_panel, "*jump_pointer"),
 		XtNstate, &appres.jump_pointer, NULL);
 
+  /* These two lines generate warnings with -Wbad-function-cast.  Grrr. */
   appres.key_click_duration = (int)XawToggleGetCurrent(click_buttons);
   appres.autoclick_delay = (int)XawToggleGetCurrent(autoclick_buttons);
 
@@ -1989,7 +1999,7 @@
   if (props_panel == None) {
     Widget label, button;
     Widget form, w;
-    int i;
+    Cardinal i;
     int val;
 
     props_panel = XtVaCreatePopupShell("props_panel", transientShellWidgetClass,
@@ -2015,7 +2025,7 @@
     click_buttons = button;
     for (val = 1; val <= 50; val *= 2) {
       char s1[10];
-      sprintf(s1, "%dms", val);
+      snprintf(s1, sizeof(s1), "%dms", val);
       button = XtVaCreateManagedWidget(s1, toggleWidgetClass,
 			       form, XtNfromVert, w, XtNfromHoriz, button,
 			       XtNradioData, (XtPointer)val,
@@ -2037,7 +2047,7 @@
     autoclick_buttons = button;
     for (val = 500; val <= 1000; val += 100) {
       char s1[10];
-      sprintf(s1, "%dms", val);
+      snprintf(s1, sizeof(s1), "%dms", val);
       button = XtVaCreateManagedWidget(s1, toggleWidgetClass,
 			       form, XtNfromVert, w, XtNfromHoriz, button,
 			       XtNradioData, (XtPointer)val,
@@ -2099,7 +2109,7 @@
   focused_subwindow = None;
   if (target_dpy != NULL && target_dpy != dpy) XCloseDisplay(target_dpy);
 
-  strncpy(name, (display_name == NULL) ? "" : display_name, sizeof(name));
+  snprintf(name, sizeof(name), "%s", (display_name == NULL) ? "" : display_name);
   for (cp = name; isascii(*cp) && isprint(*cp); cp++) ;
   *cp = '\0';
 
@@ -2292,7 +2302,7 @@
   }
 }
 
-static void SignalUser1(void)
+static void SignalUser1(int sig)
 {
   XWindowAttributes attr;
   XGetWindowAttributes(dpy, XtWindow(toplevel), &attr);
@@ -2594,7 +2604,7 @@
   XtAddCallback(w, XtNcallback, (XtCallbackProc)KeyPressed, (XtPointer)name);
 
   if (label != NULL) {
-    strncpy(str, label, sizeof(str) - 1);
+    snprintf(str, sizeof(str), "%s", label);
     if (strcmp(str, "space") == 0) strcpy(str, "");
     len = strlen(str);
     if (3 <= len) {
@@ -2666,9 +2676,9 @@
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
@@ -2770,12 +2780,12 @@
   Widget form, key, left;
   Pixel color;
   XFontStruct *font;
-  Dimension wd, max_wd;
+  Dimension dwd, max_dwd;
   int row, col, first_row;
   char name[50], *label;
   Widget key_box[NUM_KEY_ROWS];
   Widget menu_entry;
-  int i;
+  Cardinal i;
 
 #include "xvkbd.xbm"
 #include "iconify.xbm"
@@ -2795,7 +2805,7 @@
     for (row = first_row; row < NUM_KEY_ROWS; row++) {
       if (keys_normal[row][0] == NULL) continue;
 
-      sprintf(name, "row%d", row);
+      snprintf(name, sizeof(name), "row%d", row);
       key_box[row] = XtVaCreateManagedWidget(name, formWidgetClass, form, NULL);
       key_box[row + 1] = None;
       if (row != first_row)
@@ -2805,7 +2815,7 @@
         
       left = None;
       for (col = 0; keys_normal[row][col] != NULL; col++) {
-        strcpy(name, keys_normal[row][col]);
+	snprintf(name, sizeof(name), "%s", keys_normal[row][col]);
 	if (strcmp(name, "MainMenu") == 0) {
 	  Widget iconify_button = None;
 
@@ -2847,11 +2857,11 @@
 	    color = appres.general_background;
 	    font = appres.general_font;
 	    if (isalpha(name[0])) font = appres.letter_font;
-	    if (strcmp(name, "space") != 0) sprintf(name, "%d,%d", row, col);
+	    if (strcmp(name, "space") != 0) snprintf(name, sizeof(name), "%d,%d", row, col);
 	  }
 	  key = MakeKey(key_box[row], XtNewString(name), label, color);
-	  XtVaGetValues(key, XtNwidth, &wd, NULL);
-	  if (wd <= 1) {
+	  XtVaGetValues(key, XtNwidth, &dwd, NULL);
+	  if (dwd <= 1) {
 	    /* keys can be removed by setting its width to 1 */
 	    XtDestroyWidget(key);
 	    key = None;
@@ -2888,7 +2898,7 @@
     Window root;
     int x1, y1;
     unsigned int wd, ht, bd, dp;
-    int max_wd, max_ht;
+    unsigned int max_wd, max_ht;
 
     XGetGeometry(dpy, XtWindow(toplevel), &root, &x1, &y1, &wd, &ht, &bd, &dp);
     max_wd = XtScreen(toplevel)->width * appres.max_width_ratio;
@@ -2906,16 +2916,16 @@
 
   if (!appres.debug && key_box[first_row] != None) {
     if (appres.keypad) {
-      XtVaGetValues(key_box[1], XtNwidth, &max_wd, NULL);
+      XtVaGetValues(key_box[1], XtNwidth, &max_dwd, NULL);
     } else {
-      max_wd = 0;
+      max_dwd = 0;
       for (row = first_row; row < NUM_KEY_ROWS && key_box[row] != None; row++) {
-        XtVaGetValues(key_box[row], XtNwidth, &wd, NULL);
-        if (max_wd < wd) max_wd = wd;
+        XtVaGetValues(key_box[row], XtNwidth, &dwd, NULL);
+        if (max_dwd < dwd) max_dwd = dwd;
       }
     }
     for (row = first_row; row < NUM_KEY_ROWS && key_box[row] != None; row++) {
-      XtVaSetValues(key_box[row], XtNwidth, max_wd, NULL);
+      XtVaSetValues(key_box[row], XtNwidth, max_dwd, NULL);
     }
   }
   if (0 < strlen(appres.geometry)) {
@@ -3015,19 +3025,20 @@
   home = getenv("HOME");
   if (appres.key_file[0] != '/' && home != NULL
       && strlen(home) + strlen(appres.key_file) + 1 < sizeof(fkey_filename))
-    sprintf(fkey_filename, "%s/%s", home, appres.key_file);
+    snprintf(fkey_filename, sizeof(fkey_filename), "%s/%s", home, appres.key_file);
   else
-    strncpy(fkey_filename, appres.key_file, sizeof(fkey_filename));
+    snprintf(fkey_filename, sizeof(fkey_filename), "%s", appres.key_file);
 
-  strncpy(dict_filename, appres.dict_file, sizeof(dict_filename));
+  snprintf(dict_filename, sizeof(dict_filename), "%s", appres.dict_file);
 
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
@@ -3047,7 +3058,7 @@
 	appres.jump_pointer = val;
       else if (strcmp(key, "dict_file") == 0) {
 	sscanf(&str[1], "%*s %s", &key);
-	strncpy(dict_filename, key, sizeof(dict_filename));
+	snprintf(dict_filename, sizeof(dict_filename), "%s", key);
       }
     } else if (isalpha(str[0])) {
       len = strlen(str);
@@ -3102,9 +3113,9 @@
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
@@ -3127,7 +3138,7 @@
 	prefix = "";
 	if (cur_fkey_value_mode[0] == 'c') prefix = "!";
 	else if (fkey_value[0] == '!') prefix = "\\";
-	sprintf(sp->value, "%s %s%s", cur_fkey, prefix, fkey_value);
+	snprintf(sp->value, len + strlen(fkey_value) + 5, "%s %s%s", cur_fkey, prefix, fkey_value);
       } else {  /* empty string - remove the entry for the function key */
 	if (sp != NULL) {
 	  if (sp2 != NULL) sp2->next = sp->next;
@@ -3147,10 +3158,10 @@
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
@@ -3213,9 +3224,9 @@
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
@@ -3277,8 +3288,8 @@
     else if (shift_state & ControlMask) prefix = 'c';
     else if (shift_state & ShiftMask) prefix = 's';
   }
-  if (prefix == '\0') sprintf(label, "%s", key);
-  else sprintf(label, "%c:%s", prefix, key);
+  if (prefix == '\0') snprintf(label, sizeof(label), "%s", key);
+  else snprintf(label, sizeof(label), "%c:%s", prefix, key);
   len = strlen(label);
   
   for (sp = fkey_list; sp != NULL; sp = sp->next) {
@@ -3336,8 +3347,10 @@
 {
   StopAutoclick();
 
+#ifdef USE_XTEST
   XTestFakeButtonEvent(target_dpy, 1, True, CurrentTime);
   XTestFakeButtonEvent(target_dpy, 1, False, CurrentTime);
+#endif
 }
 
 static void ShowBalloon(Widget w, XEvent *event, String *pars, Cardinal *n_pars)
@@ -3418,7 +3431,7 @@
 static void VisibilityChanged(Widget w, XEvent *event,
 			      String *pars, Cardinal *n_pars)
 {
-  static cnt = 0;
+  static int cnt = 0;
   static time_t t1 = 0;
   time_t t2;
 
@@ -3466,7 +3479,9 @@
   Boolean open_keypad_panel = FALSE;
   char ch;
   Window child;
+#ifdef USE_XTEST
   int op, ev, err;
+#endif
 
   argc1 = argc;
   argv1 = malloc(sizeof(char *) * (argc1 + 5));
@@ -3664,14 +3679,14 @@
   if (locale == NULL) {
     return cur_locale;
   } else if (category == LC_ALL) {
-    strcpy(old_locale, cur_locale);
+    snprintf(cur_locale, sizeof(cur_locale), "%s", s);
     if (locale[0] == '\0') {
       s = getenv("LC_ALL");
       if (s == NULL) s = "C";  /* LC_ALL not defined */
     } else {
       s = locale;
     }
-    strncpy(cur_locale, s, sizeof(cur_locale) - 1);
+    snprintf(cur_locale, sizeof(cur_locale), "%s", s);
     return old_locale;
   } else {
     return cur_locale;
