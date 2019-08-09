Description: Assorted compilation and usage fixes.
 - fix a lot of compiler warnings
 - unbreak the build if XTEST is not selected
 - use snprintf() instead of sprintf() and strcpy(), just in case
 - fix the text of an error message
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2015-05-07

--- xvkbd.c.orig	2018-02-25 00:55:33 UTC
+++ xvkbd.c
@@ -470,8 +470,8 @@ static int altgr_mask = 0;
 static int level3_shift_mask = 0;
 static KeySym altgr_keysym = NoSymbol;
 
-static int shift_state = 0;
-static int mouse_shift = 0;
+static unsigned int shift_state = 0;
+static unsigned int mouse_shift = 0;
 
 static Display *target_dpy = NULL;
 
@@ -482,7 +482,7 @@ static Window focused_subwindow = None;
 static Pixmap xvkbd_pixmap = None;
 
 static int AddKeysym(KeySym keysym, Boolean top);  /* forward */
-static void SendString(const unsigned char *str);
+static void SendString(const char *str);
 static void MakeKeyboard(Boolean remake);
 static void MakeKeypad(Widget form, Widget from_vert, Widget from_horiz);
 static void MakeSunFunctionKey(Widget form, Widget from_vert, Widget from_horiz);
@@ -492,6 +492,8 @@ static void PopupFunctionKeyEditor(void)
 static void DeleteWindowProc(Widget w, XEvent *event, String *pars, Cardinal *n_pars);
 static void SaveProperty(void);
 
