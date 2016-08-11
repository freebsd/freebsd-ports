--- main.c	2005-01-29 03:31:33.000000000 +0000
+++ main.c	2016-07-01 20:14:55.443662000 +0000
@@ -210,14 +210,14 @@
 static int close_window (Display *disp, Window win);
 static int longest_str (gchar **strv);
 static int window_to_desktop (Display *disp, Window win, int desktop);
-static void window_set_title (Display *disp, Window win, char *str, char mode);
+static void window_set_title (Display *disp, Window win, const char *str, char mode);
 static gchar *get_window_title (Display *disp, Window win);
 static gchar *get_window_class (Display *disp, Window win);
 static gchar *get_property (Display *disp, Window win, 
         Atom xa_prop_type, gchar *prop_name, unsigned long *size);
 static void init_charset(void);
-static int window_move_resize (Display *disp, Window win, char *arg);
-static int window_state (Display *disp, Window win, char *arg);
+static int window_move_resize (Display *disp, Window win, const char *arg);
+static int window_state (Display *disp, Window win, const char *arg);
 static Window Select_Window(Display *dpy);
 static Window get_active_window(Display *dpy);
 
@@ -629,9 +629,9 @@
 }/*}}}*/
 
 static void window_set_title (Display *disp, Window win, /* {{{ */
-        char *title, char mode) {
-    gchar *title_utf8;
-    gchar *title_local;
+        const char *title, char mode) {
+    void *title_utf8;
+    void *title_local;
 
     if (envir_utf8) {
         title_utf8 = g_strdup(title);
@@ -734,7 +734,7 @@
             0, 0, 0, 0, 0);
 }/*}}}*/
 
-static int window_state (Display *disp, Window win, char *arg) {/*{{{*/
+static int window_state (Display *disp, Window win, const char *arg) {/*{{{*/
     unsigned long action;
     Atom prop1 = 0;
     Atom prop2 = 0;
@@ -827,7 +827,7 @@
     return FALSE;
 }/*}}}*/
 
-static int window_move_resize (Display *disp, Window win, char *arg) {/*{{{*/
+static int window_move_resize (Display *disp, Window win, const char *arg) {/*{{{*/
     signed long grav, x, y, w, h;
     unsigned long grflags;
     const char *argerr = "The -e option expects a list of comma separated integers: \"gravity,X,Y,width,height\"\n";
@@ -1441,6 +1441,9 @@
 
     /* null terminate the result to make string handling easier */
     tmp_size = (ret_format / 8) * ret_nitems;
+    /* Correct 64 Architecture implementation of 32 bit data */
+    if (ret_format == 32)
+        tmp_size *= sizeof(long)/4;
     ret = g_malloc(tmp_size + 1);
     memcpy(ret, ret_prop, tmp_size);
     ret[tmp_size] = '\0';
