--- lib/i3ipcpp/src/ipc.cpp.orig	2023-11-12 19:08:48 UTC
+++ lib/i3ipcpp/src/ipc.cpp
@@ -1,6 +1,7 @@
 #include "i3ipc++/ipc.hpp"
 
 #include <json/json.h>
+#include <sys/wait.h>
 
 #include <auss.hpp>
 #include <cstdio>
