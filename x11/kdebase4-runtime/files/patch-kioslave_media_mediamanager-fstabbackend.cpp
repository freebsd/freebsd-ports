--- kioslave/media/mediamanager/fstabbackend.cpp.orig	Fri Feb  9 04:11:01 2007
+++ kioslave/media/mediamanager/fstabbackend.cpp	Fri Feb  9 04:11:10 2007
@@ -154,7 +154,6 @@
 	  || ( networkSharesOnly
 	    && mount->mountType().find( "smb" ) == -1
 	    && mount->mountType().find( "cifs" ) == -1
-	    && mount->mountType().find( "nfs" ) == -1
 	     )
 	   )
 	{
