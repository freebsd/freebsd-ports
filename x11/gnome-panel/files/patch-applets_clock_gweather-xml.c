--- applets/clock/gweather-xml.c.orig	2008-01-23 00:51:33.000000000 -0500
+++ applets/clock/gweather-xml.c	2008-01-23 00:52:35.000000000 -0500
@@ -359,7 +359,7 @@ gweather_xml_load_locations( GtkTreeView
 #ifdef GWEATHER_XML_LOCATION
   xml = xmlNewTextReaderFilename (GWEATHER_XML_LOCATION "Locations.xml");
 #else
-  xml = xmlNewTextReaderFilename ("/usr/share/gnome-applets/gweather/Locations.xml");
+  xml = xmlNewTextReaderFilename ("/usr/local/share/libgweather/Locations.xml");
 #endif
   if( xml == NULL )
     goto error_out;
