--- kioslave/media/mediamanager/halbackend.cpp.orig	Mon May 14 09:55:40 2007
+++ kioslave/media/mediamanager/halbackend.cpp	Sat Jun  2 11:40:22 2007
@@ -17,9 +17,15 @@
 */
 
 #include "halbackend.h"
-#include "linuxcdpolling.h"
 
 #include <stdlib.h>
+#ifdef Q_OS_FREEBSD
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#include <langinfo.h>
+#include <qregexp.h>
+#endif
 
 #include <kapplication.h>
 #include <qeventloop.h>
@@ -71,6 +77,10 @@
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
@@ -184,6 +194,10 @@
 
     libhal_free_string_array( halDeviceList );
 
+#ifdef Q_OS_FREEBSD
+    connect(&m_pollTimer, SIGNAL(timeout()),
+        this, SLOT(pollMediaList()));
+#endif
     return true;
 }
 
@@ -245,11 +259,11 @@
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
 
@@ -264,6 +278,11 @@
         {
             /* Create medium */
             Medium* medium = new Medium(udi, "");
+#ifdef Q_OS_FREEBSD
+            m_pollTimer.stop();
+            m_pollMediaList.append(medium);
+            m_pollTimer.start(250);
+#endif
             // if the storage has a volume, we ignore it
             if ( setFloppyProperties(medium) )
                 m_mediaList.addMedium(medium, allowNotification);
@@ -290,12 +309,23 @@
 
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
@@ -331,7 +361,7 @@
     }
 
     const char* mediumUdi = findMediumUdiFromUdi(udi);
-    kdDebug() << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
+    kdDebug(1219) << "findMedumUdiFromUdi " << udi << " returned " << mediumUdi << endl;
     if (!mediumUdi)
         return;
 
@@ -389,7 +419,7 @@
         {
             Medium m( *cmedium );
             if ( setFstabProperties( &m ) ) {
-                kdDebug() << "setFstabProperties worked" << endl;
+                kdDebug(1219) << "setFstabProperties worked" << endl;
                 m_mediaList.changeMediumState(m, false);
             }
             return;
@@ -404,6 +434,7 @@
         setFloppyProperties(m);
     if (libhal_device_query_capability(m_halContext, mediumUdi, "camera", NULL))
         setCameraProperties(m);
+    m->setHalMounted(libhal_device_get_property_string(m_halContext, mediumUdi, "info.hal_mount.created_mount_point", NULL));
 
     m_mediaList.changeMediumState(*m, false);
 
@@ -476,28 +507,23 @@
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
@@ -581,7 +607,7 @@
             }
         }
 
-        kdDebug() << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
+        kdDebug(1219) << mp << " " << mounted << " " << medium->deviceNode() << " " <<  endl;
         QString fstype = medium->fsType();
         if ( fstype.isNull() )
             fstype = "auto";
@@ -766,7 +792,32 @@
     if (medium && !isInFstab(medium).isNull())
         return QStringList(); // not handled by HAL - fstab entry
 
+		const char *boolOptionNames[] = { "ro", "quiet", "atime", "uid", "utf8", "flush", "sync", 0 };
+		const char *stringOptionNames[] = { "shortname", "journaling", "mountpoint", "automount",
+#ifdef Q_OS_FREEBSD
+				"filemask", "dirmask", "charset", "locale", "doscodepage",
+#endif
+				0 };
+
     KConfig config("mediamanagerrc");
+    config.setGroup("General");
+    QMap<QString,QString> options;
+    for (int index = 0; boolOptionNames[index]; ++index)
+        if (config.hasKey(boolOptionNames[index]))
+            options.insert(boolOptionNames[index],
+                config.readBoolEntry(boolOptionNames[index]) ? "true" : "false");
+    for (int index = 0; stringOptionNames[index]; ++index)
+        if (config.hasKey(stringOptionNames[index]))
+            options.insert(stringOptionNames[index],
+                config.readEntry(stringOptionNames[index]));
+    if (!libhal_device_exists(m_halContext, name.latin1(), NULL))
+    {
+        QStringList result;
+        if (name.lower() == "general")
+        for (QMap<QString,QString>::ConstIterator it = options.begin(); it != options.end(); ++it)
+            result << it.key() + '=' + it.data();
+        return result;
+    }		
     config.setGroup(name);
 
     char ** array = libhal_device_get_property_strlist(m_halContext, name.latin1(), "volume.mount.valid_options", NULL);
