--- capplets/xkb_capplet.c.orig	Thu May 15 01:41:56 2003
+++ capplets/xkb_capplet.c	Thu May 15 01:42:18 2003
@@ -222,11 +222,12 @@
                          CURRENT_OPTION_GROUP_NAME_PROPERTY, NULL );
     } else if( GTK_IS_OPTION_MENU( optionsCtl ) )       // singlesel
     {
+      const gchar *optionName;
       theItem =
         gtk_menu_get_active( GTK_MENU
                              ( gtk_option_menu_get_menu
                                ( GTK_OPTION_MENU( optionsCtl ) ) ) );
-      const gchar *optionName = gtk_widget_get_name( theItem );
+      optionName = gtk_widget_get_name( theItem );
       XklDebug( 200, "Option [%s:%s] selected \n", groupName, optionName );
       if( optionName != NULL && *optionName != '\0' )
         GSwitchItConfigXkbOptionsAdd( &gswic->config, groupName, optionName );
