--- kcontrol/crypto/crypto.cpp.orig	2012-09-26 18:12:48.000000000 +0200
+++ kcontrol/crypto/crypto.cpp	2012-09-26 20:33:56.000000000 +0200
@@ -2321,7 +2321,11 @@
 unsigned int i;
 SSL_CTX *ctx;
 SSL *ssl;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+const SSL_METHOD *meth;
+#else
 SSL_METHOD *meth;
+#endif
 
   SSLv2Box->clear();
   SSLv3Box->clear();
@@ -2337,7 +2341,11 @@
   CipherItem *item;
   for (i=0; ; i++) {
     int j, k;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    const SSL_CIPHER *sc;
+#else
     SSL_CIPHER *sc;
+#endif
     sc = (meth->get_cipher)(i);
     if (!sc)
       break;
@@ -2365,7 +2373,11 @@
 
   for (i=0; ; i++) {
     int j, k;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    const SSL_CIPHER *sc;
+#else
     SSL_CIPHER *sc;
+#endif
     sc = (meth->get_cipher)(i);
     if (!sc)
       break;
