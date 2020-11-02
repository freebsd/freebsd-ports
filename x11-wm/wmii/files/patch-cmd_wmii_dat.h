--- cmd/wmii/dat.h.orig	2007-11-16 13:59:15 UTC
+++ cmd/wmii/dat.h
@@ -2,7 +2,6 @@
  * See LICENSE file for license details.
  */
 
-#define _XOPEN_SOURCE 600
 #define IXP_P9_STRUCTS
 #define IXP_NO_P9_
 #include <regexp9.h>
@@ -194,7 +193,7 @@ struct Ruleset {
 };
 
 /* global variables */
-struct {
+struct Global {
 	CTuple focuscolor;
 	CTuple normcolor;
 	Font *font;
@@ -207,8 +206,10 @@ struct {
 	char grabmod[5];
 	ulong mod;
 	int colmode;
-} def;
+};
 
+extern struct Global def;
+
 enum {
 	BarLeft, BarRight
 };
@@ -223,40 +224,42 @@ struct WMScreen {
 
 	Rectangle r;
 	Rectangle brect;
-} *screens, *screen;
+};
 
-Client *client;
-View *view;
-Key *key;
-Divide *divs;
-Client c_magic;
-Client c_root;
+extern WMScreen *screens, *screen;
 
-Handlers framehandler;
+extern Client *client;
+extern View *view;
+extern Key *key;
+extern Divide *divs;
+extern Client c_magic;
+extern Client c_root;
 
-char buffer[8092];
+extern Handlers framehandler;
 
+extern char buffer[8092];
+
 /* IXP */
-IxpServer srv;
-Ixp9Srv p9srv;
+extern IxpServer srv;
+extern Ixp9Srv p9srv;
 
 /* X11 */
-uint num_screens;
-uint valid_mask;
-uint num_lock_mask;
-Bool sel_screen;
+extern uint num_screens;
+extern uint valid_mask;
+extern uint num_lock_mask;
+extern Bool sel_screen;
 
-Image xor;
+extern Image xor;
 
-Cursor cursor[CurLast];
-void (*handler[LASTEvent]) (XEvent *);
+extern Cursor cursor[CurLast];
+extern void (*handler[LASTEvent]) (XEvent *);
 
 /* Misc */
-Image *broken;
-Bool starting;
-Bool verbose;
-char *user;
-char *execstr;
+extern Image *broken;
+extern Bool starting;
+extern Bool verbose;
+extern char *user;
+extern char *execstr;
 
 #define Debug if(verbose)
 #define Dprint(...) do{ Debug fprint(2, __VA_ARGS__); }while(0)
