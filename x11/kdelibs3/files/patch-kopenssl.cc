Index: kio/kssl/kopenssl.cc
===================================================================
RCS file: /home/kde/kdelibs/kio/kssl/kopenssl.cc,v
retrieving revision 1.58.2.1
retrieving revision 1.58.2.2
diff -u -3 -p -r1.58.2.1 -r1.58.2.2
--- kio/kssl/kopenssl.cc	2002/04/10 22:00:44	1.58.2.1
+++ kio/kssl/kopenssl.cc	2002/08/12 16:45:14	1.58.2.2
@@ -105,6 +105,7 @@ static int (*K_SSL_CTX_use_certificate) 
 static int (*K_SSL_get_error) (SSL*, int) = NULL;
 static STACK_OF(X509)* (*K_SSL_get_peer_cert_chain) (SSL*) = NULL;
 static void (*K_X509_STORE_CTX_set_chain) (X509_STORE_CTX *, STACK_OF(X509)*) = NULL;
+static void (*K_X509_STORE_CTX_set_purpose) (X509_STORE_CTX *, int) = NULL;
 static void (*K_sk_free) (STACK*) = NULL;
 static int (*K_sk_num) (STACK*) = NULL;
 static char* (*K_sk_pop) (STACK*) = NULL;
@@ -348,6 +349,7 @@ KConfig *cfg;
       K_X509_REQ_free = (void (*)(X509_REQ*)) _cryptoLib->symbol("X509_REQ_free");
       K_X509_REQ_new = (X509_REQ* (*)()) _cryptoLib->symbol("X509_REQ_new");
       K_X509_STORE_CTX_set_chain = (void (*)(X509_STORE_CTX *, STACK_OF(X509)*)) _cryptoLib->symbol("X509_STORE_CTX_set_chain");
+      K_X509_STORE_CTX_set_purpose = (void (*)(X509_STORE_CTX *, int)) _cryptoLib->symbol("X509_STORE_CTX_set_purpose");
       K_sk_free = (void (*) (STACK *)) _cryptoLib->symbol("sk_free");
       K_sk_num = (int (*) (STACK *)) _cryptoLib->symbol("sk_num");
       K_sk_pop = (char* (*) (STACK *)) _cryptoLib->symbol("sk_pop");
@@ -930,6 +932,10 @@ char *KOpenSSLProxy::sk_value(STACK *s, 
 
 void KOpenSSLProxy::X509_STORE_CTX_set_chain(X509_STORE_CTX *v, STACK_OF(X509)* x) {
    if (K_X509_STORE_CTX_set_chain) (K_X509_STORE_CTX_set_chain)(v,x);
+}
+
+void KOpenSSLProxy::X509_STORE_CTX_set_purpose(X509_STORE_CTX *v, int purpose) {
+   if (K_X509_STORE_CTX_set_purpose) (K_X509_STORE_CTX_set_purpose)(v,purpose);
 }
 
 
