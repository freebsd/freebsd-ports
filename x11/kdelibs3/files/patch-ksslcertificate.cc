--- kio/kssl/ksslcertificate.cc.orig	Sat Dec  1 01:30:03 2001
+++ kio/kssl/ksslcertificate.cc	Mon Aug 12 22:28:40 2002
@@ -544,6 +544,7 @@
     //
 
     // int X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx, int purpose);
+    d->kossl->X509_STORE_CTX_set_purpose(certStoreCTX, X509_PURPOSE_SSL_SERVER);
 
     //kdDebug(7029) << "KSSL verifying.............." << endl;
     certStoreCTX->error = X509_V_OK;
