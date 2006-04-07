--- kioslave/http/http.cc.orig	Fri Apr  7 06:17:01 2006
+++ kioslave/http/http.cc	Fri Apr  7 06:18:00 2006
@@ -3590,6 +3590,16 @@
       error(ERR_ACCESS_DENIED, u.url());
       return false;
     }
+
+    // preserve #ref: (bug 124654)
+    // if we were at http://host/resource1#ref, we sent a GET for "/resource1"
+    // if we got redirected to http://host/resource2, then we have to re-add
+    // the fragment:
+    if (m_request.url.hasRef() && !u.hasRef() &&
+        (m_request.url.host() == u.host()) &&
+        (m_request.url.protocol() == u.protocol()))
+      u.setRef(m_request.url.ref());
+ 
     m_bRedirect = true;
     m_redirectLocation = u;
 
