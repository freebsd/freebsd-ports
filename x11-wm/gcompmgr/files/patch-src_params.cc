--- src/params.cc.orig	2019-07-01 08:27:28 UTC
+++ src/params.cc
@@ -22,6 +22,7 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include "params.h"
+#include <cstring>
 #define BUFSIZE 1000
 
 params::params()
