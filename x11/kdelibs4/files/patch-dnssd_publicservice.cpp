--- dnssd/publicservice.cpp.orig	Sat Mar 19 09:36:15 2005
+++ dnssd/publicservice.cpp	Sat Mar 19 09:41:46 2005
@@ -18,7 +18,12 @@
  * Boston, MA 02111-1307, USA.
  */
 
+#include "config.h"
+
 #include "publicservice.h"
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #include <netinet/in.h>
 #include <qapplication.h>
 #include "sdevent.h"
