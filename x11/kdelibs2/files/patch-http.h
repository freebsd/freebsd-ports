--- kio/http/http.h	2001/02/26 03:57:23	1.83.2.1
+++ kio/http/http.h	2001/03/29 23:43:13	1.83.2.2
@@ -1,4 +1,4 @@
-// $Id: http.h,v 1.83.2.1 2001/02/26 03:57:23 waba Exp $
+// $Id: http.h,v 1.83.2.2 2001/03/29 23:43:13 adawit Exp $
 
 #ifndef __http_h__
 #define __http_h__
@@ -178,7 +178,7 @@ protected:
     */
   void addEncoding(QString, QStringList &);
 
-  void configAuth(const char *, bool, bool firstCall = true );
+  void configAuth(const char *, bool);
 #ifdef DO_SSL
   void initSSL();
   void closeSSL();
@@ -362,6 +362,8 @@ protected:
   HTTP_AUTH Authentication;
   HTTP_AUTH ProxyAuthentication;
   bool m_bUnauthorized;
+  short unsigned int m_iProxyAuthCount;
+  short unsigned int m_iWWWAuthCount;
 
   // Persistant connections
   bool m_bKeepAlive;
