--- ./src/print_volume.c.orig	2012-10-03 13:44:44.000000000 +0200
+++ ./src/print_volume.c	2012-12-29 01:14:29.384748264 +0100
@@ -175,8 +175,9 @@
 	}
 #endif
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
-        char mixerpath[] = "/dev/mixer";
+	char mixerpath[] = "/dev/mixer";
         int mixfd, vol, devmask = 0;
+	int pbval = 1;
 
         if ((mixfd = open(mixerpath, O_RDWR)) < 0)
                 return;
@@ -185,6 +186,12 @@
         if (ioctl(mixfd, MIXER_READ(0),&vol) == -1)
                 return;
 
+	if ((vol & 0x7f) == 0 && (vol >> 8) & 0x7f == 0)
+		pbval = 0;
+
+	if (!pbval)
+		START_COLOR("color_bad");
+
         const char *walk = fmt;
         for (; *walk != '\0'; walk++) {
                 if (*walk != '%') {
