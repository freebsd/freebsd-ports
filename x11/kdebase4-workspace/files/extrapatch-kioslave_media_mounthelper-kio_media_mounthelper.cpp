--- kioslave/media/mounthelper/kio_media_mounthelper.cpp.orig	Sat Jan 27 01:58:24 2007
+++ kioslave/media/mounthelper/kio_media_mounthelper.cpp	Sat Jan 27 02:35:28 2007
@@ -77,7 +77,9 @@
 	m_isCdrom = medium.mimeType().find("dvd")!=-1
 	         || medium.mimeType().find("cd")!=-1;
 
-	if (args->isSet("u"))
+	bool do_eject = args->isSet("s") || args->isSet("e");
+
+	if (args->isSet("u") || do_eject)
 	{
 	  DCOPRef mediamanager("kded", "mediamanager");
 	  DCOPReply reply = mediamanager.call( "unmount", medium.id());
@@ -85,13 +87,14 @@
 	    reply.get(m_errorStr);
 	  kdDebug() << "medium unmount " << m_errorStr << endl;
 	  if (m_errorStr.isNull())
+	  {
+	    if( do_eject )
+	      invokeEject(device, true);
+	    else
 	    ::exit(0);
+	  }
 	  else
 	    error();
-	}
-	else if (args->isSet("s") || args->isSet("e"))
-	{
-		invokeEject(device, true);
 	}
 	else
 	{
