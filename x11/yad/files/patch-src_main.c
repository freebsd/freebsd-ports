--- src/main.c.orig	2015-07-18 16:00:17 UTC
+++ src/main.c
@@ -765,6 +765,7 @@ main (gint argc, gchar ** argv)
         ret = yad_print_run ();
         break;
 
+#ifdef HAVE_HTML
       case YAD_MODE_HTML:
         /* Webkit doesn't handle focus for child dialogs when gtk_dialog_run() is used */
         /* FIXME: maybe this solution must be expanded to all dialogs */
@@ -775,6 +776,7 @@ main (gint argc, gchar ** argv)
 
         gtk_main ();
         break;
+#endif
 
       default:
         dialog = create_dialog ();
