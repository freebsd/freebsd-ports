--- ksysguard/ksysguardd/FreeBSD/ksysguardd.c	2001/11/17 02:01:46	1.5
+++ ksysguard/ksysguardd/FreeBSD/ksysguardd.c	2001/11/17 06:16:15	1.6
@@ -17,9 +17,11 @@
     along with this program; if not, write to the Free Software
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
-	$Id: ksysguardd.c,v 1.2.6.1 2001/11/08 10:48:51 tokoe Exp $
+	$Id: ksysguardd.c,v 1.6 2001/11/17 06:16:15 waba Exp $
 */
 
+#include <config.h>
+
 #include <ctype.h>
 #include <fcntl.h>
 #include <netdb.h>
