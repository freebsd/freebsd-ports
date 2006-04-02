--- src/gtk/clipbrd.cpp.orig	Wed Mar 22 05:42:16 2006
+++ src/gtk/clipbrd.cpp	Sun Apr  2 17:51:17 2006
@@ -494,16 +494,21 @@
 
     delete[] array;
 
+#ifdef __WXGTK20__
     gtk_signal_connect( GTK_OBJECT(m_clipboardWidget),
                         "selection_get",
                         GTK_SIGNAL_FUNC(selection_handler),
                         GUINT_TO_POINTER(
-#ifdef __WXGTK20__
                                 gtk_get_current_event_time()
+                                        ) );
 #else
+    gtk_signal_connect( GTK_OBJECT(m_clipboardWidget),
+                        "selection_get",
+                        GTK_SIGNAL_FUNC(selection_handler),
+                        GUINT_TO_POINTER(
                                 gdk_event_get_time(gtk_get_current_event())
-#endif
                                         ) );
+#endif
 
 #if wxUSE_THREADS
     /* disable GUI threads */
