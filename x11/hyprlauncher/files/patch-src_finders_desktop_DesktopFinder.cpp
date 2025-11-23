--- src/finders/desktop/DesktopFinder.cpp.orig	2025-11-23 08:44:11 UTC
+++ src/finders/desktop/DesktopFinder.cpp
@@ -9,6 +9,7 @@
 #include <fstream>
 #include <sys/inotify.h>
 #include <sys/poll.h>
+#include <unistd.h>
 
 #include <hyprutils/string/String.hpp>
 #include <hyprutils/os/Process.hpp>
