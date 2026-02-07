--- src/KeyClient.cpp.orig     Thu Jun  9 09:07:14 2005
+++ src/KeyClient.cpp  Thu Jun  9 09:10:24 2005
@@ -102,6 +102,11 @@
   _netclient = new Netclient(this->display());
   _active = _clients.end();
 
+  // Initialize uninitialized pointers to NULL
+  _keybindings = NULL;
+  config_check_timer = NULL;
+
+
   initialize();
 }
 
