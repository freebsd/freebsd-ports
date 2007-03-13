--- kioslave/media/mediamanager/halbackend.cpp.orig	Mon Jan 15 12:31:32 2007
+++ kioslave/media/mediamanager/halbackend.cpp	Sat Mar  3 18:00:49 2007
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
 
 #include <kapplication.h>
 #include <qeventloop.h>
@@ -71,6 +76,10 @@
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
@@ -184,6 +193,10 @@
 
     libhal_free_string_array( halDeviceList );
 
+#ifdef Q_OS_FREEBSD
+    connect(&m_pollTimer, SIGNAL(timeout()),
+        this, SLOT(pollMediaList()));
+#endif
     return true;
 }
 
@@ -251,11 +264,11 @@
             }
         }
         QMap<QString,QString> options = MediaManagerUtils::splitOptions(mountoptions(udi));
-        kdDebug() << "automount " << options["automount"] << endl;
+        kdDebug(1219) << "automount " << options["automount"] << endl;
         if (options["automount"] == "true" && allowNotification ) {
             QString error = mount(medium);
             if (!error.isEmpty())
-                kdDebug() << "error " << error << endl;
+                kdDebug(1219) << "error " << error << endl;
         }
         m_mediaList.addMedium(medium, allowNotification);
 
@@ -272,6 +285,11 @@
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
 
@@ -293,12 +311,23 @@
 
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
@@ -334,7 +363,7 @@
     }
 
     const char* mediumUdi = findMediumUdiFromUdi(udi);
-    kdDebug() << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
+    kdDebug(1219) << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
     if (!mediumUdi)
         return;
 
@@ -392,7 +421,7 @@
         {
             Medium m( *cmedium );
             if ( setFstabProperties( &m ) ) {
-                kdDebug() << "setFstabProperties worked" << endl;
+                kdDebug(1219) << "setFstabProperties worked" << endl;
                 m_mediaList.changeMediumState(m, false);
             }
             return;
@@ -407,6 +436,7 @@
         setFloppyProperties(m);
     if (libhal_device_query_capability(m_halContext, mediumUdi, "camera", NULL))
         setCameraProperties(m);
+    m->setHalMounted(libhal_device_get_property_string(m_halContext, mediumUdi, "info.hal_mount.created_mount_point", NULL));
 
     m_mediaList.changeMediumState(*m, false);
 
@@ -479,28 +509,23 @@
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
@@ -584,7 +609,7 @@
             }
         }
 
-        kdDebug() << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
+        kdDebug(1219) << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
         QString fstype = medium->fsType();
         if ( fstype.isNull() )
             fstype = "auto";
@@ -794,7 +819,7 @@
         if (t.endsWith("="))
             t = t.left(t.length() - 1);
         valids[t] = true;
-        kdDebug() << "valid " << t << endl;
+        kdDebug(1219) << "valid " << t << endl;
     }
     libhal_free_string_array(array);
     QStringList result;
@@ -915,12 +940,20 @@
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
@@ -960,7 +993,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Mount"))) {
-        kdDebug() << "mount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -968,7 +1001,7 @@
                                    DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &poptions, noptions,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "mount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -996,7 +1029,7 @@
         return qerror;
     }
 
-    kdDebug() << "mount queued for " << udi << endl;
+    kdDebug(1219) << "mount queued for " << udi << endl;
 
     dbus_message_unref (dmesg);
     dbus_message_unref (reply);
@@ -1044,7 +1077,7 @@
 
 void HALBackend::slotResult(KIO::Job *job)
 {
-    kdDebug() << "slotResult " << mount_jobs[job] << endl;
+    kdDebug(1219) << "slotResult " << mount_jobs[job] << endl;
 
     struct mount_job_data *data = mount_jobs[job];
     QString& qerror = data->errorMessage;
@@ -1071,7 +1104,6 @@
         qerror = job->errorText();
     }
 
-    ResetProperties( medium->id().latin1() );
     mount_jobs.remove(job);
 
     /* Job completed. Notify the caller */
@@ -1080,6 +1112,25 @@
     kapp->eventLoop()->exitLoop();
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
@@ -1092,12 +1143,14 @@
         QString reald = (*it)->realDeviceName();
         if ( reald.endsWith( "/" ) )
             reald = reald.left( reald.length() - 1 );
-        kdDebug() << "isInFstab -" << medium->deviceNode() << "- -" << reald << "- -" << (*it)->mountedFrom() << "-" << endl;
+        kdDebug(1219) << "isInFstab -" << medium->deviceNode() << "- -" << reald << "- -" << (*it)->mountedFrom() << "-" << endl;
         if ((*it)->mountedFrom() == medium->deviceNode() || ( !medium->deviceNode().isEmpty() && reald == medium->deviceNode() ) )
 	{
+#ifndef Q_OS_FREEBSD
             QStringList opts = (*it)->mountOptions();
             if (opts.contains("user") || opts.contains("users"))
                 return (*it)->mountPoint();
+#endif
         }
     }
 
@@ -1116,7 +1169,7 @@
         data.completed = false;
         data.medium = medium;
 
-        kdDebug() << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
+        kdDebug(1219) << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
         KIO::Job *job = KIO::mount( false, 0, medium->deviceNode(), mountPoint );
         connect(job, SIGNAL( result (KIO::Job *)),
                 SLOT( slotResult( KIO::Job *)));
@@ -1134,7 +1187,7 @@
 
     QStringList soptions;
 
-    kdDebug() << "mounting " << medium->id() << "..." << endl;
+    kdDebug(1219) << "mounting " << medium->id() << "..." << endl;
 
     QMap<QString,QString> valids = MediaManagerUtils::splitOptions(mountoptions(medium->id()));
     if (valids["flush"] == "true")
@@ -1147,10 +1200,10 @@
 
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
 
@@ -1180,6 +1233,13 @@
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
@@ -1192,9 +1252,6 @@
         return qerror;
     }
 
-    medium->setHalMounted(true);
-    ResetProperties(medium->id().latin1());
-
     return QString();
 }
 
@@ -1255,7 +1312,7 @@
     const char *options[2];
 
     const char *udi = medium->id().latin1();
-    kdDebug() << "unmounting " << udi << "..." << endl;
+    kdDebug(1219) << "unmounting " << udi << "..." << endl;
 
     dbus_error_init(&error);
     DBusConnection *dbus_connection = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
@@ -1268,7 +1325,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Unmount"))) {
-        kdDebug() << "unmount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -1278,7 +1335,7 @@
     if (!dbus_message_append_args (dmesg, DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &options, 0,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "unmount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -1288,7 +1345,7 @@
     {
         QString qerror, reason;
 
-        kdDebug() << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
+        kdDebug(1219) << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
         qerror = "<qt>";
         qerror += i18n("Unfortunately, the device <b>%1</b> (%2) named <b>'%3'</b> and "
                        "currently mounted at <b>%4</b> could not be unmounted. ").arg(
@@ -1318,13 +1375,10 @@
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
