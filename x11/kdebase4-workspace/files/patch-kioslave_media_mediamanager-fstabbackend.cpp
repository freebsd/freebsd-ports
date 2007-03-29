--- kioslave/media/mediamanager/fstabbackend.cpp.orig	Sun Oct  1 19:31:54 2006
+++ kioslave/media/mediamanager/fstabbackend.cpp	Thu Mar 29 02:19:18 2007
@@ -152,9 +152,7 @@
 	  // We might want to display only network shares
 	  // since HAL doesn't handle them
 	  || ( networkSharesOnly
-	    && mount->mountType().find( "smb" ) == -1
 	    && mount->mountType().find( "cifs" ) == -1
-	    && mount->mountType().find( "nfs" ) == -1
 	     )
 	   )
 	{
