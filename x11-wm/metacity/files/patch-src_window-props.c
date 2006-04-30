--- src/window-props.c.orig	Wed Dec 14 09:27:03 2005
+++ src/window-props.c	Wed Dec 14 09:28:57 2005
@@ -20,6 +20,7 @@
  * 02111-1307, USA.
  */
 
+#include <sys/param.h>
 #include <config.h>
 #include "window-props.h"
 #include "xprops.h"
@@ -194,6 +195,7 @@ reload_net_wm_user_time (MetaWindow    *
 }
 
 #define MAX_TITLE_LENGTH 512
+#define HOST_NAME_MAX MAXHOSTNAMELEN
 
 /**
  * Called by set_window_title and set_icon_title to set the value of
