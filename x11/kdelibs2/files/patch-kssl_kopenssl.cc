$FreeBSD$

--- kssl/kopenssl.cc.orig	Tue Sep  4 16:08:18 2001
+++ kssl/kopenssl.cc	Mon Aug 19 12:27:36 2002
@@ -92,6 +92,7 @@ static int (*K_SSL_CTX_use_certificate) 
 static int (*K_SSL_get_error) (SSL*, int) = NULL;
 static STACK_OF(X509)* (*K_SSL_get_peer_cert_chain) (SSL*) = NULL;
 static void (*K_X509_STORE_CTX_set_chain) (X509_STORE_CTX *, STACK_OF(X509)*) = NULL;
+static void (*K_X509_STORE_CTX_set_purpose) (X509_STORE_CTX *, int) = NULL;
 static void (*K_sk_free) (STACK*) = NULL;
 static int (*K_sk_num) (STACK*) = NULL;
 static char* (*K_sk_value) (STACK*, int) = NULL;
@@ -254,6 +255,7 @@ KConfig *cfg;
                 X509**, STACK_OF(X509)**)) _cryptoLib->symbol("PKCS12_parse");
       K_EVP_PKEY_free = (void (*) (EVP_PKEY *)) _cryptoLib->symbol("EVP_PKEY_free");
       K_X509_STORE_CTX_set_chain = (void (*)(X509_STORE_CTX *, STACK_OF(X509)*)) _cryptoLib->symbol("X509_STORE_CTX_set_chain");
+      K_X509_STORE_CTX_set_purpose = (void (*)(X509_STORE_CTX *, int)) _cryptoLib->symbol("X509_STORE_CTX_set_purpose");
       K_sk_free = (void (*) (STACK *)) _cryptoLib->symbol("sk_free");
       K_sk_num = (int (*) (STACK *)) _cryptoLib->symbol("sk_num");
       K_sk_value = (char* (*) (STACK *, int)) _cryptoLib->symbol("sk_value");
@@ -742,6 +744,10 @@ char *KOpenSSLProxy::sk_value(STACK *s, 
 
 void KOpenSSLProxy::X509_STORE_CTX_set_chain(X509_STORE_CTX *v, STACK_OF(X509)* x) {
    if (K_X509_STORE_CTX_set_chain) (K_X509_STORE_CTX_set_chain)(v,x);
+}
+
+void KOpenSSLProxy::X509_STORE_CTX_set_purpose(X509_STORE_CTX *v, int purpose) {
+   if (K_X509_STORE_CTX_set_purpose) (K_X509_STORE_CTX_set_purpose)(v,purpose);
 }
 
 
