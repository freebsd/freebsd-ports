error: invalid suffix on literal; C++11 requires a space between literal and identifier 
[-Wreserved-user-defined-literal]
     fprintf(stderr, "kdeinit4: Aborting. $"DISPLAY" is not set.\n");

--- kinit/kinit.cpp.orig	2018-01-07 10:44:53 UTC
+++ kinit/kinit.cpp
@@ -1478,7 +1478,7 @@ static void kdeinit_library_path()
    if (display.isEmpty())
    {
 #if defined(Q_WS_X11) || defined(Q_WS_QWS)
-     fprintf(stderr, "kdeinit4: Aborting. $"DISPLAY" is not set.\n");
+     fprintf(stderr, "kdeinit4: Aborting. $" DISPLAY " is not set.\n");
      exit(255);
 #endif
    }
