--- kioslave/sftp/kio_sftp.cpp.orig	2014-10-27 22:00:05.195340477 +0100
+++ kioslave/sftp/kio_sftp.cpp		2014-10-27 22:00:14.755340379 +0100
@@ -528,7 +528,7 @@
     return false;
   }
 
-  int timeout_sec = 30, timeout_usec = 0;
+  long int timeout_sec = 30, timeout_usec = 0;
 
   kDebug(KIO_SFTP_DB) << "Creating the SSH session and setting options";
 