@@ -777,25 +828,68 @@
         if (t.endsWith("="))
             t = t.left(t.length() - 1);
         valids[t] = true;
-        kdDebug() << "valid " << t << endl;
+        kdDebug(1219) << "valid " << t << endl;
     }
     libhal_free_string_array(array);
     QStringList result;
     QString tmp;
 
+    QMap<QString,QString> halOptions;
+    LibHalVolume* halVolume = libhal_volume_from_udi(m_halContext, name.latin1());
+    if (!halVolume)
+    {
+        LibHalDrive *halDrive  = libhal_drive_from_udi(m_halContext, name.latin1());
+        if (halDrive)
+        {
+            tmp = QString::fromLatin1(libhal_drive_policy_get_mount_options(halDrive, NULL));
+            libhal_drive_free(halDrive);
+        }
+    }
+    else
+    {
+        const char *driveUdi = libhal_volume_get_storage_device_udi(halVolume);
+        LibHalDrive *halDrive  = !driveUdi ? 0 : libhal_drive_from_udi(m_halContext, driveUdi);
+        if (halDrive)
+        {
+            tmp = QString::fromLatin1(libhal_volume_policy_get_mount_options(halDrive, halVolume, NULL));
+            libhal_drive_free(halDrive);
+        }
+        libhal_volume_free(halVolume);
+    }
+    if (!tmp.isEmpty())
+    {
+        uint start = 0;
+        while(start < tmp.length())
+        {
+            int end = tmp.find(',', start);
+            if (end == -1) end = tmp.length();
+            QString opt = tmp.mid( start, end - start );
+            start = end + 1;
+            end = opt.find('=');
+            QString key = opt.left(end);
+            if (valids.contains(key))
+                halOptions.insert(key, end == -1 ? QString::null : opt.mid(end + 1));
+        }
+    }
+
     QString fstype = libhal_device_get_property_QString(m_halContext, name.latin1(), "volume.fstype");
     if (fstype.isNull())
         fstype = libhal_device_get_property_QString(m_halContext, name.latin1(), "volume.policy.mount_filesystem");
 
     QString drive_udi = libhal_device_get_property_QString(m_halContext, name.latin1(), "block.storage_device");
 
+    bool value = false;
     bool removable = false;
     if ( !drive_udi.isNull() )
+    {
+        value = libhal_device_get_property_bool(m_halContext, drive_udi.latin1(), "storage.automount_enabled_hint", NULL);
         removable = libhal_device_get_property_bool(m_halContext, drive_udi.latin1(), "storage.removable", NULL)
-                     || libhal_device_get_property_bool(m_halContext, drive_udi.latin1(), "storage.hotpluggable", NULL);
+                     || libhal_device_get_property_bool(m_halContext, drive_udi.latin1(), "storage.hotpluggable", NULL);				
+    }
 
     config.setGroup(drive_udi);
