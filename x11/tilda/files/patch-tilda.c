--- src/tilda.c.orig	2017-09-08 22:19:35.318278000 +0300
+++ src/tilda.c	2017-09-08 22:21:22.752550000 +0300
@@ -12,6 +12,7 @@
  * You should have received a copy of the GNU Library General Public
  * License along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
+#include <fcntl.h>
 #define _POSIX_SOURCE /* feature test macro for signal functions */
 #define _XOPEN_SOURCE /* feature test macro for popen */
 
@@ -230,7 +231,7 @@
 static GSList *getPids() {
     GSList *pids = NULL;
     FILE *ps_output;
-    const gchar ps_command[] = "ps -C tilda -o pid=";
+    const gchar ps_command[] = "pgrep tilda";
     gchar buf[16]; /* Really shouldn't need more than 6 */
 
     if ((ps_output = popen (ps_command, "r")) == NULL) {
