--- Hotkeys.C.orig	2014-04-23 11:21:46.000000000 +0200
+++ Hotkeys.C	2014-04-23 11:23:21.000000000 +0200
@@ -86,9 +86,9 @@
   {FL_ALT+FL_SHIFT+0xfe20,PreviousWindow}, // XK_ISO_Left_Tab
 #endif
 #if KWM_HOTKEYS && DESKTOPS // KWM uses these to switch desktops
-//   {FL_CTRL+FL_Tab,	NextDesk},
-//   {FL_CTRL+FL_SHIFT+FL_Tab,PreviousDesk},
-//   {FL_CTRL+FL_SHIFT+0xfe20,PreviousDesk}, // XK_ISO_Left_Tab
+  {FL_CTRL+FL_Tab,	NextDesk},
+  {FL_CTRL+FL_SHIFT+FL_Tab,PreviousDesk},
+  {FL_CTRL+FL_SHIFT+0xfe20,PreviousDesk}, // XK_ISO_Left_Tab
   {FL_CTRL+FL_F+1,	DeskNumber},
   {FL_CTRL+FL_F+2,	DeskNumber},
   {FL_CTRL+FL_F+3,	DeskNumber},
@@ -182,9 +182,10 @@
 int Handle_Hotkey() {
   for (int i = 0; keybindings[i].key; i++) {
     if (Fl::test_shortcut(keybindings[i].key) ||
+	(
 	(keybindings[i].key & 0xFFFF) == FL_Delete
 	&& Fl::event_key() == FL_BackSpace// fltk bug?
-	) {
+	)) {
       keybindings[i].func();
       return 1;
     }
