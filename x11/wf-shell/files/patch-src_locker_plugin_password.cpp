--- src/locker/plugin/password.cpp.orig	2026-08-02 19:12:39 UTC
+++ src/locker/plugin/password.cpp
@@ -5,7 +5,11 @@
 #include "gtkmm/enums.h"
 #include "gtkmm/label.h"
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <security/pam_types.h>
+#else
 #include <security/_pam_types.h>
+#endif
 #include <security/pam_appl.h>
 
 #include "locker.hpp"
