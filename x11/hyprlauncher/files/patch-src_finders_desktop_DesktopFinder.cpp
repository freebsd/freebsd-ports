--- src/finders/desktop/DesktopFinder.cpp.orig	2025-12-27 13:54:55 UTC
+++ src/finders/desktop/DesktopFinder.cpp
@@ -9,6 +9,7 @@
 #include <fstream>
 #include <sys/inotify.h>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <unordered_set>
 
 #include <hyprutils/string/String.hpp>
