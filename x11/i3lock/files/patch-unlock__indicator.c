--- unlock_indicator.c.orig	2019-05-11 07:55:23 UTC
+++ unlock_indicator.c
@@ -35,7 +35,7 @@ extern bool debug_mode;
 
 /* The current position in the input buffer. Useful to determine if any
  * characters of the password have already been entered or not. */
-int input_position;
+extern int input_position;
 
 /* The lock window. */
 extern xcb_window_t win;
