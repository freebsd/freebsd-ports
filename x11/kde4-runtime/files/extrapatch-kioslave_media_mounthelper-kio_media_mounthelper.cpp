--- kioslave/media/mounthelper/kio_media_mounthelper.cpp.orig	Mon Jan 15 12:31:31 2007
+++ kioslave/media/mounthelper/kio_media_mounthelper.cpp	Wed Feb 21 15:17:23 2007
@@ -89,7 +89,9 @@
 	m_isCdrom = medium.mimeType().find("dvd")!=-1
 	         || medium.mimeType().find("cd")!=-1;
 
-	if (args->isSet("u"))
+	bool do_eject = args->isSet("s") || args->isSet("e");
+
+	if (args->isSet("u") || do_eject)
 	{
 	  DCOPRef mediamanager("kded", "mediamanager");
 	  DCOPReply reply = mediamanager.call( "unmount", medium.id());
@@ -97,30 +99,14 @@
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
-		/*
-		* We want to call mediamanager unmount before invoking eject. That's
-		* because unmount would provide an informative error message in case of
-		* failure. However, there are cases when unmount would fail
-		* (supermount, slackware, see bug#116209) but eject would succeed.
-		* Thus if unmount fails, save unmount error message and invokeEject()
-		* anyway. Only if both unmount and eject fail, notify the user by
-		* displaying the saved error message (see ejectFinished()).
-		*/
-		if (medium.isMounted())
-		{
-			DCOPRef mediamanager("kded", "mediamanager");
-			DCOPReply reply = mediamanager.call( "unmount", medium.id());
-			if (reply.isValid())
-			reply.get(m_errorStr);
-			m_device = device;
-		}
-		invokeEject(device, true);
 	}
 	else
 	{
