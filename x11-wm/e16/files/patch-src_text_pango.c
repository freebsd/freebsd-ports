--- src/text_pango.c.orig	2010-03-01 10:10:12.000000000 +0100
+++ src/text_pango.c	2010-03-01 10:10:23.000000000 +0100
@@ -21,12 +21,11 @@
  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 #include "E.h"
-#include "tclass.h"
 
 #ifdef USE_PANGO
-#include "xwin.h"
 #include <X11/Xft/Xft.h>
 #include <pango/pangoxft.h>
+#include "tclass.h"
 
 /*
  * Pango-Xft
