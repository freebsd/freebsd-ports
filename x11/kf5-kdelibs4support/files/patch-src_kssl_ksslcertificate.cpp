--- src/kssl/ksslcertificate.cpp.orig	2022-10-19 06:09:59 UTC
+++ src/kssl/ksslcertificate.cpp
@@ -1222,7 +1222,7 @@ QByteArray KSSLCertificate::toNetscape()
 {
     QByteArray qba;
      // no equivalent in OpenSSL 1.1.0 (?), so behave as if we had no OpenSSL at all
-#if KSSL_HAVE_SSL && (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
+#if KSSL_HAVE_SSL && OPENSSL_VERSION_NUMBER < 0x10100000L
     NETSCAPE_X509 nx;
     ASN1_OCTET_STRING hdr;
     QTemporaryFile ktf;
