--- kioslave/http/http.cc.orig	Sun Mar  2 20:02:28 2003
+++ kioslave/http/http.cc	Thu Mar 20 22:05:14 2003
@@ -438,7 +438,6 @@
           kdDebug(7113) << "(" << m_pid << ") Unset tunneling flag!" << endl;
           setEnableSSLTunnel( false );
           m_bIsTunneled = true;
-          m_bNeedTunnel = false;
           // Reset the CONNECT response code...
           m_responseCode = m_prevResponseCode;
           continue;
@@ -1936,7 +1935,42 @@
   // Check the validity of the current connection, if one exists.
   httpCheckConnection();  
 
-  // Determine if this is a POST or GET method
+
+  if ( !m_bIsTunneled && m_bNeedTunnel )
+  {
+    setEnableSSLTunnel( true );
+    // We send a HTTP 1.0 header since some proxies refuse HTTP 1.1 and we don't
+    // need any HTTP 1.1 capabilities for CONNECT - Waba
+    header = QString("CONNECT %1:%2 HTTP/1.0"
+                     "\r\n").arg( m_request.hostname).arg(m_request.port);
+
+    // Identify who you are to the proxy server!
+    if (!m_request.userAgent.isEmpty())
+        header += "User-Agent: " + m_request.userAgent + "\r\n";
+
+    /* Add hostname information */
+    header += "Host: ";
+    if (m_state.hostname.find(':') != -1)
+    {
+      // This is an IPv6 (not hostname)
+      header += '[';
+      header += m_state.hostname;
+      header += ']';
+    }
+    else
+    {
+      header += m_state.hostname;
+    }
+
+    if (m_state.port != m_iDefaultPort)
+      header += QString(":%1").arg(m_state.port);
+    header += "\r\n";
+
+    header += proxyAuthenticationHeader();
+  }
+  else
+  {
+    // Determine the kind of method we are handling...
   switch (m_request.method)
   {
   case HTTP_GET:
@@ -1944,12 +1978,12 @@
       break;
   case HTTP_PUT:
       header = "PUT ";
-      moreData = !m_bNeedTunnel;
+        moreData = true;
       m_request.bCachedWrite = false; // Do not put any result in the cache
       break;
   case HTTP_POST:
       header = "POST ";
-      moreData = !m_bNeedTunnel;
+        moreData = true;
       m_request.bCachedWrite = false; // Do not put any result in the cache
       break;
   case HTTP_HEAD:
@@ -2033,40 +2067,6 @@
       return false;
   }
 
-  if ( !m_bIsTunneled && m_bNeedTunnel )
-  {
-    setEnableSSLTunnel( true );
-    // We send a HTTP 1.0 header since some proxies refuse HTTP 1.1 and we don't
-    // need any HTTP 1.1 capabilities for CONNECT - Waba
-    header = QString("CONNECT %1:%2 HTTP/1.0"
-                     "\r\n").arg( m_request.hostname).arg(m_request.port);
-
-    // Identify who you are to the proxy server!
-    if (!m_request.userAgent.isEmpty())
-        header += "User-Agent: " + m_request.userAgent + "\r\n";
-
-    /* Add hostname information */
-    header += "Host: ";
-    if (m_state.hostname.find(':') != -1)
-    {
-      // This is an IPv6 (not hostname)
-      header += '[';
-      header += m_state.hostname;
-      header += ']';
-    }
-    else
-    {
-      header += m_state.hostname;
-    }
-
-    if (m_state.port != m_iDefaultPort)
-      header += QString(":%1").arg(m_state.port);
-    header += "\r\n";
-
-    header += proxyAuthenticationHeader();
-  }
-  else
-  {
     // format the URI
     if (m_state.doProxy && !m_bIsTunneled)
     {
@@ -2271,7 +2271,6 @@
     // Do we need to authorize to the proxy server ?
     if ( m_state.doProxy && !m_bIsTunneled )
       header += proxyAuthenticationHeader();
-  }
 
   if ( m_protocol == "webdav" || m_protocol == "webdavs" )
   {
@@ -2289,6 +2288,7 @@
     // add extra header elements for WebDAV
     if ( !davHeader.isNull() )
       header += davHeader;
+    }
   }
 
   kdDebug(7103) << "(" << m_pid << ") ============ Sending Header:" << endl;
