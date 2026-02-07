--- xfce4-about/main.c.orig	2024-11-29 19:21:01 UTC
+++ xfce4-about/main.c
@@ -24,6 +24,10 @@
 #include <stdlib.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
+
 #ifdef ENABLE_X11
 #include <gdk/gdkx.h>
 #endif
@@ -98,7 +102,7 @@ xfce_about_system (GtkBuilder *builder)
       else
         {
           const gchar *extensions[] = { "svg", "png" };
-          g_autofree gchar *pixmap_path = g_strconcat ("/usr/share/pixmaps/", os_logo, ".", NULL);
+          g_autofree gchar *pixmap_path = g_strconcat ("%%PREFIX%%/share/pixmaps/", os_logo, ".", NULL);
 
           for (guint i = 0; i < G_N_ELEMENTS (extensions); i++)
             {
@@ -142,7 +146,11 @@ xfce_about_system (GtkBuilder *builder)
   gtk_label_set_text (GTK_LABEL (label), gtk_text);
 
   label = gtk_builder_get_object (builder, "kernel-version");
+#ifdef __FreeBSD__
+  kernel_text = g_strdup_printf ("%d", getosreldate ());
+#else
   kernel_text = get_system_info (KERNEL);
+#endif
   gtk_label_set_text (GTK_LABEL (label), kernel_text ? kernel_text : "");
 
   label = gtk_builder_get_object (builder, "windowing-system");
