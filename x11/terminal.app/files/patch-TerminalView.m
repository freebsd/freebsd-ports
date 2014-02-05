--- TerminalView.m.orig	2012-03-06 17:54:33.000000000 -0500
+++ TerminalView.m
@@ -33,7 +33,7 @@ activated */
 #  include <termios.h>
 #  include <pcap.h>
 #define TCSETS TIOCSETA
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/ioctl.h>
 #  include <termios.h>
@@ -52,7 +52,7 @@ activated */
 #include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #if !(defined (__NetBSD__)) && !(defined (__SOLARIS__)) && !(defined(__OpenBSD__))
 #  include <pty.h>
 #endif
@@ -73,6 +73,7 @@ activated */
 #include <AppKit/NSGraphics.h>
 #include <AppKit/NSScroller.h>
 #include <AppKit/DPSOperators.h>
+#include <AppKit/NSButtonCell.h>
 
 #include "TerminalView.h"
 
