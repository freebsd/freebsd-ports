Index: kio/kssl/kopenssl.h
===================================================================
RCS file: /home/kde/kdelibs/kio/kssl/kopenssl.h,v
retrieving revision 1.37.2.1
retrieving revision 1.37.2.2
diff -u -3 -p -r1.37.2.1 -r1.37.2.2
--- kio/kssl/kopenssl.h	2002/04/10 22:00:44	1.37.2.1
+++ kio/kssl/kopenssl.h	2002/08/12 16:45:14	1.37.2.2
@@ -309,6 +309,10 @@ public:
     */
    void X509_STORE_CTX_set_chain(X509_STORE_CTX *v, STACK_OF(X509)* x);
 
+   /*
+    *   X509_STORE_CTX_set_purpose - set the purpose of the certificate 
+    */
+   void X509_STORE_CTX_set_purpose(X509_STORE_CTX *v, int purpose);
 
    /*
     *   X509_verify_cert - verify the certificate
