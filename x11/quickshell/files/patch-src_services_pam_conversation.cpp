--- src/services/pam/conversation.cpp.orig	2026-01-12 13:51:40 UTC
+++ src/services/pam/conversation.cpp
@@ -7,6 +7,7 @@
 #include <qstring.h>
 #include <qtmetamacros.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include "../../core/logcat.hpp"
 #include "ipc.hpp"
