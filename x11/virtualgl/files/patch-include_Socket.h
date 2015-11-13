--- include/Socket.h.orig	2014-07-17 11:36:01 UTC
+++ include/Socket.h
@@ -138,7 +138,7 @@ namespace vglutil
 	{
 		public:
 
-			Socket(bool doSSL);
+			Socket(bool doSSL=false);
 			#ifdef USESSL
 			Socket(SOCKET sd, SSL *ssl);
 			#else
