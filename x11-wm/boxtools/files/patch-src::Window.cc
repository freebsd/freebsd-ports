--- src/Window.cc.orig Wed Aug 13 12:40:02 2003 
+++ src/Window.cc      Wed Aug 13 12:41:03 2003
@@ -44,6 +44,8 @@
 #endif // HAVE_STDLIB_H
 }
+#include <cassert>
+
 #include "i18n.hh"
 #include "blackbox.hh"
 #include "GCCache.hh"
