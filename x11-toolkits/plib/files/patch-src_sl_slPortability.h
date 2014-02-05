--- src/sl/slPortability.h.orig	2008-03-11 02:06:24.000000000 +0000
+++ src/sl/slPortability.h
@@ -51,7 +51,7 @@
 #include <limits.h>
 #include <math.h>
 
-#if (defined(UL_LINUX) || defined(UL_BSD)) && !defined(__NetBSD__)
+#if (defined(UL_LINUX) || defined(UL_BSD) || defined(__DragonFly__)) && !defined(__NetBSD__)
 #define SL_USING_OSS_AUDIO 1
 #endif
 
@@ -59,7 +59,7 @@
 #  if defined(UL_LINUX)
 #    include <linux/soundcard.h>
 #    include <sys/ioctl.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__DragonFly__)
 #    include <sys/soundcard.h>
 #  else
     /*
@@ -75,7 +75,7 @@
 #endif
 
 #ifdef UL_BSD
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #  include <sys/audioio.h>
 #endif
 #endif
