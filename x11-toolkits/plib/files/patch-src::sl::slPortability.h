--- ./src/sl/slPortability.h.orig	Sat Sep  7 17:54:59 2002
+++ ./src/sl/slPortability.h	Sat Sep  7 17:55:22 2002
@@ -74,7 +74,7 @@
 #  if defined(__linux__)
 #    include <linux/soundcard.h>
 #  elif defined(__FreeBSD__)
-#    include <machine/soundcard.h>
+#    include <sys/soundcard.h>
 #  else
     /*
       Tom thinks this file may be <sys/soundcard.h> under some
