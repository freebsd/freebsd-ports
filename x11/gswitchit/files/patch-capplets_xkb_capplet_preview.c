--- capplets/xkb_capplet_preview.c.orig	Wed Jul  2 19:50:07 2003
+++ capplets/xkb_capplet_preview.c	Wed Jul  2 19:56:26 2003
@@ -35,8 +35,9 @@
 static void XkbCappletPreviewRealized( GtkWidget * bonoboWidget,
                                        GSwitchItCapplet * gswic )
 {
+  GtkWidget *bonoboWindow;
   XklDebug( 150, "REALIZED\n" );
-  GtkWidget *bonoboWindow =
+  bonoboWindow =
     GTK_WIDGET( g_object_get_data( G_OBJECT( gswic->capplet ),
                                    PREVIEW_BONOBO_WINDOW_PROPERTY ) );
 
@@ -110,12 +111,13 @@
   } else
   {
     // Existing bonobo window
-    XklDebug( 150, "Reusing existing bonobo window\n" );
     GtkWidget *oldChild;
+    BonoboUIEngine *uiEngine;
+    XklDebug( 150, "Reusing existing bonobo window\n" );
     bonoboWindow = GTK_WIDGET( bw );
     bonobo_window_set_contents( BONOBO_WINDOW( bonoboWindow ), NULL );
     uiContainer = bonobo_ui_container_new(  );
-    BonoboUIEngine *uiEngine =
+    uiEngine =
       bonobo_window_get_ui_engine( BONOBO_WINDOW( bonoboWindow ) );
     bonobo_ui_container_set_engine( uiContainer, uiEngine );
   }
