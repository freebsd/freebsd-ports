--- src/tilda.c.orig	2015-12-16 12:11:58 UTC
+++ src/tilda.c
@@ -12,6 +12,7 @@
  * You should have received a copy of the GNU Library General Public
  * License along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
+#include <fcntl.h>
 #define _POSIX_SOURCE /* feature test macro for signal functions */
 #define _XOPEN_SOURCE /* feature test macro for popen */
 