-    bool value = config.readBoolEntry("automount", false);
+    value = config.readBoolEntry("automount",
+        !options.contains("automount") ? value : options["automount"] == "true" );
     config.setGroup(name);
 
     if (libhal_device_get_property_bool(m_halContext, name.latin1(), "volume.disc.is_blank", NULL)
@@ -809,44 +903,98 @@
 
     if (valids.contains("ro"))
     {
-        value = config.readBoolEntry("ro", false);
+        value = options.contains("ro") ? options["ro"] == "true"
+            : halOptions.contains("ro");
+        value = config.readBoolEntry("ro", value);
         tmp = QString("ro=%1").arg(value ? "true" : "false");
         if (fstype != "iso9660") // makes no sense
             result << tmp;
+        halOptions.remove("ro");
     }
 
     if (valids.contains("quiet"))
     {
-        value = config.readBoolEntry("quiet", false);
+        value = options.contains("quiet") ? options["quiet"] == "true"
+            : halOptions.contains("quiet");
+        value = config.readBoolEntry("quiet",  value);
         tmp = QString("quiet=%1").arg(value ? "true" : "false");
         if (fstype != "iso9660") // makes no sense
             result << tmp;
+        halOptions.remove("quiet");
     }
 
     if (valids.contains("flush"))
     {
-        value = config.readBoolEntry("flush", fstype.endsWith("fat"));
+        value = options.contains("flush") ? options["flush"] == "true"
+            : (halOptions.contains("flush") || fstype.endsWith("fat"));
+        value = config.readBoolEntry("flush", value);
         tmp = QString("flush=%1").arg(value ? "true" : "false");
         result << tmp;
+        halOptions.remove("flush");
     }
 
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("-u"))
+#else
     if (valids.contains("uid"))
+#endif
     {
-        value = config.readBoolEntry("uid", true);
+        value = !options.contains("uid") ? true : options["uid"] == "true";
+        value = config.readBoolEntry("uid", value);
         tmp = QString("uid=%1").arg(value ? "true" : "false");
         result << tmp;
+#ifdef Q_OS_FREEBSD
+        halOptions.remove("-u");
+#else
+        halOptions.remove("uid");
+#endif
     }
 
     if (valids.contains("utf8"))
     {
-        value = config.readBoolEntry("utf8", true);
+        value = !options.contains("iocharset") && !halOptions.contains("iocharset") 
+            && (options.contains("utf8") ? options["utf8"] == "true"
+            : halOptions.contains("utf8"));
+        value = config.readBoolEntry("utf8", value);
         tmp = QString("utf8=%1").arg(value ? "true" : "false");
         result << tmp;
+        halOptions.remove("utf8");
     }
 
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("nowin95")
+        && valids.contains("longnames")
+        && valids.contains("shortnames"))
+    {
+        QString svalue = "winnt";
+        if (halOptions.contains("longnames") && !halOptions.contains("shortnames") && !halOptions.contains("nowin95"))
+            svalue = "winnt";
+        else if (!halOptions.contains("longnames") && halOptions.contains("shortnames") && !halOptions.contains("nowin95"))
+            svalue = "win95";
+        else if (halOptions.contains("longnames") && halOptions.contains("shortnames") && !halOptions.contains("nowin95"))
+            svalue = "mixed";
+        else if (halOptions.contains("nowin95"))
+            svalue = "lower";
+        svalue = config.readEntry("shortname",
+            options.contains("shortname") ? options["shortname"] : svalue);
+        if (svalue == "winnt")
+            result << "shortname=winnt";
+        else if (svalue == "win95")
+            result << "shortname=win95";
+        else if (svalue == "mixed")
+            result << "shortname=mixed";
+        else
+            result << "shortname=lower";
+        halOptions.remove("nowin95");
+        halOptions.remove("longnames");
+        halOptions.remove("shortnames");
+    }
+#else
     if (valids.contains("shortname"))
     {
-        QString svalue = config.readEntry("shortname", "lower").lower();
+        QString svalue = options.contains("shortname") ? options["shortname"]
+						: (halOptions.contains("shortname") ? halOptions["shortname"] : "winnt");
+        svalue = config.readEntry("shortname", svalue).lower();
         if (svalue == "winnt")
             result << "shortname=winnt";
         else if (svalue == "win95")
@@ -856,28 +1004,36 @@
         else
             result << "shortname=lower";
     }
