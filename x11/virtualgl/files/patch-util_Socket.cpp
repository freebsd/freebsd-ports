--- util/Socket.cpp.orig	2014-07-17 11:36:01 UTC
+++ util/Socket.cpp
@@ -125,7 +125,7 @@ static X509 *newCert(EVP_PKEY *priv)
 #endif // USESSL
 
 
-Socket::Socket(bool doSSL_=false)
+Socket::Socket(bool doSSL_)
 	#ifdef USESSL
 	: doSSL(doSSL_)
 	#endif
