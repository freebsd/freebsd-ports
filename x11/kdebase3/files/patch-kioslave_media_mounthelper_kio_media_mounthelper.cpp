--- kioslave/media/mounthelper/kio_media_mounthelper.cpp.orig	Fri Aug  5 14:26:27 2005
+++ kioslave/media/mounthelper/kio_media_mounthelper.cpp	Fri Aug  5 14:27:25 2005
@@ -79,7 +79,7 @@
 		connect( job, SIGNAL( result( KIO::Job * ) ),
 		         this, SLOT( slotResult( KIO::Job * ) ) );
 	}
-	else if (args->isSet("s"))
+	else if (args->isSet("s") || args->isSet("e"))
 	{
 		if (medium.isMounted())
 		{
@@ -93,10 +93,6 @@
 		{
 			invokeEject(device, true);
 		}
-	}
-	else if (args->isSet("e"))
-	{
-		invokeEject(device);
 	}
 	else
 	{
