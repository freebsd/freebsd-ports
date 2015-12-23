--- src/Toolbar.cc.orig	2015-05-11 11:54:54 UTC
+++ src/Toolbar.cc
@@ -44,7 +44,7 @@ long nextTimeout(int resolution)
 {
   timeval now;
   gettimeofday(&now, 0);
-  return (std::max(1000l, ((((resolution - (now.tv_sec % resolution)) * 1000l))
+  return (std::max(1000ll, ((((resolution - (now.tv_sec % resolution)) * 1000l))
                            - (now.tv_usec / 1000l))));
 }
 
