--- regex_feature.c.orig	Tue May 14 16:03:27 2002
+++ regex_feature.c	Tue May 14 16:03:58 2002
@@ -13,6 +13,7 @@
    GNU General Public License for more details.
 */
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <regex.h>
