--- libzvt/gnome-pty-helper.c.orig	2002-06-05 06:07:33.000000000 +0000
+++ libzvt/gnome-pty-helper.c	2013-03-06 13:40:00.000000000 +0000
@@ -50,9 +50,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
-#include <utmp.h>
 #include <grp.h>
-#include <glib/galloca.h>
+#include <glib.h>
 #include "gnome-pty.h"
 #include "gnome-login-support.h"
 
