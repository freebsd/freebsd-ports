--- kdecore/kapp.cpp	Sun Feb 18 10:26:53 2001
+++ kdecore/kapp.cpp.new	Thu Feb 22 23:58:03 2001
@@ -795,6 +795,7 @@
         // we already have a connection to the session manager, use it.
         SmcRequestSaveYourself( mySmcConnection, SmSaveBoth, True,
 				SmInteractStyleAny, False, True );
+	SmcCloseConnection( mySmcConnection, 0, 0 );
 
 	// flush the request
 	IceFlush(SmcGetIceConnection(mySmcConnection));
