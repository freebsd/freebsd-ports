--- src/Window.cc.orig	Tue Aug 27 01:28:07 2002
+++ src/Window.cc	Mon May 31 13:34:45 2004
@@ -44,6 +44,7 @@
 #endif // HAVE_STDLIB_H
 }
 
+#include <cassert>
 #include "i18n.hh"
 #include "blackbox.hh"
 #include "GCCache.hh"
