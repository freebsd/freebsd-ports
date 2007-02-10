--- kioslave/media/mediamanager/halbackend.cpp.orig	Sun Oct  1 21:31:54 2006
+++ kioslave/media/mediamanager/halbackend.cpp	Fri Feb  9 22:01:27 2007
@@ -17,9 +17,14 @@
 */
 
 #include "halbackend.h"
-#include "linuxcdpolling.h"
 
 #include <stdlib.h>
+#ifdef Q_OS_FREEBSD
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#include <langinfo.h>
+#endif
 
 #include <qfile.h>
 #include <klocale.h>
@@ -66,6 +71,10 @@
     /* Close HAL connection */
     if (m_halContext)
     {
+#ifdef Q_OS_FREEBSD
+        m_pollTimer.stop();
+        m_pollMediaList.clear();
+#endif
         const QPtrList<Medium> medlist = m_mediaList.list();
         QPtrListIterator<Medium> it (medlist);
         for ( const Medium *current_medium = it.current(); current_medium; current_medium = ++it)
@@ -185,6 +194,10 @@
 
     libhal_free_string_array( halDeviceList );
 
+#ifdef Q_OS_FREEBSD
+    connect(&m_pollTimer, SIGNAL(timeout()),
+        this, SLOT(pollMediaList()));
+#endif
     return true;
 }
 
@@ -242,11 +255,11 @@
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
@@ -264,6 +277,11 @@
             Medium* medium = new Medium(udi, "");
             setFloppyProperties(medium);
             m_mediaList.addMedium(medium, allowNotification);
+#ifdef Q_OS_FREEBSD
+            m_pollTimer.stop();
+            m_pollMediaList.append(medium);
+            m_pollTimer.start(250);
+#endif
             return;
         }
 
@@ -285,12 +303,23 @@
 
 void HALBackend::RemoveDevice(const char *udi)
 {
+#ifdef Q_OS_FREEBSD
+    m_pollMediaList.remove(m_mediaList.findById(udi));
+    if (m_pollMediaList.isEmpty())
+        m_pollTimer.stop();
+#endif
     m_mediaList.removeMedium(udi, true);
 }
 
 void HALBackend::ModifyDevice(const char *udi, const char* key)
 {
-    Q_UNUSED(key);
+    if (
+        !( strcmp(key, "info.hal_mount.created_mount_point")
+        && strcmp(key, "info.hal_mount.mounted_by_uid")
+        && strcmp(key, "volume.mount_point")
+        && strcmp(key, "volume.is_mounted_read_only")))
+        return;
+
     const char* mediumUdi = findMediumUdiFromUdi(udi);
     if (!mediumUdi)
         return;
@@ -326,7 +355,7 @@
     }
 
     const char* mediumUdi = findMediumUdiFromUdi(udi);
-    kdDebug() << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
+    kdDebug(1219) << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
     if (!mediumUdi)
         return;
 
@@ -384,7 +413,7 @@
         {
             Medium m( *cmedium );
             if ( setFstabProperties( &m ) ) {
-                kdDebug() << "setFstabProperties worked" << endl;
+                kdDebug(1219) << "setFstabProperties worked" << endl;
                 m_mediaList.changeMediumState(m, false);
             }
             return;
@@ -399,6 +428,7 @@
         setFloppyProperties(m);
     if (libhal_device_query_capability(m_halContext, mediumUdi, "camera", NULL))
         setCameraProperties(m);
+    m->setHalMounted(libhal_device_get_property_string(m_halContext, mediumUdi, "info.hal_mount.created_mount_point", NULL));
 
     m_mediaList.changeMediumState(*m, false);
 
@@ -469,28 +499,23 @@
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
@@ -575,7 +600,7 @@
             }
         }
 
-        kdDebug() << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
+        kdDebug(1219) << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
         QString fstype = medium->fsType();
         if ( fstype.isNull() )
             fstype = "auto";
@@ -762,7 +787,7 @@
         if (t.endsWith("="))
             t = t.left(t.length() - 1);
         valids[t] = true;
-        kdDebug() << "valid " << t << endl;
+        kdDebug(1219) << "valid " << t << endl;
     }
     libhal_free_string_array(array);
     QStringList result;
@@ -882,12 +908,20 @@
             result << "journaling=ordered";
     }
 
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("-C"))
+    {
+        result << QString("charset=%1").arg(nl_langinfo(CODESET));
+        kdDebug(1219) << "mount properties " << result << " " << endl;
+    }
+#endif
+
     return result;
 }
 
 bool HALBackend::setMountoptions(const QString &name, const QStringList &options )
 {
-    kdDebug() << "setMountoptions " << name << " " << options << endl;
+    kdDebug(1219) << "setMountoptions " << name << " " << options << endl;
 
     KConfig config("mediamanagerrc");
     config.setGroup(name);
@@ -927,7 +959,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Mount"))) {
-        kdDebug() << "mount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -935,7 +967,7 @@
                                    DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &poptions, noptions,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "mount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -963,7 +995,7 @@
         return qerror;
     }
 
-    kdDebug() << "mount queued for " << udi << endl;
+    kdDebug(1219) << "mount queued for " << udi << endl;
 
     dbus_message_unref (dmesg);
     dbus_message_unref (reply);
@@ -974,15 +1006,33 @@
 
 void HALBackend::slotResult(KIO::Job *job)
 {
-    kdDebug() << "slotResult " << mount_jobs[job] << endl;
+    kdDebug(1219) << "slotResult " << mount_jobs[job] << endl;
     if (job->error())
     {
         KMessageBox::error(0, job->errorText());
     }
-    ResetProperties( mount_jobs[job].latin1() );
     mount_jobs.remove(job);
 }
 
