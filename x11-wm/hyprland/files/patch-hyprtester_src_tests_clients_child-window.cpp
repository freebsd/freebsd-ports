--- hyprtester/src/tests/clients/child-window.cpp.orig	2026-01-04 11:41:28 UTC
+++ hyprtester/src/tests/clients/child-window.cpp
@@ -7,6 +7,7 @@
 #include <hyprutils/os/FileDescriptor.hpp>
 #include <hyprutils/os/Process.hpp>
 
+#include <unistd.h>
 #include <sys/poll.h>
 #include <csignal>
 #include <thread>
@@ -120,4 +121,4 @@ static bool test() {
     return !ret;
 }
 
-REGISTER_CLIENT_TEST_FN(test);
\ No newline at end of file
+REGISTER_CLIENT_TEST_FN(test);
