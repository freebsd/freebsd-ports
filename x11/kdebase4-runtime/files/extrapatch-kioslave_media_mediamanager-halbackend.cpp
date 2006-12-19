--- kioslave/media/mediamanager/halbackend.cpp.orig	Sun Oct  1 19:31:54 2006
+++ kioslave/media/mediamanager/halbackend.cpp	Tue Dec 19 11:14:04 2006
@@ -17,7 +17,6 @@
 */
 
 #include "halbackend.h"
-#include "linuxcdpolling.h"
 
 #include <stdlib.h>
 
@@ -469,28 +468,23 @@
             else
                 mimeType = "media/dvd" + MOUNT_SUFFIX;
 
-        if (libhal_volume_disc_has_audio(halVolume) && !libhal_volume_disc_has_data(halVolume))
-        {
-            mimeType = "media/audiocd";
-            medium->unmountableState( "audiocd:/?device=" + QString(libhal_volume_get_device_file(halVolume)) );
-        }
-
-        medium->setIconName(QString::null);
-
         /* check if the disc id a vcd or a video dvd */
-        DiscType type = LinuxCDPolling::identifyDiscType(libhal_volume_get_device_file(halVolume));
-        switch (type)
+        if (libhal_volume_disc_has_data(halVolume))
         {
-        case DiscType::VCD:
+        if (libhal_device_get_property_bool(m_halContext, udi, "volume.disc.is_vcd", NULL))
             mimeType = "media/vcd";
-            break;
-        case DiscType::SVCD:
+        else if (libhal_device_get_property_bool(m_halContext, udi, "volume.disc.is_svcd", NULL))
             mimeType = "media/svcd";
-            break;
-        case DiscType::DVD:
+        else if (libhal_device_get_property_bool(m_halContext, udi, "volume.disc.is_videodvd", NULL))
             mimeType = "media/dvdvideo";
-            break;
         }
+        else if (libhal_volume_disc_has_audio(halVolume))
+	{
+            mimeType = "media/audiocd";
+            medium->unmountableState( "audiocd:/?device=" + QString(libhal_volume_get_device_file(halVolume)) );
+        }
+
+        medium->setIconName(QString::null);
     }
     else
     {
