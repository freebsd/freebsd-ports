--- src/kssl/kopenssl.cpp.orig	2022-10-19 06:07:48 UTC
+++ src/kssl/kopenssl.cpp
@@ -978,7 +978,7 @@ void KOpenSSLProxy::X509_STORE_free(X509_STORE *v)
 
 void KOpenSSLProxy::X509_STORE_set_verify_cb(X509_STORE *store, int (*verify_cb)(int, X509_STORE_CTX *))
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     X509_STORE_set_verify_cb_func(store, verify_cb);
 #else
     if (K_X509_STORE_set_verify_cb) {
@@ -1043,7 +1043,7 @@ X509_NAME *KOpenSSLProxy::X509_get_issuer_name(X509 *a
 
 void KOpenSSLProxy::X509_get0_signature(const ASN1_BIT_STRING **psig, const X509_ALGOR **algor, const X509 *x)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     if (psig) {
         *psig = x->signature;
     }
@@ -1121,7 +1121,7 @@ X509 *KOpenSSLProxy::X509_dup(X509 *x509)
 
 ASN1_TIME *KOpenSSLProxy::X509_getm_notBefore(const X509 *x)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return X509_get_notBefore(x);
 #else
     if (K_X509_getm_notBefore) {
@@ -1134,7 +1134,7 @@ ASN1_TIME *KOpenSSLProxy::X509_getm_notBefore(const X5
 
 ASN1_TIME *KOpenSSLProxy::X509_getm_notAfter(const X509 *x)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return X509_get_notAfter(x);
 #else
     if (K_X509_getm_notAfter) {
@@ -1412,7 +1412,7 @@ void KOpenSSLProxy::X509_STORE_CTX_set_purpose(X509_ST
 
 X509 *KOpenSSLProxy::X509_STORE_CTX_get_current_cert(X509_STORE_CTX *v)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return v->current_cert;
 #else
     if (K_X509_STORE_CTX_get_current_cert) {
@@ -1425,7 +1425,7 @@ X509 *KOpenSSLProxy::X509_STORE_CTX_get_current_cert(X
 
 void KOpenSSLProxy::X509_STORE_CTX_set_error(X509_STORE_CTX *v, int error)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     v->error = error;
 #else
     if (K_X509_STORE_CTX_set_error) {
@@ -1436,7 +1436,7 @@ void KOpenSSLProxy::X509_STORE_CTX_set_error(X509_STOR
 
 int KOpenSSLProxy::X509_STORE_CTX_get_error(X509_STORE_CTX *v)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return v->error;
 #else
     if (K_X509_STORE_CTX_get_error) {
@@ -1893,7 +1893,7 @@ int KOpenSSLProxy::EVP_PKEY_assign(EVP_PKEY *pkey, int
 
 int KOpenSSLProxy::EVP_PKEY_base_id(EVP_PKEY *pkey)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return pkey->type;
 #else
     if (K_EVP_PKEY_base_id) {
@@ -1906,7 +1906,7 @@ int KOpenSSLProxy::EVP_PKEY_base_id(EVP_PKEY *pkey)
 
 RSA *KOpenSSLProxy::EVP_PKEY_get0_RSA(EVP_PKEY *pkey)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return pkey->pkey.rsa;
 #else
     if (K_EVP_PKEY_get0_RSA) {
@@ -1919,7 +1919,7 @@ RSA *KOpenSSLProxy::EVP_PKEY_get0_RSA(EVP_PKEY *pkey)
 
 void KOpenSSLProxy::RSA_get0_key(RSA *rsa, const BIGNUM **n, const BIGNUM **e, const BIGNUM **d)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     if (n) {
         *n = rsa->n;
     }
@@ -1938,7 +1938,7 @@ void KOpenSSLProxy::RSA_get0_key(RSA *rsa, const BIGNU
 
 DSA *KOpenSSLProxy::EVP_PKEY_get0_DSA(EVP_PKEY *pkey)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return pkey->pkey.dsa;
 #else
     if (K_EVP_PKEY_get0_DSA) {
@@ -1951,7 +1951,7 @@ DSA *KOpenSSLProxy::EVP_PKEY_get0_DSA(EVP_PKEY *pkey)
 
 void KOpenSSLProxy::DSA_get0_pqg(DSA *dsa, const BIGNUM **p, const BIGNUM **q, const BIGNUM **g)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     if (p) {
         *p = dsa->p;
     }
@@ -1970,7 +1970,7 @@ void KOpenSSLProxy::DSA_get0_pqg(DSA *dsa, const BIGNU
 
 void KOpenSSLProxy::DSA_get0_key(DSA *dsa, const BIGNUM **pub_key, const BIGNUM **priv_key)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     if (pub_key) {
         *pub_key = dsa->pub_key;
     }
