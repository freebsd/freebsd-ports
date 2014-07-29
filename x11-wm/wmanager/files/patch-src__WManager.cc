diff -urN -urN -x .svn ../vendor/wmanager/src/WManager.cc ./src/WManager.cc
--- ../vendor/wmanager/src/WManager.cc	2007-12-11 12:42:04.000000000 +0200
+++ ./src/WManager.cc	2007-12-17 16:09:16.000000000 +0200
@@ -24,8 +24,12 @@
 // SYSTEM INCLUDES /////////////////////////////////
 #include <string>                                 // standard string class
 #include <fstream>                                // file streams
+#include <cstdlib>                                // 'exit'
 #include <cstring>                                // only for 'strtok'
+#include <iostream>
 #include <pwd.h>                                  // for home directory
+#include <unistd.h>
+#include <sys/types.h>
 
 
 // PROJECT INCLUDES ////////////////////////////////
@@ -36,6 +40,7 @@
 // LOCAL INCLUDES //////////////////////////////////
 #include <FL/fl_message.H>                        // message window
 
+using namespace std;
 
 // constructor
 WManager::WManager()
@@ -302,7 +307,7 @@
     } else {
       fl_alert("Error near %s while parsing configuration file %s!"
 	       "Try to read on...",
-	       name->c_str(), _ConfigurationFilename);
+	       name->c_str(), _ConfigurationFilename->c_str());
     } // end if
   } // end if
 }
@@ -310,7 +315,7 @@
 
 // cut rest from the beginning of str
 char*
-WManager::_CutString(char* str, char* rest)
+WManager::_CutString(const char* str, const char* rest)
 {
   int   i          = 0;
   int   n          = 0;
