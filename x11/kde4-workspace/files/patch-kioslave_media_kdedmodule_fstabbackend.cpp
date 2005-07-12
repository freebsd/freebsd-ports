--- kioslave/media/kdedmodule/fstabbackend.cpp
+++ kioslave/media/kdedmodule/fstabbackend.cpp
@@ -47,6 +47,12 @@
 	handleMtabChange();
 
 	KDirWatch::self()->startScan();
+
+#ifdef Q_OS_FREEBSD
+	connect( &m_mtabTimer, SIGNAL( timeout() ),
+	         this, SLOT( handleMtabChange() ) );
+	m_mtabTimer.start(250);
+#endif
 }
 
 FstabBackend::~FstabBackend()
@@ -86,7 +92,7 @@
 	  || mount->mountType() == "tmpfs"
 	  || mount->mountType() == "sysfs"
 	  || mount->mountType() == "usbfs"
-	  || mount->mountType() == "proc"
+	  || mount->mountType().contains( "proc" )
 	  || mount->mountType() == "unknown"
 	  || mount->mountType() == "none"
 	  || mount->mountedFrom() == "none"
@@ -136,7 +142,7 @@
 #if 0
 		else if ( !m_mtabIds.contains(id) )
 		{
-			QString name = generateName(dev);
+			QString name = generateName(dev, fs);
 
 			Medium *m = new Medium(id, name);
 
@@ -205,7 +211,7 @@
 
 		if ( !m_fstabIds.contains(id) )
 		{
-			QString name = generateName(dev);
+			QString name = generateName(dev, fs);
 
 			Medium *m = new Medium(id, name);
 
@@ -247,9 +253,18 @@
 	      +m.replace("/", "");
 }
 
-QString FstabBackend::generateName(const QString &devNode)
+QString FstabBackend::generateName(const QString &devNode, const QString &fsType)
 {
-	return KURL(devNode).fileName();
+	KURL url( devNode );
+
+	if ( url.isValid() )
+	{
+		return url.fileName();
+	}
+	else // surely something nfs or samba based
+	{
+		return fsType;
+	}
 }
 
 void FstabBackend::guess(const QString &devNode, const QString &mountPoint,
