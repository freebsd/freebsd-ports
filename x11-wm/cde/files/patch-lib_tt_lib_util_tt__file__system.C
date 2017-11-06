--- lib/tt/lib/util/tt_file_system.C	2016-06-19 20:46:29 UTC
+++ lib/tt/lib/util/tt_file_system.C
@@ -46,6 +46,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <errno.h>
 #if defined(linux)
 # include <sys/poll.h>
 #else
@@ -516,7 +517,11 @@ updateFileSystemEntries ()
         int             flags = MNT_NOWAIT;
         char            *s, *host, path[MNAMELEN] ;
  
-        numfs = getfsstat ( (struct statfs *)0, 0, 0 );
+        numfs = getfsstat ( (struct statfs *)0, 0, flags );
+        if(numfs == (-1)){
+            _tt_syslog(0,LOG_ERR,"getfsstat: %s",strerror(errno));
+            exit(EXIT_FAILURE);
+        }
 
         bufsize = numfs * sizeof ( struct statfs );
         buf = (struct statfs *) malloc ( bufsize );