+#ifdef Q_OS_FREEBSD
+void HALBackend::pollMediaList()
+{
+    struct statfs *mntBuf;
+    int mntNum = getmntinfo(&mntBuf, MNT_NOWAIT);
+    QPtrList<Medium>::iterator it = m_pollMediaList.begin();
+    QPtrList<Medium>::iterator end = m_pollMediaList.end();
+    for (; it!=end; ++it)
+    {
+        bool mounted = false;
+        const char *dev = (*it)->deviceNode().ascii();
+        for (int n = mntNum-1; n >= 0 && !mounted; n--) 
+            mounted = !strcmp(dev, mntBuf[n].f_mntfromname);
+        if ((*it)->isMounted() != mounted)
+            ResetProperties((*it)->id().latin1());
+    }
+}
+#endif
+
 QString HALBackend::isInFstab(const Medium *medium)
 {
     KMountPoint::List fstab = KMountPoint::possibleMountPoints(KMountPoint::NeedMountOptions|KMountPoint::NeedRealDeviceName);
@@ -992,11 +1042,13 @@
 
     for (; it!=end; ++it)
     {
-        kdDebug() << "isInFstab -" << medium->deviceNode() << "- -" << (*it)->realDeviceName() << "- -" << (*it)->mountedFrom() << endl;
+        kdDebug(1219) << "isInFstab -" << medium->deviceNode() << "- -" << (*it)->realDeviceName() << "- -" << (*it)->mountedFrom() << endl;
         if ((*it)->mountedFrom() == medium->deviceNode() || ( !medium->deviceNode().isEmpty() && (*it)->realDeviceName() == medium->deviceNode() ) )
 	{
+#ifndef Q_OS_FREEBSD
             QStringList opts = (*it)->mountOptions();
             if (opts.contains("user") || opts.contains("users"))
+#endif
                 return (*it)->mountPoint();
         }
     }
@@ -1012,7 +1064,7 @@
     QString mountPoint = isInFstab(medium);
     if (!mountPoint.isNull())
     {
-        kdDebug() << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
+        kdDebug(1219) << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
         KIO::Job *job = KIO::mount( false, 0, medium->deviceNode(), mountPoint );
         connect(job, SIGNAL( result (KIO::Job *)),
                 SLOT( slotResult( KIO::Job *)));
@@ -1023,7 +1075,7 @@
 
     QStringList soptions;
 
-    kdDebug() << "mounting " << medium->id() << "..." << endl;
+    kdDebug(1219) << "mounting " << medium->id() << "..." << endl;
 
     QMap<QString,QString> valids = MediaManagerUtils::splitOptions(mountoptions(medium->id()));
     if (valids["flush"] == "true")
@@ -1036,10 +1088,10 @@
 
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
 
@@ -1069,6 +1121,13 @@
             soptions << QString("data=ordered");
     }
 
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("charset"))
+    {
+        soptions << QString("-C=%1").arg(valids["charset"]);
+    }
+#endif
+
     const char **options = new const char*[soptions.size() + 1];
     uint noptions = 0;
     for (QStringList::ConstIterator it = soptions.begin(); it != soptions.end(); ++it, ++noptions)
@@ -1081,9 +1140,6 @@
         return qerror;
     }
 
-    medium->setHalMounted(true);
-    ResetProperties(medium->id().latin1());
-
     return QString();
 }
 
@@ -1121,7 +1177,7 @@
     QString mountPoint = isInFstab(medium);
     if (!mountPoint.isNull())
     {
-        kdDebug() << "triggering user unmount " << medium->deviceNode() << " " << mountPoint << endl;
+        kdDebug(1219) << "triggering user unmount " << medium->deviceNode() << " " << mountPoint << endl;
         KIO::Job *job = KIO::unmount( medium->mountPoint(), false );
         connect(job, SIGNAL( result (KIO::Job *)),
                 SLOT( slotResult( KIO::Job *)));
@@ -1134,7 +1190,7 @@
     const char *options[2];
 
     const char *udi = medium->id().latin1();
-    kdDebug() << "unmounting " << udi << "..." << endl;
+    kdDebug(1219) << "unmounting " << udi << "..." << endl;
 
     dbus_error_init(&error);
     DBusConnection *dbus_connection = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
@@ -1147,7 +1203,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Unmount"))) {
-        kdDebug() << "unmount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -1157,7 +1213,7 @@
     if (!dbus_message_append_args (dmesg, DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &options, 0,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "unmount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -1165,7 +1221,7 @@
     dbus_error_init (&error);
     if (!(reply = dbus_connection_send_with_reply_and_block (dbus_connection, dmesg, -1, &error)))
     {
-        kdDebug() << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
+        kdDebug(1219) << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
         QString qerror = error.message;
         if (!strcmp(error.name, "org.freedesktop.Hal.Device.Volume.Busy")) {
             qerror = QString("<qt>") + i18n("Device is Busy:");
@@ -1201,13 +1257,10 @@
         return qerror;
     }
 
-    kdDebug() << "unmount queued for " << udi << endl;
+    kdDebug(1219) << "unmount queued for " << udi << endl;
 
     dbus_message_unref (dmesg);
     dbus_message_unref (reply);
-
-    medium->setHalMounted(false);
-    ResetProperties(udi);
 
     return QString();
 }
