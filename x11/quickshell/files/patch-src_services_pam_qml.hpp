--- src/services/pam/qml.hpp.orig	2025-10-12 00:14:14 UTC
+++ src/services/pam/qml.hpp
@@ -6,7 +6,9 @@
 #include <qtclasshelpermacros.h>
 #include <qthread.h>
 #include <qtmetamacros.h>
+#if defined(__linux__)
 #include <security/_pam_types.h>
+#endif
 #include <security/pam_appl.h>
 
 #include "conversation.hpp"
