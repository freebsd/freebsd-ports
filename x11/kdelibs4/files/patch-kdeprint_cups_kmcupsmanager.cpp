--- kdeprint/cups/kmcupsmanager.cpp.orig	Wed Jan 26 11:58:07 2005
+++ kdeprint/cups/kmcupsmanager.cpp	Wed Jan 26 12:09:45 2005
@@ -100,10 +100,10 @@
 {
 	QString	d = cupsInstallDir();
 	if (d.isEmpty())
-		d = "/usr";
+		d = "%%LOCALBASE%%";
 	d.append("/share/cups/model");
 	// raw foomatic support
-	d.append(":/usr/share/foomatic/db/source");
+	d.append(":%%LOCALBASE%%/share/foomatic/db/source");
 	return d;
 }
 
@@ -553,7 +553,7 @@
 {
 	QStringList	comps = QStringList::split('/', drname, false);
 	QString	tmpFile = locateLocal("tmp", "foomatic_" + kapp->randomString(8));
-	QString	PATH = getenv("PATH") + QString::fromLatin1(":/usr/sbin:/usr/local/sbin:/opt/sbin:/opt/local/sbin");
+	QString	PATH = getenv("PATH") + QString::fromLatin1(":%%LOCALBASE%%/bin:/usr/sbin:/usr/local/sbin:/opt/sbin:/opt/local/sbin");
 	QString	exe = KStandardDirs::findExe("foomatic-datafile", PATH);
 	if (exe.isEmpty())
 	{
@@ -844,7 +844,7 @@
 	{
 		QString	path = cupsInstallDir();
 		if (path.isEmpty())
-			path = "/usr/share/cups";
+			path = "%%LOCALBASE%%/share/cups";
 		else
 			path += "/share/cups";
 		CupsAddSmb::exportDest(m_currentprinter->printerName(), path);
