--- rsibreak/src/rsiglobals.cpp.orig	Fri Apr 21 21:35:42 2006
+++ rsibreak/src/rsiglobals.cpp	Fri Apr 21 21:36:17 2006
@@ -72,11 +72,11 @@ QString RSIGlobals::formatSeconds( const
     sString1 = i18n("One second","%n seconds", secs);
     sString2 = i18n("one second","%n seconds", secs);
 
-    if ( hours > 0 and mins >0 )
+    if ( hours > 0 && mins >0 )
         return(i18n("Arguments: hours, minutes "
                     "both as you defined earlier",
                     "%1 and %2").arg(hString, mString2) );
-    else if ( hours > 0 and mins == 0 )
+    else if ( hours > 0 && mins == 0 )
         return( hString );
 
     else if ( hours == 0 )
