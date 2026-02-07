--- window-list.c.orig	2005-12-06 04:57:05.000000000 +0200
+++ window-list.c	2010-01-11 13:37:39.000000000 +0200
@@ -15,6 +15,12 @@
  *   along with this program; if not, write to the Free Software
  *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110 USA
  */
+#include <sys/param.h>
+#ifdef __FreeBSD__
+#define  LINKPATH "/proc/%d/file"
+#else
+#define  LINKPATH "/proc/%d/exe"
+#endif
 
 #define WNCK_I_KNOW_THIS_IS_UNSTABLE wankfactor
 
@@ -57,7 +63,7 @@
   if( pid < 0 || pid == getpid() ) // never list myself
     return FALSE;
 
-  path = g_strdup_printf( "/proc/%d/exe", pid );
+  path = g_strdup_printf( LINKPATH, pid );
   len = readlink( path, destination, sizeof destination );
   g_free( path );
 
