$FreeBSD$

--- src/paclock.c.orig	Fri Jan 16 13:22:09 2004
+++ src/paclock.c	Thu Mar 11 18:00:10 2004
@@ -20,6 +20,7 @@
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include <signal.h>
 #include "pabar.h"
 #include "paclock.h"
 #include "timux.h"
