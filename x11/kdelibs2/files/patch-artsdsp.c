--- arts/artsc/artsdsp.c	Sat Oct 28 18:12:12 2000
+++ arts/artsc/artsdsp.c.new	Sat Oct 28 18:14:56 2000
@@ -27,6 +27,9 @@
 #endif
 
 #ifdef HAVE_SYS_SOUNDCARD_H
+#ifndef SNDCTL_DSP_CHANNELS
+#define SNDCTL_DSP_CHANNELS SOUND_PCM_WRITE_CHANNELS
+#endif
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
