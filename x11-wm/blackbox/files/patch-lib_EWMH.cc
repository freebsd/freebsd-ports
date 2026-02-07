# Fix error: non-constant-expression cannot be narrowed from type 'long' to
# 'unsigned long' in initializer list [-Wc++11-narrowing]
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226708

--- lib/EWMH.cc.orig	2018-08-09 04:45:57 UTC
+++ lib/EWMH.cc
@@ -247,7 +247,7 @@ bool bt::EWMH::readDesktopGeometry(Window target,
 
 void bt::EWMH::setDesktopViewport(Window target, int x, int y) const {
   const unsigned long viewport[] =
-    { static_cast<long>(x), static_cast<long>(y) };
+    { static_cast<unsigned long>(x), static_cast<unsigned long>(y) };
   setProperty(target, XA_CARDINAL, net_desktop_viewport,
               reinterpret_cast<const unsigned char *>(viewport), 2);
 }
