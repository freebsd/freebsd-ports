--- kdecore/kextsock.cpp	11 Dec 2003 22:54:36 -0000	1.67
+++ kdecore/kextsock.cpp	22 Jan 2004 19:59:13 -0000
@@ -1892,7 +1892,11 @@ int KExtendedSocket::doLookup(const QStr
   err = kde_getaddrinfo(_host, _serv, &hint, res);
 
 #ifdef HAVE_RES_INIT
-  if (err == EAI_NONAME || err == EAI_NODATA || err == EAI_AGAIN)
+  if (err == EAI_NONAME || 
+#ifdef EAI_NODATA
+	err == EAI_NODATA || 
+#endif
+	err == EAI_AGAIN)
     {
       // A loookup error occurred and nothing was resolved
       // However, since the user could have just dialed up to the ISP
@@ -2274,7 +2278,11 @@ void KExtendedSocket::dnsResultsReady()
   else
     {
       d->status = nothing;
+#ifdef EAI_NODATA
       setError(IO_LookupError, EAI_NODATA);
+#else
+      setError(IO_LookupError, EAI_NONAME);
+#endif
     }
 
   emit lookupFinished(n);
