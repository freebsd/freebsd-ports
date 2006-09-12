--- kioslave/media/mediamanager/fstabbackend.cpp.orig	Mon May 22 20:12:42 2006
+++ kioslave/media/mediamanager/fstabbackend.cpp	Fri Jun 16 08:56:20 2006
@@ -111,6 +111,7 @@
 	if ( mount->mountType() == "swap"
 	  || mount->mountType() == "tmpfs"
 	  || mount->mountType() == "sysfs"
+	  || mount->mountType() == "fdescfs"
 	  || mount->mountType() == "kernfs"
 	  || mount->mountType() == "usbfs"
 	  || mount->mountType().contains( "proc" )
