--- libxklavier/xklavier_config_xkb.c.orig	Sat Dec 10 00:04:07 2005
+++ libxklavier/xklavier_config_xkb.c	Sat Dec 10 00:04:41 2005
@@ -223,7 +223,7 @@ static XkbDescPtr _XklConfigGetKeyboard(
           exit( 1 );
         default:
           /* parent */
-          pid = wait( &status );
+          pid = waitpid( cpid, &status, 0 );
           XklDebug( 150, "Return status of %d (well, started %d): %d\n", pid, cpid, status );
           memset( (char *)&result, 0, sizeof(result) );
           result.xkb = XkbAllocKeyboard();
