--- src/keymap.c.orig	Tue Oct 22 17:42:20 2002
+++ src/keymap.c	Tue Oct 22 17:42:33 2002
@@ -18,6 +18,7 @@
 
 #ident "$Id: patch-src_keymap.c,v 1.1 2002/10/22 21:53:50 marcus Exp $"
 #include "../config.h"
+#include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
 #include <glib.h>
