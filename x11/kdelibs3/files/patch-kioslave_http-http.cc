--- kioslave/http/http.cc	2007/09/26 17:08:43	717341
+++ kioslave/http/http.cc	2007/10/17 04:11:51	726097
@@ -3409,10 +3409,6 @@
 
   } while (!m_bEOF && (len || noHeader) && (headerSize < maxHeaderSize) && (gets(buffer, sizeof(buffer)-1)));
 
-  // Send the current response before processing starts or it
-  // might never get sent...
-  forwardHttpResponseHeader();
-
   // Now process the HTTP/1.1 upgrade
   QStringList::Iterator opt = upgradeOffers.begin();
   for( ; opt != upgradeOffers.end(); ++opt) {
@@ -3818,6 +3814,10 @@
     mimeType( m_strMimeType );
   }
 
+  // Do not move send response header before any redirection as it seems
+  // to screw up some sites. See BR# 150904.
+  forwardHttpResponseHeader();
+
   if (m_request.method == HTTP_HEAD)
      return true;
 
@@ -3830,10 +3830,10 @@
         // Check...
         createCacheEntry(m_strMimeType, expireDate); // Create a cache entry
         if (!m_request.fcache)
-	    {
-		m_request.bCachedWrite = false; // Error creating cache entry.
-		kdDebug(7113) << "(" << m_pid << ") Error creating cache entry for " << m_request.url.url()<<"!\n";
-	    }
+        {
+          m_request.bCachedWrite = false; // Error creating cache entry.
+          kdDebug(7113) << "(" << m_pid << ") Error creating cache entry for " << m_request.url.url()<<"!\n";
+        }
         m_request.expireDate = expireDate;
         m_maxCacheSize = config()->readNumEntry("MaxCacheSize", DEFAULT_MAX_CACHE_SIZE) / 2;
      }