-
+#endif
     if (valids.contains("sync"))
     {
-        value = config.readBoolEntry("sync", ( valids.contains("flush") && !fstype.endsWith("fat") ) && removable);
+        value = options.contains("sync") ? options["sync"] == "true"
+                                               : (halOptions.contains("sync") || ((valids.contains("flush") && !fstype.endsWith("fat")) && removable));
+        value = config.readBoolEntry("sync", value);
         tmp = QString("sync=%1").arg(value ? "true" : "false");
         if (fstype != "iso9660") // makes no sense
             result << tmp;
+        halOptions.remove("sync");
     }
 
     if (valids.contains("noatime"))
     {
         value = config.readBoolEntry("atime", !fstype.endsWith("fat"));
+        value = options.contains("atime") ? options["atime"] == "true"
+                                               : (halOptions.contains("noatime") ? false : !fstype.endsWith("fat"));
+        value = config.readBoolEntry("atime", value);
         tmp = QString("atime=%1").arg(value ? "true" : "false");
         if (fstype != "iso9660") // makes no sense
             result << tmp;
+        halOptions.remove("noatime");
     }
 
     QString mount_point = libhal_device_get_property_QString(m_halContext, name.latin1(), "volume.mount_point");
     if (mount_point.isEmpty())
         mount_point = libhal_device_get_property_QString(m_halContext, name.latin1(), "volume.policy.desired_mount_point");
 
-    mount_point = config.readEntry("mountpoint", mount_point);
+    mount_point = config.readEntry("mountpoint",
+        options.contains("mountpoint") ? options["mountpoint"] : mount_point);
 
     if (!mount_point.startsWith("/"))
         mount_point = "/media/" + mount_point;
@@ -887,7 +1043,9 @@
 
     if (valids.contains("data"))
     {
-        QString svalue = config.readEntry("journaling").lower();
+        QString svalue = options.contains("journaling") ? options["journaling"]
+						: (halOptions.contains("data") ? halOptions["data"] : "ordered");
+        svalue = config.readEntry("journaling", svalue).lower();
         if (svalue == "ordered")
             result << "journaling=ordered";
         else if (svalue == "writeback")
@@ -896,6 +1054,82 @@
             result << "journaling=data";
         else
             result << "journaling=ordered";
+        halOptions.remove("data");
+    }
+
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("-m"))
+    {
+        QString svalue = options.contains("filemask") ? options["filemask"]
+            : (halOptions.contains("-m") ? halOptions["-m"] : QString::null);
+        svalue = config.readEntry("filemask", svalue);
+        if (!svalue.isEmpty())
+            result << QString("filemask=%1").arg(svalue);
+        halOptions.remove("-m");
+        kdDebug(1219) << "mount properties " << result << " " << endl;
+    }
+
+    if (valids.contains("-M"))
+    {
+        QString svalue = options.contains("dirmask") ? options["dirmask"]
+            : (halOptions.contains("-M") ? halOptions["-M"] : QString::null);
+        svalue = config.readEntry("dirmask", svalue);
+        if (!svalue.isEmpty())
+            result << QString("dirmask=%1").arg(svalue);
+        halOptions.remove("-M");
+        kdDebug(1219) << "mount properties " << result << " " << endl;
+    }
+
+    if (valids.contains("-C"))
+    {
+        QString svalue = options.contains("charset") ? options["charset"]
+            : (halOptions.contains("-C") ? halOptions["-C"] : nl_langinfo(CODESET));
+        svalue = config.readEntry("charset", svalue);
+        if (!svalue.isEmpty())
+            result << QString("charset=%1").arg(svalue);
+        halOptions.remove("-C");
+        kdDebug(1219) << "mount properties " << result << " " << endl;
+    }
+
+    if (valids.contains("-L"))
+    {
+        QString locale = getenv("LANG");
+        if (locale.isEmpty()) locale = getenv("LC_ALL");
+        QString svalue = options.contains("locale") ? options["locale"]
+            : (halOptions.contains("-L") ? halOptions["-L"] : locale );
+        svalue = config.readEntry("locale", svalue);
+        if (!svalue.isEmpty())
+            result << QString("locale=%1").arg(svalue);
+        halOptions.remove("-L");
+        kdDebug(1219) << "mount properties " << result << " " << endl;
+    }
+
+    if (valids.contains("-D"))
+    {
+        QString svalue = options.contains("doscodepage") ? options["doscodepage"]
+            : (halOptions.contains("-D") ? halOptions["-D"] : nl_langinfo(CODESET));
+        svalue = config.readEntry("doscodepage", svalue);
+        if (!svalue.isEmpty())
+            result << QString("doscodepage=%1").arg(svalue);
+        halOptions.remove("-D");
+        kdDebug(1219) << "mount properties " << result << " " << endl;
+    }
+#endif
+
+    if (!halOptions.isEmpty())
+    {
+        QString svalue;
+        for (QMap<QString,QString>::ConstIterator it = halOptions.begin(); it != halOptions.end(); ++it)
+        {
+            if (it != halOptions.begin())
+								svalue += ',';
+            svalue += it.key();
+            if (!it.data().isEmpty())
+            svalue += '=' + it.data();
+        }
+        if (!svalue.isEmpty())
+            result << QString("options=%1").arg(svalue);
+        kdDebug(1219) << "mount properties " << result << " " << endl;
     }
 
     return result;