+static void SignalUser1(int dummy);
+
 /*
  * Search for window which has specified instance name (WM_NAME)
  * or class name (WM_CLASS).
@@ -500,8 +502,7 @@ static Window FindWindow(Window top, cha
 {
   Window w;
   Window *children, dummy;
-  unsigned int nchildren;
-  int i;
+  unsigned int nchildren, i;
   XClassHint hint;
   char *win_name;
 
@@ -824,7 +825,9 @@ static int MyErrorHandler(Display *my_dp
  */
 static void SendEvent(XKeyEvent *event)
 {
+#ifdef USE_XTEST
   static Boolean first = TRUE;
+#endif
 
   if (!appres.no_sync) {
     XSync(event->display, FALSE);
@@ -1136,11 +1139,11 @@ static void SendKeyPressedEvent(KeySym k
 
 #ifdef USE_XTEST
   if (appres.xtest && press_release == 0) {
-    Window root, child;
+    Window troot, child;
     int root_x, root_y, x, y;
     unsigned int mask;
 
-    XQueryPointer(target_dpy, event.root, &root, &child, &root_x, &root_y, &x, &y, &mask);
+    XQueryPointer(target_dpy, event.root, &troot, &child, &root_x, &root_y, &x, &y, &mask);
 
     event.type = KeyRelease;
     event.state = 0;
@@ -1332,7 +1335,7 @@ static int n_word_list = 0;
 
 static void SetDefaultDictionary(void)
 {
-  strncpy(dict_filename, appres.dict_file, sizeof(dict_filename));
+  snprintf(dict_filename, sizeof(dict_filename), "%s", appres.dict_file);
   XtVaSetValues(props_dict_entry, XtNstring, dict_filename, NULL);
 }
 
@@ -1347,7 +1350,7 @@ static void ReadCompletionDictionary(voi
   struct WORDLIST *p;
 
   if (strcmp(cur_dict_filename, dict_filename) == 0) return;
-  strcpy(cur_dict_filename, dict_filename);
+  snprintf(cur_dict_filename, sizeof(cur_dict_filename), "%s", dict_filename);
 
   if (!first) {
     int cnt = 0;
@@ -1397,7 +1400,7 @@ static void ReadCompletionDictionary(voi
 
 static void AddToCompletionText(KeySym keysym)
 {
-  int len;
+  size_t len;
   struct WORDLIST *node_ptr;
 
   if (completion_entry != None) {
@@ -1487,7 +1490,7 @@ static void PopupCompletionPanel(void)
 
   ReadCompletionDictionary();
 
-  sprintf(msg, "%d words in the dictionary", n_completion_words);
+  snprintf(msg, sizeof(msg), "%d words in the dictionary", n_completion_words);
   XtVaSetValues(completion_entry, XtNlabel, msg, NULL);
 
   completion_text[0] = '\0';
@@ -1502,11 +1505,11 @@ static void PopupCompletionPanel(void)
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
@@ -1536,8 +1539,7 @@ static void SendString(const unsigned ch
         } else {
           len = cp2 - cp - 1;
           if (sizeof(key) <= len) len = sizeof(key) - 1;
-          strncpy(key, cp + 1, len);
-          key[len] = '\0';
+          snprintf(key, sizeof(key), "%s", cp + 1);
           KeyPressed(None, key, NULL);
           cp = cp2;
         }
@@ -1584,11 +1586,12 @@ static void SendString(const unsigned ch
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
@@ -1599,10 +1602,18 @@ static void SendString(const unsigned ch
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
@@ -1684,7 +1695,7 @@ static void Highlight(char *name, int st
   char name1[50];
   Widget w;
 
-  sprintf(name1, "*%s", name);
+  snprintf(name1, sizeof(name1), "*%s", name);
   w = XtNameToWidget(toplevel, name1);
   if (w != None) {
     if (strstr(name, "Focus") != NULL) {
@@ -1730,13 +1741,13 @@ static Boolean CheckShiftState(int row, 
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
@@ -1824,7 +1835,7 @@ static void RefreshShiftState(Boolean fo
 
     Window root, child;
     int root_x, root_y, x, y;
-    unsigned int mask;
+    unsigned int tmask;
 
     XKeyEvent event;
 
@@ -1840,28 +1851,28 @@ static void RefreshShiftState(Boolean fo
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
@@ -1922,7 +1933,7 @@ static char *GetWindowGeometry(Widget w)
 
   XtVaGetValues(w, XtNx, &x0, XtNy, &y0, NULL);
   XGetGeometry(dpy, XtWindow(w), &root, &x1, &y1, &wd, &ht, &bd, &dp);
-  sprintf(geom, "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
+  snprintf(geom, sizeof(geom), "%dx%d+%d+%d", wd, ht, (int)(x0 - x1), (int)(y0 - y1));
 
   return geom;
 }
@@ -1964,7 +1975,7 @@ static void SetWindowManagerHint(Boolean
 	       FALSE, SubstructureNotifyMask | SubstructureRedirectMask,
 	       (XEvent *)&ev);
     if (appres.debug)
-      fprintf(stderr, "SetWindowManagerHint: _NET_WM_STATE_ABOVE = %d\n", ev.data.l[0]);
+      fprintf(stderr, "SetWindowManagerHint: _NET_WM_STATE_ABOVE = %ld\n", ev.data.l[0]);
   }
 }
 
@@ -1986,7 +1997,7 @@ static void LayoutSelected(Widget w, cha
   if (key != NULL) {
     if (strcmp(key, "default") != 0) {
       sscanf(key, "%29[^/]/%29s", customization, lang);
-      sprintf(name, "XVkbd-%s", customization);
+      snprintf(name, sizeof(name), "XVkbd-%s", customization);
       xenv = XtResolvePathname(dpy, "app-defaults", name, NULL, NULL, NULL, 0, NULL);
       if (xenv == NULL) {
 	fprintf(stderr, "%s: app-default file \"%s\" not installed\n",
@@ -1994,12 +2005,10 @@ static void LayoutSelected(Widget w, cha
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
 
       keyboard_layout = XtNewString(key);
@@ -2119,6 +2128,7 @@ static void PropsItemToggled(Widget w, c
   XtVaGetValues(XtNameToWidget(props_panel, "*jump_pointer"),
 		XtNstate, &appres.jump_pointer, NULL);
 
+  /* These two lines generate warnings with -Wbad-function-cast.  Grrr. */
   appres.key_click_duration = (int)XawToggleGetCurrent(click_buttons);
   appres.autoclick_delay = (int)XawToggleGetCurrent(autoclick_buttons);
 
@@ -2185,7 +2195,7 @@ static void PopupPropsPanel(void)
   if (props_panel == None) {
     Widget label, button;
     Widget form, w;
-    int i;
+    Cardinal i;
     int val;
 
     props_panel = XtVaCreatePopupShell("props_panel", transientShellWidgetClass,
@@ -2211,7 +2221,7 @@ static void PopupPropsPanel(void)
     click_buttons = button;
     for (val = 1; val <= 50; val *= 2) {
       char s1[10];
-      sprintf(s1, "%dms", val);
+      snprintf(s1, sizeof(s1), "%dms", val);
       button = XtVaCreateManagedWidget(s1, toggleWidgetClass,
 			       form, XtNfromVert, w, XtNfromHoriz, button,
 			       XtNradioData, (XtPointer)val,
@@ -2233,7 +2243,7 @@ static void PopupPropsPanel(void)
     autoclick_buttons = button;
     for (val = 500; val <= 1000; val += 100) {
       char s1[10];
-      sprintf(s1, "%dms", val);
+      snprintf(s1, sizeof(s1), "%dms", val);
       button = XtVaCreateManagedWidget(s1, toggleWidgetClass,
 			       form, XtNfromVert, w, XtNfromHoriz, button,
 			       XtNradioData, (XtPointer)val,
@@ -2295,7 +2305,7 @@ static void OpenRemoteDisplay(Widget w, 
   focused_subwindow = None;
   if (target_dpy != NULL && target_dpy != dpy) XCloseDisplay(target_dpy);
 
-  strncpy(name, (display_name == NULL) ? "" : display_name, sizeof(name));
+  snprintf(name, sizeof(name), "%s", (display_name == NULL) ? "" : display_name);
   for (cp = name; isascii(*cp) && isprint(*cp); cp++) ;
   *cp = '\0';
 
@@ -2806,7 +2816,7 @@ static Widget MakeKey(Widget parent, con
   XtAddCallback(w, XtNcallback, (XtCallbackProc)KeyPressed, (XtPointer)name);
 
   if (label != NULL) {
-    strncpy(str, label, sizeof(str) - 1);
+    snprintf(str, sizeof(str), "%s", label);
     if (strcmp(str, "space") == 0) strcpy(str, "");
     len = strlen(str);
     if (3 <= len) {
@@ -2878,9 +2888,9 @@ static void MakeKeypad(Widget form, Widg
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
@@ -2982,12 +2992,12 @@ static void MakeKeyboard(Boolean remake)
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
@@ -3007,7 +3017,7 @@ static void MakeKeyboard(Boolean remake)
     for (row = first_row; row < NUM_KEY_ROWS; row++) {
       if (keys_normal[row][0] == NULL) continue;
 
-      sprintf(name, "row%d", row);
+      snprintf(name, sizeof(name), "row%d", row);
       key_box[row] = XtVaCreateManagedWidget(name, formWidgetClass, form, NULL);
       key_box[row + 1] = None;
       if (row != first_row)
@@ -3017,7 +3027,7 @@ static void MakeKeyboard(Boolean remake)
         
       left = None;
       for (col = 0; keys_normal[row][col] != NULL; col++) {
-        strcpy(name, keys_normal[row][col]);
+	snprintf(name, sizeof(name), "%s", keys_normal[row][col]);
 	if (strcmp(name, "MainMenu") == 0) {
 	  Widget iconify_button = None;
 
@@ -3059,11 +3069,11 @@ static void MakeKeyboard(Boolean remake)
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
@@ -3099,7 +3109,7 @@ static void MakeKeyboard(Boolean remake)
     Window root;
     int x1, y1;
     unsigned int wd, ht, bd, dp;
-    int max_wd, max_ht;
+    unsigned int max_wd, max_ht;
 
     XGetGeometry(dpy, XtWindow(toplevel), &root, &x1, &y1, &wd, &ht, &bd, &dp);
     max_wd = XtScreen(toplevel)->width * appres.max_width_ratio;
@@ -3118,16 +3128,16 @@ static void MakeKeyboard(Boolean remake)
 
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
@@ -3236,11 +3246,11 @@ static void ReadProperty(void)
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
@@ -3253,7 +3263,7 @@ static void ReadProperty(void)
 				  keyboard_layout, getenv("XENVIRONMENT"));
 	if (getenv("XENVIRONMENT") == NULL) layout_selected = TRUE;
       } else if (sscanf(&str[1], "dict_file %s", key) == 1) {
-	strncpy(dict_filename, key, sizeof(dict_filename));
+	snprintf(dict_filename, sizeof(dict_filename), "%s", key);
       } else if (sscanf(&str[1], "%s %d", key, &val) == 2) {
 	if (strcmp(key, "quick_modifiers") == 0)
 	  appres.quick_modifiers = val;
@@ -3329,9 +3339,9 @@ static void FKeyMenuSelected(Widget w, c
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
@@ -3354,7 +3364,7 @@ static void FKeyMenuSelected(Widget w, c
 	prefix = "";
 	if (cur_fkey_value_mode[0] == 'c') prefix = "!";
 	else if (fkey_value[0] == '!' || fkey_value[0] == '\\') prefix = "\\";
-	sprintf(sp->value, "%s %s%s", cur_fkey, prefix, fkey_value);
+	snprintf(sp->value, len + strlen(fkey_value) + 5, "%s %s%s", cur_fkey, prefix, fkey_value);
       } else {  /* empty string - remove the entry for the function key */
 	if (sp != NULL) {
 	  if (sp2 != NULL) sp2->next = sp->next;
@@ -3374,10 +3384,10 @@ static void FKeyMenuSelected(Widget w, c
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
@@ -3441,9 +3451,9 @@ static void PopupFunctionKeyEditor(void)
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
@@ -3514,8 +3524,8 @@ static const char *FindFunctionKeyValue(
     else if (shift_state & ControlMask) prefix = 'c';
     else if (shift_state & ShiftMask) prefix = 's';
   }
-  if (prefix == '\0') sprintf(label, "%s", key);
-  else sprintf(label, "%c:%s", prefix, key);
+  if (prefix == '\0') snprintf(label, sizeof(label), "%s", key);
+  else snprintf(label, sizeof(label), "%c:%s", prefix, key);
   len = strlen(label);
   
   for (sp = fkey_list; sp != NULL; sp = sp->next) {
@@ -3573,8 +3583,10 @@ static void Autoclick(void)
 {
   StopAutoclick();
 
+#ifdef USE_XTEST
   XTestFakeButtonEvent(target_dpy, 1, True, CurrentTime);
   XTestFakeButtonEvent(target_dpy, 1, False, CurrentTime);
+#endif
 }
 
 static void ShowBalloon(Widget w, XEvent *event, String *pars, Cardinal *n_pars)
@@ -3703,7 +3715,9 @@ int main(int argc, char *argv[])
   Boolean open_keypad_panel = FALSE;
   char ch;
   Window child;
+#ifdef USE_XTEST
   int op, ev, err;
+#endif
 
   argc1 = argc;
   argv1 = malloc(sizeof(char *) * (argc1 + 5));
@@ -3905,14 +3919,14 @@ char *setlocale(int category, const char
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
