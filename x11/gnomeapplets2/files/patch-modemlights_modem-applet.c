--- modemlights/modem-applet.c.orig	Fri Jan 14 00:06:52 2005
+++ modemlights/modem-applet.c	Fri Jan 14 00:08:28 2005
@@ -24,12 +24,19 @@
 
 #include <panel-applet.h>
 #include <fcntl.h>
+#ifndef __FreeBSD__
 #include <pty.h>
+#endif
 #include <sys/poll.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <libxml/tree.h>
 #include <glade/glade.h>
+#ifdef __FreeBSD__
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#endif
 
 #include "modem-applet.h"
 