@@ -903,32 +1137,82 @@
 
 bool HALBackend::setMountoptions(const QString &name, const QStringList &options )
 {
-    kdDebug() << "setMountoptions " << name << " " << options << endl;
+    kdDebug(1219) << "setMountoptions " << name << " " << options << endl;
 
     KConfig config("mediamanagerrc");
-    config.setGroup(name);
+    config.setGroup(name.lower() == "general" ? "General" : name);
 
     QMap<QString,QString> valids = MediaManagerUtils::splitOptions(options);
 
     const char *names[] = { "ro", "quiet", "atime", "uid", "utf8", "flush", "sync", 0 };
     for (int index = 0; names[index]; ++index)
         if (valids.contains(names[index]))
-            config.writeEntry(names[index], valids[names[index]] == "true");
+            if (valids[names[index]].isEmpty())
+                config.deleteEntry(names[index]);
+            else
+                config.writeEntry(names[index], valids[names[index]] == "true");
 
     if (valids.contains("shortname"))
-        config.writeEntry("shortname", valids["shortname"]);
+        if (valids["shortname"].isEmpty())
+            config.deleteEntry("shortname");
+        else
+            config.writeEntry("shortname", valids["shortname"]);
 
     if (valids.contains("journaling"))
-        config.writeEntry("journaling", valids["journaling"]);
+        if (valids["journaling"].isEmpty())
+            config.deleteEntry("journaling");
+        else
+            config.writeEntry("journaling", valids["journaling"]);
 
-    if (!mountoptions(name).contains(QString("mountpoint=%1").arg(valids["mountpoint"])))
-        config.writeEntry("mountpoint", valids["mountpoint"]);
+        if (valids.contains("mountpoint"))
+        if (valids["mountpoint"].isEmpty())
+            config.deleteEntry("mountpoint");
+        else if (!mountoptions(name).contains(QString("mountpoint=%1").arg(valids["mountpoint"])))
+            config.writeEntry("mountpoint", valids["mountpoint"]);
+
+        if (valids.contains("automount"))
+            if (valids["automount"].isEmpty())
+                config.deleteEntry("automount");
+            else
+            {
+                QString drive_udi = libhal_device_exists(m_halContext, name.latin1(), NULL)
+                    ? libhal_device_get_property_QString(m_halContext, name.latin1(), "block.storage_device")
+                    : (name.lower() == "general" ? "General" : name);
+                config.setGroup(drive_udi);
+                config.writeEntry("automount", valids["automount"]);
+            }
 
-    if (valids.contains("automount")) {
-        QString drive_udi = libhal_device_get_property_QString(m_halContext, name.latin1(), "block.storage_device");
-        config.setGroup(drive_udi);
-        config.writeEntry("automount", valids["automount"]);
-    }
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("filemask"))
+        if (valids["filemask"].isEmpty())
+						config.deleteEntry("filemask");
+        else
+						config.writeEntry("filemask", valids["filemask"]);
+
+    if (valids.contains("dirmask"))
+        if (valids["dirmask"].isEmpty())
+						config.deleteEntry("dirmask");
+        else
+						config.writeEntry("dirmask", valids["dirmask"]);
+
+    if (valids.contains("charset"))
+        if (valids["charset"].isEmpty())
+						config.deleteEntry("charset");
+        else
+						config.writeEntry("charset", valids["charset"]);
+
+    if (valids.contains("locale"))
+        if (valids["locale"].isEmpty())
+						config.deleteEntry("locale");
+        else
+						config.writeEntry("locale", valids["locale"]);
+
+    if (valids.contains("doscodepage"))
+        if (valids["doscodepage"].isEmpty())
+						config.deleteEntry("doscodepage");
+        else
+						config.writeEntry("doscodepage", valids["doscodepage"]);
+#endif
 
     return true;
 }
