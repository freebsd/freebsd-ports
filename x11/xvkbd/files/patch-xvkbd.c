Description: Assorted compilation and usage fixes.
 - fix a lot of compiler warnings
 - unbreak the build if XTEST is not selected
 - use snprintf() instead of sprintf() and strcpy(), just in case
 - fix the text of an error message
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2015-05-07

--- xvkbd.c.orig	2020-05-04 04:34:19 UTC
+++ xvkbd.c
@@ -492,8 +492,8 @@ static int altgr_mask = 0;
 static int level3_shift_mask = 0;
 static KeySym altgr_keysym = NoSymbol;
 
-static int shift_state = 0;
-static int mouse_shift = 0;
+static unsigned int shift_state = 0;
+static unsigned int mouse_shift = 0;
 
 static Display *target_dpy = NULL;
 
@@ -513,6 +513,8 @@ static void PopupFunctionKeyEditor(void);
 static void DeleteWindowProc(Widget w, XEvent *event, String *pars, Cardinal *n_pars);
 static void SaveProperty(void);
 
+static void SignalUser1(int dummy);
+
 /*
  * Search for window which has specified instance name (WM_NAME)
  * or class name (WM_CLASS).
@@ -521,8 +523,7 @@ static Window FindWindow(Window top, char *name)
 {
   Window w;
   Window *children, dummy;
-  unsigned int nchildren;
-  int i;
+  unsigned int nchildren, i;
   XClassHint hint;
   char *win_name;
 
@@ -846,7 +847,9 @@ static int MyErrorHandler(Display *my_dpy, XErrorEvent
  */
 static void SendEvent(XKeyEvent *event)
 {
+#ifdef USE_XTEST
   static Boolean first = TRUE;
+#endif
 
   if (!appres.no_sync) {
     XSync(event->display, FALSE);
@@ -1157,11 +1160,11 @@ static void SendKeyPressedEvent(KeySym keysym, unsigne
 
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
@@ -1377,7 +1380,7 @@ static	XtIntervalId save_private_dict_timer_id = (XtIn
 
 static void SetDefaultDictionary(void)
 {
-  strncpy(dict_filename, appres.dict_file, sizeof(dict_filename) - 1);
+  snprintf(dict_filename, sizeof(dict_filename), "%s", appres.dict_file);
   XtVaSetValues(props_dict_entry, XtNstring, dict_filename, NULL);
 }
 
@@ -1394,7 +1397,7 @@ static void ReadCompletionDictionary(void)
   struct WORDLIST *p;
 
   if (strcmp(cur_dict_filename, dict_filename) == 0) return;
-  strcpy(cur_dict_filename, dict_filename);
+  snprintf(cur_dict_filename, sizeof(cur_dict_filename), "%s", dict_filename);
 
   if (!first) {
     int cnt = 0;
@@ -1522,7 +1525,7 @@ static void SavePrivateDictionary(void)
 
 static void AddToCompletionText(KeySym keysym)
 {
-  int len;
+  size_t len;
   struct WORDLIST *node_ptr;
   char ch;
 
@@ -1729,7 +1732,7 @@ static void SendString(const char *str)
 {
   const char *cp, *cp2;
   char key[50];
-  int len;
+  size_t len;
   int val;
   Window target_root, child, junk_w;
   int junk_i;
@@ -1761,8 +1764,7 @@ static void SendString(const char *str)
         } else {
           len = cp2 - cp - 1;
           if (sizeof(key) <= len) len = sizeof(key) - 1;
-          strncpy(key, cp + 1, len);
-          key[len] = '\0';
+          snprintf(key, sizeof(key), "%s", cp + 1);
           KeyPressed(None, key, NULL);
           cp = cp2;
         }
@@ -1810,11 +1812,12 @@ static void SendString(const char *str)
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
 	  if (appres.debug) fprintf(stderr, "xvkbd: XTestFakeButtonEvent(%d)\n", *cp - '0');
@@ -1825,10 +1828,18 @@ static void SendString(const char *str)
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
@@ -1956,13 +1967,13 @@ static Boolean CheckShiftState(int row, int col, int s
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
@@ -2054,7 +2065,7 @@ static void RefreshShiftState(Boolean force)
 
     Window root, child;
     int root_x, root_y, x, y;
-    unsigned int mask;
+    unsigned int tmask;
 
     XKeyEvent event;
 
@@ -2070,28 +2081,28 @@ static void RefreshShiftState(Boolean force)
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
@@ -2354,6 +2365,7 @@ static void PropsItemToggled(Widget w, char *key, char
   XtVaGetValues(XtNameToWidget(props_panel, "*integrate_completion_panel"),
 		XtNstate, &appres.integrate_completion_panel, NULL);
 
+  /* These two lines generate warnings with -Wbad-function-cast.  Grrr. */
   appres.key_click_duration = (int)XawToggleGetCurrent(click_buttons);
   appres.autoclick_delay = (int)XawToggleGetCurrent(autoclick_buttons);
 
@@ -2426,7 +2438,7 @@ static void PopupPropsPanel(void)
   if (props_panel == None) {
     Widget label, button;
     Widget form, w;
-    int i;
+    Cardinal i;
     int val;
 
     props_panel = XtVaCreatePopupShell("props_panel", transientShellWidgetClass,
@@ -2560,7 +2572,7 @@ static void OpenRemoteDisplay(Widget w, char *display_
   focused_subwindow = None;
   if (target_dpy != NULL && target_dpy != dpy) XCloseDisplay(target_dpy);
 
-  strncpy(name, (display_name == NULL) ? "" : display_name, sizeof(name) - 1);
+  snprintf(name, sizeof(name), "%s", (display_name == NULL) ? "" : display_name);
   for (cp = name; isascii(*cp) && isprint(*cp); cp++) ;
   *cp = '\0';
 
@@ -3087,7 +3099,7 @@ static Widget MakeKey(Widget parent, const char *name,
   XtAddCallback(w, XtNcallback, (XtCallbackProc)KeyPressed, (XtPointer)name);
 
   if (label != NULL) {
-    strncpy(str, label, sizeof(str) - 1);
+    snprintf(str, sizeof(str), "%s", label);
     if (strcmp(str, "space") == 0) strcpy(str, "");
     len = strlen(str);
     if (3 <= len) {
@@ -3158,7 +3170,7 @@ static void MakeKeypad(Widget form, Widget from_vert, 
 	       || (strncmp(keypad_shift[row][col], "KP_", 3) == 0
 		   && isdigit(keypad_shift[row][col][3])))
 	color = appres.general_background;
-      strcpy(name, keypad[row][col]);
+      snprintf(name, sizeof(name), "%s", keypad[row][col]);
       if (strcmp(name, "Focus") != 0 && strcmp(name, "Num_Lock") != 0)
 	snprintf(name, sizeof(name), "pad%d,%d", row, col);
       key = MakeKey(keypad_box, XtNewString(name),
@@ -3261,12 +3273,12 @@ static void MakeKeyboard(Boolean remake)
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
@@ -3300,7 +3312,7 @@ static void MakeKeyboard(Boolean remake)
         
       left = None;
       for (col = 0; keys_normal[row][col] != NULL; col++) {
-        strcpy(name, keys_normal[row][col]);
+	snprintf(name, sizeof(name), "%s", keys_normal[row][col]);
 	if (strcmp(name, "MainMenu") == 0) {
 	  Widget iconify_button = None;
 
@@ -3345,8 +3357,8 @@ static void MakeKeyboard(Boolean remake)
 	    if (strcmp(name, "space") != 0) snprintf(name, sizeof(name), "%d,%d", row, col);
 	  }
 	  key = MakeKey(key_box[row], XtNewString(name), label, color);
-	  XtVaGetValues(key, XtNwidth, &wd, NULL);
-	  if (wd <= 1) {
+	  XtVaGetValues(key, XtNwidth, &dwd, NULL);
+	  if (dwd <= 1) {
 	    /* keys can be removed by setting its width to 1 */
 	    XtDestroyWidget(key);
 	    key = None;
@@ -3382,7 +3394,7 @@ static void MakeKeyboard(Boolean remake)
     Window root;
     int x1, y1;
     unsigned int wd, ht, bd, dp;
-    int max_wd, max_ht;
+    unsigned int max_wd, max_ht;
 
     XGetGeometry(dpy, XtWindow(toplevel), &root, &x1, &y1, &wd, &ht, &bd, &dp);
     max_wd = XtScreen(toplevel)->width * appres.max_width_ratio;
@@ -3401,16 +3413,16 @@ static void MakeKeyboard(Boolean remake)
 
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
 
@@ -3523,9 +3535,9 @@ static void ReadProperty(void)
       && strlen(home) + strlen(appres.key_file) + 1 < sizeof(fkey_filename))
     snprintf(fkey_filename, sizeof(fkey_filename), "%s/%s", home, appres.key_file);
   else
-    strncpy(fkey_filename, appres.key_file, sizeof(fkey_filename) - 1);
+    snprintf(fkey_filename, sizeof(fkey_filename), "%s", appres.key_file);
 
-  strncpy(dict_filename, appres.dict_file, sizeof(dict_filename) - 1);
+  snprintf(dict_filename, sizeof(dict_filename), "%s", appres.dict_file);
 
   fp = fopen(fkey_filename, "r");
   if (fp == NULL) return;
@@ -3538,7 +3550,7 @@ static void ReadProperty(void)
 				  keyboard_layout, getenv("XENVIRONMENT"));
 	if (getenv("XENVIRONMENT") == NULL) layout_selected = TRUE;
       } else if (sscanf(&str[1], "dict_file %s", key) == 1) {
-	strncpy(dict_filename, key, sizeof(dict_filename) - 1);
+	snprintf(dict_filename, sizeof(dict_filename), "%s", key);
       } else if (sscanf(&str[1], "private_dict_weight %s", key) == 1) {
 	strncpy(private_dict_weight_value, key, sizeof(private_dict_weight_value) - 1);
       } else if (sscanf(&str[1], "%s %d", key, &val) == 2) {
@@ -3624,7 +3636,7 @@ static void FKeyMenuSelected(Widget w, char *key)
   else if (strncmp(key, "Shift-", strlen("Shift-")) == 0)
     snprintf(key2, sizeof(key2), "s:%s", &key[strlen("Shift-")]);
   else
-    strcpy(key2, key);
+    snprintf(key2, sizeof(key2), "%s", key);
 
   if (strcmp(cur_fkey, key2) != 0) {
     if (strlen(cur_fkey) != 0) {
@@ -3647,7 +3659,7 @@ static void FKeyMenuSelected(Widget w, char *key)
 	prefix = "";
 	if (cur_fkey_value_mode[0] == 'c') prefix = "!";
 	else if (fkey_value[0] == '!' || fkey_value[0] == '\\') prefix = "\\";
-	sprintf(sp->value, "%s %s%s", cur_fkey, prefix, fkey_value);
+	snprintf(sp->value, len + strlen(fkey_value) + 5, "%s %s%s", cur_fkey, prefix, fkey_value);
       } else {  /* empty string - remove the entry for the function key */
 	if (sp != NULL) {
 	  if (sp2 != NULL) sp2->next = sp->next;
@@ -3667,10 +3679,10 @@ static void FKeyMenuSelected(Widget w, char *key)
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
@@ -3870,8 +3882,10 @@ static void Autoclick(void)
 {
   StopAutoclick();
 
+#ifdef USE_XTEST
   XTestFakeButtonEvent(target_dpy, 1, True, CurrentTime);
   XTestFakeButtonEvent(target_dpy, 1, False, CurrentTime);
+#endif
 }
 
 static void ShowBalloon(Widget w, XEvent *event, String *pars, Cardinal *n_pars)
@@ -4000,7 +4014,9 @@ int main(int argc, char *argv[])
   Boolean open_keypad_panel = FALSE;
   char ch;
   Window child;
+#ifdef USE_XTEST
   int op, ev, err;
+#endif
 
   argc1 = argc;
   argv1 = malloc(sizeof(char *) * (argc1 + 5));
@@ -4207,14 +4223,14 @@ char *setlocale(int category, const char *locale)
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
