--- lib/globalshortcut/src/hotkeymanager.cpp.orig	2018-12-31 18:07:36 UTC
+++ lib/globalshortcut/src/hotkeymanager.cpp
@@ -1,7 +1,7 @@
 // Copyright (C) 2014-2018 Manuel Schneider
 
 #include "globalshortcut/hotkeymanager.h"
-#if defined __linux__
+#if defined __linux__ || defined(__FreeBSD__)
 #include "hotkeymanager_x11.h"
 #elif defined __APPLE__
 #elif defined _WIN32