@@ -943,7 +1227,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Mount"))) {
-        kdDebug() << "mount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -951,7 +1235,7 @@
                                    DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &poptions, noptions,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "mount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "mount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -979,7 +1263,7 @@
         return qerror;
     }
 
-    kdDebug() << "mount queued for " << udi << endl;
+    kdDebug(1219) << "mount queued for " << udi << endl;
 
     dbus_message_unref (dmesg);
     dbus_message_unref (reply);
@@ -991,8 +1275,13 @@
 QString HALBackend::listUsingProcesses(const Medium* medium)
 {
     QString proclist, fullmsg;
+#ifndef Q_OS_FREEBSD
     QString cmdline = QString("/usr/bin/env fuser -vm %1 2>&1").arg(KProcess::quote(medium->mountPoint()));
-    FILE *fuser = popen(cmdline.latin1(), "r");
+#else
+    QString cmdline = QString("{ fstat -m | awk '$5~/^(MOUNT|%1)/' | column -t; } 2>&1")
+			.arg(QRegExp::escape(medium->mountPoint()).replace('/', "\\/"));
+#endif
+    FILE *fuser = popen(cmdline.local8Bit(), "r");
 
     uint counter = 0;
     if (fuser) {
@@ -1027,7 +1316,7 @@
 
 void HALBackend::slotResult(KIO::Job *job)
 {
-    kdDebug() << "slotResult " << mount_jobs[job] << endl;
+    kdDebug(1219) << "slotResult " << mount_jobs[job] << endl;
 
     struct mount_job_data *data = mount_jobs[job];
     QString& qerror = data->errorMessage;
@@ -1054,7 +1343,6 @@
         qerror = job->errorText();
     }
 
-    ResetProperties( medium->id().latin1() );
     mount_jobs.remove(job);
 
     /* Job completed. Notify the caller */
@@ -1063,6 +1351,25 @@
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
@@ -1075,11 +1382,13 @@
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
+#endif
                 return (*it)->mountPoint();
         }
     }
@@ -1099,7 +1408,7 @@
         data.completed = false;
         data.medium = medium;
 
-        kdDebug() << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
+        kdDebug(1219) << "triggering user mount " << medium->deviceNode() << " " << mountPoint << " " << medium->id() << endl;
         KIO::Job *job = KIO::mount( false, 0, medium->deviceNode(), mountPoint );
         connect(job, SIGNAL( result (KIO::Job *)),
                 SLOT( slotResult( KIO::Job *)));
@@ -1117,7 +1426,7 @@
 
     QStringList soptions;
 
-    kdDebug() << "mounting " << medium->id() << "..." << endl;
+    kdDebug(1219) << "mounting " << medium->id() << "..." << endl;
 
     QMap<QString,QString> valids = MediaManagerUtils::splitOptions(mountoptions(medium->id()));
     if (valids["flush"] == "true")
