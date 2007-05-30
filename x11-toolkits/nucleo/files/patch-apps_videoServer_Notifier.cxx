--- apps/videoServer/Notifier.cxx.orig	Thu May 24 15:48:08 2007
+++ apps/videoServer/Notifier.cxx	Thu May 24 15:48:17 2007
@@ -19,6 +19,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include <iostream>
 #include <stdexcept>
