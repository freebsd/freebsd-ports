--- src/tilda.c.orig	2014-10-28 11:26:57.000000000 +0000
+++ src/tilda.c	2015-04-09 12:05:56.977831590 +0000
@@ -12,6 +12,7 @@
  * You should have received a copy of the GNU Library General Public
  * License along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
+#include <fcntl.h>
 #define _POSIX_SOURCE /* feature test macro for signal functions */
 #define _XOPEN_SOURCE /* feature test macro for popen */
 