@@ -1125,15 +1434,19 @@
 
     if (valids["uid"] == "true")
     {
+#ifdef Q_OS_FREEBSD
+        soptions << QString("-u=%1").arg(getuid());
+#else
         soptions << QString("uid=%1").arg(getuid());
+#endif
     }
 
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
 
@@ -1149,7 +1462,19 @@
 
     if (valids.contains("shortname"))
     {
+#ifdef Q_OS_FREEBSD
+        QString option = valids["shortname"];
+        if (option == "win95")
+						soptions << QString("shortnames");
+        else if (option == "mixed")
+						soptions << QString("shortnames") << QString("longnames");
+        else if (option == "lower")
+						soptions << QString("nowin95");
+        else
+						soptions << QString("longnames");
+#else
         soptions << QString("shortname=%1").arg(valids["shortname"]);
+#endif
     }
 
     if (valids.contains("journaling"))
@@ -1163,6 +1488,41 @@
             soptions << QString("data=ordered");
     }
 
+#ifdef Q_OS_FREEBSD
+    if (valids.contains("filemask"))
+    {
+        soptions << QString("-m=%1").arg(valids["filemask"]);
+    }
+    if (valids.contains("dirmask"))
+    {
+        soptions << QString("-M=%1").arg(valids["dirmask"]);
+    }
+    if (valids.contains("charset"))
+    {
+        soptions << QString("-C=%1").arg(valids["charset"]);
+    }
+    if (valids.contains("locale"))
+    {
+        soptions << QString("-L=%1").arg(valids["locale"]);
+    }
+    if (valids.contains("doscodepage"))
+    {
+        soptions << QString("-D=%1").arg(valids["doscodepage"]);
+    }
+#endif
+    if (valids.contains("options"))
+    {
+        uint start = 0;
+        QString tmp = valids["options"];
+        while(start < tmp.length())
+        {
+        		int end = tmp.find(',', start);
+        		if (end == -1) end = tmp.length();
+        		soptions << tmp.mid( start, end - start );
+        		start = end + 1;
+        }
+    }
+
     const char **options = new const char*[soptions.size() + 1];
     uint noptions = 0;
     for (QStringList::ConstIterator it = soptions.begin(); it != soptions.end(); ++it, ++noptions)
@@ -1175,9 +1535,6 @@
         return qerror;
     }
 
-    medium->setHalMounted(true);
-    ResetProperties(medium->id().latin1());
-
     return QString();
 }
 
@@ -1238,7 +1595,7 @@
     const char *options[2];
 
     const char *udi = medium->id().latin1();
-    kdDebug() << "unmounting " << udi << "..." << endl;
+    kdDebug(1219) << "unmounting " << udi << "..." << endl;
 
     dbus_error_init(&error);
     DBusConnection *dbus_connection = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
@@ -1251,7 +1608,7 @@
     if (!(dmesg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
                                                 "org.freedesktop.Hal.Device.Volume",
                                                 "Unmount"))) {
-        kdDebug() << "unmount failed for " << udi << ": could not create dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not create dbus message\n";
         return i18n("Internal Error");
     }
 
@@ -1261,7 +1618,7 @@
     if (!dbus_message_append_args (dmesg, DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &options, 0,
                                    DBUS_TYPE_INVALID))
     {
-        kdDebug() << "unmount failed for " << udi << ": could not append args to dbus message\n";
+        kdDebug(1219) << "unmount failed for " << udi << ": could not append args to dbus message\n";
         dbus_message_unref (dmesg);
         return i18n("Internal Error");
     }
@@ -1271,7 +1628,7 @@
     {
         QString qerror, reason;
 
-        kdDebug() << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
+        kdDebug(1219) << "unmount failed for " << udi << ": " << error.name << " " << error.message << endl;
         qerror = "<qt>";
         qerror += "<p>" + i18n("Unfortunately, the device <b>%1</b> (%2) named <b>'%3'</b> and "
                        "currently mounted at <b>%4</b> could not be unmounted. ").arg(
@@ -1301,13 +1658,10 @@
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
