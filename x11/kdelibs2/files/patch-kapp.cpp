--- kdecore/kapp.cpp.orig	Fri Dec 22 11:27:55 2000
+++ kdecore/kapp.cpp	Fri Dec 22 11:28:22 2000
@@ -776,6 +776,7 @@
     if ( mySmcConnection ) {
         // we already have a connection to the session manager, use it.
         SmcRequestSaveYourself( mySmcConnection, SmSaveBoth, True, SmInteractStyleAny, False, True );
+	SmcCloseConnection( mySmcConnection, 0, 0 );
         return TRUE;
     }
 
