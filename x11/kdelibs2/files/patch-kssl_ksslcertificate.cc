$FreeBSD$

--- kssl/ksslcertificate.cc.orig	Mon Nov  5 18:37:43 2001
+++ kssl/ksslcertificate.cc	Mon Aug 19 12:32:22 2002
@@ -259,6 +259,10 @@ KSSLCertificate::KSSLValidation KSSLCert
     if (d->_chain.isValid())
       d->kossl->X509_STORE_CTX_set_chain(certStoreCTX, (STACK_OF(X509)*)d->_chain.rawChain());
 
+ 
+     // int X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx, int purpose);
+     d->kossl->X509_STORE_CTX_set_purpose(certStoreCTX, X509_PURPOSE_SSL_SERVER);
+ 
     // FIXME: do all the X509_STORE_CTX_set_flags(); here
     //   +----->  Note that this is for 0.9.6 or better ONLY!
 
