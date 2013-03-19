--- ./src/print_volume.c.orig	2013-03-19 21:06:34.895386349 +0100
+++ ./src/print_volume.c	2013-03-19 21:06:39.429385083 +0100
@@ -175,16 +175,32 @@
 	}
 #endif
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
-        char mixerpath[] = "/dev/mixer";
+        char *mixerpath;
+        char defaultmixer[] = "/dev/mixer";
         int mixfd, vol, devmask = 0;
+        pbval = 1;
+
+        if (mixer_idx >= 0)
+                asprintf(&mixerpath, "/dev/mixer%d", mixer_idx);
+        else
+                mixerpath = defaultmixer;
 
         if ((mixfd = open(mixerpath, O_RDWR)) < 0)
                 return;
+
+        if (mixer_idx >= 0)
+                free(mixerpath);
+
         if (ioctl(mixfd, SOUND_MIXER_READ_DEVMASK, &devmask) == -1)
                 return;
         if (ioctl(mixfd, MIXER_READ(0),&vol) == -1)
                 return;
 
+        if (((vol & 0x7f) == 0) && (((vol >> 8) & 0x7f) == 0)) {
+                START_COLOR("color_degraded"); 
+                pbval = 0;
+        }
+
         const char *walk = fmt;
         for (; *walk != '\0'; walk++) {
                 if (*walk != '%') {
