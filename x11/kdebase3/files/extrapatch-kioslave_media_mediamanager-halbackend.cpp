--- kioslave/media/mediamanager/halbackend.cpp.orig	Sun Oct  1 19:31:54 2006
+++ kioslave/media/mediamanager/halbackend.cpp	Wed Dec 20 20:22:28 2006
@@ -17,7 +17,6 @@
 */
 
 #include "halbackend.h"
-#include "linuxcdpolling.h"
 
 #include <stdlib.h>
 
@@ -242,11 +241,11 @@
         Medium* medium = new Medium(udi, "");
 
         QMap<QString,QString> options = MediaManagerUtils::splitOptions(mountoptions(udi));
-        kdDebug() << "automount " << options["automount"] << endl;
+        kdDebug(1219) << "automount " << options["automount"] << endl;
         if (options["automount"] == "true" && allowNotification ) {
             QString error = mount(medium);
             if (!error.isEmpty())
-                kdDebug() << "error " << error << endl;
+                kdDebug(1219) << "error " << error << endl;
         }
         setVolumeProperties(medium);
         m_mediaList.addMedium(medium, allowNotification);
@@ -326,7 +325,7 @@
     }
 
     const char* mediumUdi = findMediumUdiFromUdi(udi);
-    kdDebug() << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
+    kdDebug(1219) << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
     if (!mediumUdi)
         return;
 
@@ -384,7 +383,7 @@
         {
             Medium m( *cmedium );
             if ( setFstabProperties( &m ) ) {
-                kdDebug() << "setFstabProperties worked" << endl;
+                kdDebug(1219) << "setFstabProperties worked" << endl;
                 m_mediaList.changeMediumState(m, false);
             }
             return;
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
@@ -575,7 +569,7 @@
             }
         }
 
-        kdDebug() << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
+        kdDebug(1219) << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
         QString fstype = medium->fsType();
         if ( fstype.isNull() )
             fstype = "auto";
@@ -762,7 +756,7 @@
         if (t.endsWith("="))
             t = t.left(t.length() - 1);
         valids[t] = true;
-        kdDebug() << "valid " << t << endl;
+        kdDebug(1219) << "valid " << t << endl;
     }
     libhal_free_string_array(array);
     QStringList result;
@@ -887,7 +881,7 @@
 
 bool HALBackend::setMountoptions(const QString &name, const QStringList &options )
 {
-    kdDebug() << "setMountoptions " << name << " " << options << endl;
+    kdDebug(1219) << "setMountoptions " << name << " " << options << endl;
 
     KConfig config("mediamanagerrc");
     config.setGroup(name);
@@ -927,7 +921,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Mount"))) {
-        kdDebug() << "mount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -935,7 +929,7 @@
                                    DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &poptions, noptions,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "mount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -963,7 +957,7 @@
         return qerror;
     }
 
-    kdDebug() << "mount queued for " << udi << endl;
+    kdDebug(1219) << "mount queued for " << udi << endl;
 
     dbus_message_unref (dmesg);
     dbus_message_unref (reply);
@@ -974,7 +968,7 @@
 
 void HALBackend::slotResult(KIO::Job *job)
 {
-    kdDebug() << "slotResult " << mount_jobs[job] << endl;
+    kdDebug(1219) << "slotResult " << mount_jobs[job] << endl;
     if (job->error())
     {
         KMessageBox::error(0, job->errorText());
@@ -992,7 +986,7 @@
 
     for (; it!=end; ++it)
     {
-        kdDebug() << "isInFstab -" << medium->deviceNode() << "- -" << (*it)->realDeviceName() << "- -" << (*it)->mountedFrom() << endl;
+        kdDebug(1219) << "isInFstab -" << medium->deviceNode() << "- -" << (*it)->realDeviceName() << "- -" << (*it)->mountedFrom() << endl;
         if ((*it)->mountedFrom() == medium->deviceNode() || ( !medium->deviceNode().isEmpty() && (*it)->realDeviceName() == medium->deviceNode() ) )
 	{
             QStringList opts = (*it)->mountOptions();
@@ -1012,7 +1006,7 @@
     QString mountPoint = isInFstab(medium);
     if (!mountPoint.isNull())
     {
-        kdDebug() << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
+        kdDebug(1219) << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
         KIO::Job *job = KIO::mount( false, 0, medium->deviceNode(), mountPoint );
         connect(job, SIGNAL( result (KIO::Job *)),
                 SLOT( slotResult( KIO::Job *)));
@@ -1023,7 +1017,7 @@
 
     QStringList soptions;
 
-    kdDebug() << "mounting " << medium->id() << "..." << endl;
+    kdDebug(1219) << "mounting " << medium->id() << "..." << endl;
 
     QMap<QString,QString> valids = MediaManagerUtils::splitOptions(mountoptions(medium->id()));
     if (valids["flush"] == "true")
@@ -1036,10 +1030,10 @@
 
     if (valids["ro"] == "true")
         soptions << "ro";
-
+#if 0
     if (valids["atime"] != "true")
         soptions << "noatime";
-
+#endif
     if (valids["quiet"] == "true")
         soptions << "quiet";
 
@@ -1121,7 +1115,7 @@
     QString mountPoint = isInFstab(medium);
     if (!mountPoint.isNull())
     {
-        kdDebug() << "triggering user unmount " << medium->deviceNode() << " " << mountPoint << endl;
+        kdDebug(1219) << "triggering user unmount " << medium->deviceNode() << " " << mountPoint << endl;
         KIO::Job *job = KIO::unmount( medium->mountPoint(), false );
         connect(job, SIGNAL( result (KIO::Job *)),
                 SLOT( slotResult( KIO::Job *)));
@@ -1134,7 +1128,7 @@
     const char *options[2];
 
     const char *udi = medium->id().latin1();
-    kdDebug() << "unmounting " << udi << "..." << endl;
+    kdDebug(1219) << "unmounting " << udi << "..." << endl;
 
     dbus_error_init(&error);
     DBusConnection *dbus_connection = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
@@ -1147,7 +1141,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Unmount"))) {
-        kdDebug() << "unmount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -1157,7 +1151,7 @@
     if (!dbus_message_append_args (dmesg, DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &options, 0,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "unmount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -1165,7 +1159,7 @@
     dbus_error_init (&error);
     if (!(reply = dbus_connection_send_with_reply_and_block (dbus_connection, dmesg, -1, &error)))
     {
-        kdDebug() << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
+        kdDebug(1219) << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
         QString qerror = error.message;
         if (!strcmp(error.name, "org.freedesktop.Hal.Device.Volume.Busy")) {
             qerror = QString("<qt>") + i18n("Device is Busy:");
@@ -1201,7 +1195,7 @@
         return qerror;
     }
 
-    kdDebug() << "unmount queued for " << udi << endl;
+    kdDebug(1219) << "unmount queued for " << udi << endl;
 
     dbus_message_unref (dmesg);
     dbus_message_unref (reply);
