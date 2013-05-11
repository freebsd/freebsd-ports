commit 65d736dab592bced4410ccfa4699de89f78c96ca
Author: Grégory Oestreicher <greg@kamago.net>
Date:   Wed May 8 23:16:00 2013 +0200

    Don't show passwords contained in HTTP URLs in error messages
    BUG: 319428

diff --git a/kioslave/http/http.cpp b/kioslave/http/http.cpp
index 2d139a9..129fc7b 100644
--- ./kioslave/http/http.cpp
+++ ./kioslave/http/http.cpp
@@ -3056,7 +3056,7 @@ try_again:
             ; // Ignore error
         } else {
             if (!sendErrorPageNotification()) {
-                error(ERR_INTERNAL_SERVER, m_request.url.url());
+                error(ERR_INTERNAL_SERVER, m_request.url.prettyUrl());
                 return false;
             }
         }
@@ -3072,9 +3072,9 @@ try_again:
         // Tell that we will only get an error page here.
         if (!sendErrorPageNotification()) {
             if (m_request.responseCode == 403)
-                error(ERR_ACCESS_DENIED, m_request.url.url());
+                error(ERR_ACCESS_DENIED, m_request.url.prettyUrl());
             else
-                error(ERR_DOES_NOT_EXIST, m_request.url.url());
+                error(ERR_DOES_NOT_EXIST, m_request.url.prettyUrl());
             return false;
         }
     } else if (m_request.responseCode >= 301 && m_request.responseCode<= 303) {
