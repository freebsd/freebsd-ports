$FreeBSD$

--- src/pashut.c.orig	Thu Sep  4 22:29:02 2003
+++ src/pashut.c	Thu Mar 11 18:08:38 2004
@@ -20,6 +20,7 @@
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include <signal.h>
 #include "pashut.h"
 #include "pawindow.h"
 #include "pabar.h"
