--- kio/http/http.cc	2001/03/16 05:55:57	1.319.2.7
+++ kio/http/http.cc	2001/03/30 22:52:10	1.319.2.10
@@ -48,6 +48,7 @@
 
 #include <kapp.h>
 #include <klocale.h>
+#include <kcharsets.h>
 #include <kprotocolmanager.h>
 #include <kdatastream.h>
 #include <ksock.h>
@@ -804,6 +805,8 @@ bool HTTPProtocol::http_open()
 
   // Let's also clear out some things, so bogus values aren't used.
   // m_HTTPrev = HTTP_Unknown;
+  m_iWWWAuthCount = 0;
+  m_iProxyAuthCount = 0;
   m_sContentMD5 = QString::null;
   m_strMimeType = QString::null;
   m_qContentEncodings.clear();
@@ -1184,7 +1187,6 @@ bool HTTPProtocol::readHeader()
 
   // read in 4096 bytes at a time (HTTP cookies can be quite large.)
   int len = 0;
-  int proxyAuthCount = 1;
   char buffer[4097];
   bool cont = false;
   bool cacheValidated = false; // Revalidation was successfull
@@ -1495,9 +1497,6 @@ bool HTTPProtocol::readHeader()
 
     // check for proxy-based authentication
     else if (strncasecmp(buffer, "Proxy-Authenticate:", 19) == 0) {
-      if ( proxyAuthCount++ > 1 )
-        configAuth(trimLead(buffer + 19), true, false);
-      else
         configAuth(trimLead(buffer + 19), true);
     }
 
@@ -1867,9 +1866,9 @@ void HTTPProtocol::addEncoding(QString e
   }
 }
 
-void HTTPProtocol::configAuth( const char *p, bool b, bool firstCall )
+void HTTPProtocol::configAuth( const char *p, bool b )
 {
-  HTTP_AUTH f;
+  HTTP_AUTH f = AUTH_None;
   const char *strAuth = p;
 
   while( *p == ' ' ) p++;
@@ -1894,15 +1893,33 @@ void HTTPProtocol::configAuth( const cha
   {
     kdWarning(7103) << "Unsupported or invalid authorization type requested" << endl;
     kdWarning(7103) << "Request Authorization: " << p << endl;
-    if ( firstCall && b )
-      ProxyAuthentication = AUTH_None;
-    return;
   }
 
-  // Always prefer the stronger authentication mode:
-  // AUTH_NONE < AUTH_BASIC < AUTH_DIGEST...
-  if ( (b && f < ProxyAuthentication) || (!b && f < Authentication) )
+  /*
+     This check ensures the following:
+     1.) Rejection of any unknown/unsupported authentication schemes
+     2.) Useage of the strongest possible authentication schemes if
+         and when multiple Proxy-Authenticate or WWW-Authenticate
+         header field is sent.
+  */
+  if ( f == AUTH_None ||
+       (b && m_iProxyAuthCount > 0 && f < ProxyAuthentication) ||
+       (!b && m_iWWWAuthCount > 0 && f < Authentication) )
+  {
+    // Since I purposefully made the Proxy-Authentication settings
+    // persistent to reduce the number of round-trips to kdesud we
+    // have to take special care when an unknown/unsupported auth-
+    // scheme is received. This check accomplishes just that...
+    if ( b )
+    {
+      if ( !m_iProxyAuthCount )
+        ProxyAuthentication = f;
+      m_iProxyAuthCount++;
+    }
+    else
+      m_iWWWAuthCount++;
     return;
+  }
 
   while (*p)
   {
@@ -3235,7 +3252,9 @@ void HTTPProtocol::reparseConfiguration(
   // Use commas not spaces.
   m_strLanguages = languageList.join( ", " );
   kdDebug(7103) << "Languages list set to " << m_strLanguages << endl;
-  m_strCharsets = KGlobal::locale()->charset() + QString::fromLatin1(";q=1.0, *;q=0.9, utf-8;q=0.8");
+  // Ugly conversion. kdeglobals has the xName (e.g. iso8859-1 instead of iso-8859-1)
+  m_strCharsets = KGlobal::charsets()->name(KGlobal::charsets()->xNameToID(KGlobal::locale()->charset()));
+  m_strCharsets += QString::fromLatin1(";q=1.0, *;q=0.9, utf-8;q=0.8");
 
   // Launch the cookiejar if not already running
   KConfig *cookieConfig = new KConfig("kcookiejarrc", false, false);
