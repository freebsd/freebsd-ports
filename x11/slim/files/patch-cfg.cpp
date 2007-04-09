--- cfg.cpp.orig	Sat Sep 16 05:00:37 2006
+++ cfg.cpp	Mon Apr  9 19:52:17 2007
@@ -211,8 +211,7 @@
     int n = -1;
     n = position.find("%");
     if (n>0) { // X Position expressed in percentage
-        const char* tmp =  position.substr(0, n).c_str();
-        int result = (max*string2int(tmp)/100) - (width / 2);
+        int result = (max*string2int(position.substr(0, n).c_str())/100) - (width / 2);
         return result < 0 ? 0 : result ;
     } else { // Absolute X position
         return string2int(position.c_str());
