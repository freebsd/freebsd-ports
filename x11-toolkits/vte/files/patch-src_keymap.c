--- src/keymap.c.orig	Tue Oct 22 17:42:20 2002
+++ src/keymap.c	Tue Oct 22 17:42:33 2002
@@ -18,6 +18,7 @@
 
 #ident "$Id: keymap.c,v 1.5 2002/10/18 20:53:53 nalin Exp $"
 #include "../config.h"
+#include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
 #include <glib.h>
