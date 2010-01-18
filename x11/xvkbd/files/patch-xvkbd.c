Description: Assorted compilation and usage fixes.
 - fix a lot of compiler warnings
 - unbreak the build if XTEST is not selected
 - fix the location of the words file on FreeBSD
 - use snprintf() instead of sprintf() and strcpy(), just in case
 - fix the text of an error message
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-01-18

--- xvkbd.c.orig
+++ xvkbd.c
@@ -356,7 +356,7 @@
   { "keyFile", "KeyFile", XtRString, sizeof(char *),
     Offset(key_file), XtRImmediate, ".xvkbd" },
   { "dictFile", "DictFile", XtRString, sizeof(char *),
-    Offset(dict_file), XtRImmediate, "/usr/dict/words" },
+    Offset(dict_file), XtRImmediate, "/usr/share/dict/words" },
   { "customizations", "Customizations", XtRString, sizeof(char *),
     Offset(customizations), XtRImmediate, "default" },
   { "editableFunctionKeys", "EditableFunctionKeys", XtRInt, sizeof(int),
@@ -449,8 +449,8 @@
 static int altgr_mask = 0;
 static KeySym altgr_keysym = NoSymbol;
 
-static int shift_state = 0;
-static int mouse_shift = 0;
+static unsigned int shift_state = 0;
+static unsigned int mouse_shift = 0;
 
 static Display *target_dpy = NULL;
 
@@ -461,7 +461,7 @@
 static Pixmap xvkbd_pixmap = None;
 
 static int AddKeysym(KeySym keysym, Boolean top);  /* forward */
-static void SendString(const unsigned char *str);
+static void SendString(const char *str);
 static void MakeKeyboard(Boolean remake);
 static void MakeKeypad(Widget form, Widget from_vert, Widget from_horiz);
 static void MakeSunFunctionKey(Widget form, Widget from_vert, Widget from_horiz);
@@ -470,6 +470,8 @@
 static void PopupFunctionKeyEditor(void);
 static void DeleteWindowProc(Widget w, XEvent *event, String *pars, Cardinal *n_pars);
 
+static void SignalUser1(int sig);
+
 /*
  * Search for window which has specified instance name (WM_NAME)
  * or class name (WM_CLASS).
@@ -478,8 +480,7 @@
 {
   Window w;
   Window *children, dummy;
-  unsigned int nchildren;
-  int i;
+  unsigned int nchildren, i;
   XClassHint hint;
 
   w = None;
@@ -756,7 +757,9 @@
  */
 static void SendEvent(XKeyEvent *event)
 {
+#ifdef USE_XTEST
   static Boolean first = TRUE;
+#endif
 
   if (!appres.no_sync) {
     XSync(event->display, FALSE);
@@ -1037,11 +1040,11 @@
 
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
@@ -1164,7 +1167,7 @@
  * via xvkbd can be listed, and choosing one of them will send the
  * suffix to the clients.
  * Words for completion will be read from dictionary file specified
- * with xvkbd.dictFile resource, such as /usr/dict/words.
+ * with xvkbd.dictFile resource, such as /usr/share/dict/words.
  */
 static Widget completion_panel = None;
 static Widget completion_entry = None;
@@ -1221,7 +1224,7 @@
 
 static void AddToCompletionText(KeySym keysym)
 {
-  int len;
+  size_t len;
   struct WORDLIST *node_ptr;
 
   if (completion_entry != None) {
@@ -1310,11 +1313,11 @@
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
@@ -1360,11 +1363,12 @@
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
@@ -1375,10 +1379,18 @@
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
@@ -1446,7 +1458,7 @@
   char name1[50];
   Widget w;
 
-  sprintf(name1, "*%s", name);
+  snprintf(name1, sizeof(name1), "*%s", name);
   w = XtNameToWidget(toplevel, name1);
   if (w != None) {
     if (strstr(name, "Focus") != NULL) {
@@ -1475,13 +1487,13 @@
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
@@ -1572,7 +1584,7 @@
 
     Window root, child;
     int root_x, root_y, x, y;
-    unsigned int mask;
+    unsigned int tmask;
 
     XKeyEvent event;
 
@@ -1588,28 +1600,28 @@
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
@@ -1670,7 +1682,7 @@
 
   XtVaGetValues(w, XtNx, &x0, XtNy, &y0, NULL);
   XGetGeometry(dpy, XtWindow(w), &root, &x1, &y1, &wd, &ht, &bd, &dp);
-  sprintf(geom, "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
+  snprintf(geom, sizeof(geom), "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
 
   return geom;
 }
@@ -1690,7 +1702,7 @@
 
   if (strcmp(key, "default") != 0) {
     sscanf(key, "%29[^/]/%29s", customization, lang);
-    sprintf(name, "XVkbd-%s", customization);
+    snprintf(name, sizeof(name), "XVkbd-%s", customization);
     xenv = XtResolvePathname(dpy, "app-defaults", name, NULL, NULL, NULL, 0, NULL);
     if (xenv == NULL) {
       fprintf(stderr, "%s: app-default file \"%s\" not installed\n",
@@ -1807,6 +1819,7 @@
   XtVaGetValues(XtNameToWidget(props_panel, "*jump_pointer"),
 		XtNstate, &appres.jump_pointer, NULL);
 
+  /* These two lines generate warnings with -Wbad-function-cast.  Grrr. */
   appres.key_click_duration = (int)XawToggleGetCurrent(click_buttons);
   appres.autoclick_delay = (int)XawToggleGetCurrent(autoclick_buttons);
 
@@ -1863,7 +1876,7 @@
   if (props_panel == None) {
     Widget label, button;
     Widget form, w;
-    int i;
+    Cardinal i;
     int val;
 
     props_panel = XtVaCreatePopupShell("props_panel", transientShellWidgetClass,
@@ -1955,7 +1968,7 @@
   focused_subwindow = None;
   if (target_dpy != NULL && target_dpy != dpy) XCloseDisplay(target_dpy);
 
-  strncpy(name, (display_name == NULL) ? "" : display_name, sizeof(name));
+  snprintf(name, sizeof(name), "%s", (display_name == NULL) ? "" : display_name);
   for (cp = name; isascii(*cp) && isprint(*cp); cp++) ;
   *cp = '\0';
 
@@ -2146,7 +2159,7 @@
   }
 }
 
-void SignalUser1(void)
+static void SignalUser1(int sig)
 {
   XWindowAttributes attr;
   XGetWindowAttributes(dpy, XtWindow(toplevel), &attr);
@@ -2448,7 +2461,7 @@
   XtAddCallback(w, XtNcallback, (XtCallbackProc)KeyPressed, (XtPointer)name);
 
   if (label != NULL) {
-    strncpy(str, label, sizeof(str) - 1);
+    snprintf(str, sizeof(str), "%s", label);
     if (strcmp(str, "space") == 0) strcpy(str, "");
     len = strlen(str);
     if (3 <= len) {
@@ -2520,9 +2533,9 @@
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
@@ -2624,12 +2637,12 @@
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
@@ -2649,7 +2662,7 @@
     for (row = first_row; row < NUM_KEY_ROWS; row++) {
       if (keys_normal[row][0] == NULL) continue;
 
-      sprintf(name, "row%d", row);
+      snprintf(name, sizeof(name), "row%d", row);
       key_box[row] = XtVaCreateManagedWidget(name, formWidgetClass, form, NULL);
       key_box[row + 1] = None;
       if (row != first_row)
@@ -2659,7 +2672,7 @@
         
       left = None;
       for (col = 0; keys_normal[row][col] != NULL; col++) {
-        strcpy(name, keys_normal[row][col]);
+	snprintf(name, sizeof(name), "%s", keys_normal[row][col]);
 	if (strcmp(name, "MainMenu") == 0) {
 	  Widget iconify_button = None;
 
@@ -2701,11 +2714,11 @@
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
@@ -2740,7 +2753,7 @@
     Window root;
     int x1, y1;
     unsigned int wd, ht, bd, dp;
-    int max_wd, max_ht;
+    unsigned int max_wd, max_ht;
 
     XGetGeometry(dpy, XtWindow(toplevel), &root, &x1, &y1, &wd, &ht, &bd, &dp);
     max_wd = XtScreen(toplevel)->width * appres.max_width_ratio;
@@ -2758,16 +2771,16 @@
 
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
@@ -2862,17 +2875,18 @@
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
@@ -2941,9 +2955,9 @@
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
@@ -2986,10 +3000,10 @@
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
@@ -3048,9 +3062,9 @@
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
@@ -3112,8 +3126,8 @@
     else if (shift_state & ControlMask) prefix = 'c';
     else if (shift_state & ShiftMask) prefix = 's';
   }
-  if (prefix == '\0') sprintf(label, "%s", key);
-  else sprintf(label, "%c:%s", prefix, key);
+  if (prefix == '\0') snprintf(label, sizeof(label), "%s", key);
+  else snprintf(label, sizeof(label), "%c:%s", prefix, key);
   len = strlen(label);
   
   for (sp = fkey_list; sp != NULL; sp = sp->next) {
@@ -3171,8 +3185,10 @@
 {
   StopAutoclick();
 
+#ifdef USE_XTEST
   XTestFakeButtonEvent(target_dpy, 1, True, CurrentTime);
   XTestFakeButtonEvent(target_dpy, 1, False, CurrentTime);
+#endif
 }
 
 static void ShowBalloon(Widget w, XEvent *event, String *pars, Cardinal *n_pars)
@@ -3253,7 +3269,7 @@
 static void VisibilityChanged(Widget w, XEvent *event,
 			      String *pars, Cardinal *n_pars)
 {
-  static cnt = 0;
+  static int cnt = 0;
   static time_t t1 = 0;
   time_t t2;
 
@@ -3301,7 +3317,9 @@
   Boolean open_keypad_panel = FALSE;
   char ch;
   Window child;
+#ifdef USE_XTEST
   int op, ev, err;
+#endif
 
   argc1 = argc;
   argv1 = malloc(sizeof(char *) * (argc1 + 5));
@@ -3500,7 +3518,7 @@
     } else {
       s = locale;
     }
-    strncpy(cur_locale, s, sizeof(cur_locale) - 1);
+    snprintf(cur_locale, sizeof(cur_locale), "%s", s);
     return old_locale;
   } else {
     return cur_locale;
