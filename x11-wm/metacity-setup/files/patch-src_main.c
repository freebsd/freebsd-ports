--- src/main.c.orig	Sun Jun 16 23:17:13 2002
+++ src/main.c	Sun Jun 16 23:17:22 2002
@@ -26,7 +26,7 @@
   gtk_set_locale ();
   gtk_init (&argc, &argv);
 
-  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
+  add_pixmap_directory (PACKAGE_DATA_DIR "/pixmaps");
 
   /*
    * The following code was added by Glade to create one of each component
