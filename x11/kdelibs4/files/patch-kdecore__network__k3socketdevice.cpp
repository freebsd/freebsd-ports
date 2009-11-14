--- kdecore/network/k3socketdevice.cpp.orig	2009-03-27 10:47:33.000000000 -0400
+++ kdecore/network/k3socketdevice.cpp	2009-09-26 16:51:55.000000000 -0400
@@ -352,9 +352,13 @@
   if (kde_connect(m_sockfd, address.address(), address.length()) == -1)
     {
       if (errno == EISCONN)
-	return true;		// we're already connected
+       {
+         KActiveSocketBase::open(Unbuffered | mode);
+         return true;          // we're already connected
+       }
       else if (errno == EALREADY || errno == EINPROGRESS)
 	{
+	  KActiveSocketBase::open(Unbuffered | mode);
 	  setError(InProgress);
 	  return true;
 	}
