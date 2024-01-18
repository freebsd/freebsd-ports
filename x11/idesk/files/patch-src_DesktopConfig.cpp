--- src/DesktopConfig.cpp.orig	2005-11-10 23:07:58 UTC
+++ src/DesktopConfig.cpp
@@ -24,6 +24,7 @@
 
 #include "DesktopConfig.h"
 #include "Util.h"
+#include "sys/stat.h"
 
 //the initilizer list just sets the program defaults for non-necessary options
 DesktopConfig::DesktopConfig(Database db, string ideskrcFile) :
