$FreeBSD$

--- kssl/kopenssl.h.orig	Sat Jul 28 21:55:41 2001
+++ kssl/kopenssl.h	Mon Aug 19 12:27:23 2002
@@ -277,6 +277,10 @@ public:
     */
    void X509_STORE_CTX_set_chain(X509_STORE_CTX *v, STACK_OF(X509)* x);
 
+   /*
+    *   X509_STORE_CTX_set_purpose - set the purpose of the certificate 
+    */
+   void X509_STORE_CTX_set_purpose(X509_STORE_CTX *v, int purpose);
 
    /*
     *   X509_verify_cert - verify the certificate
