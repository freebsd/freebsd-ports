--- src/print_volume.c.orig	2016-01-12 12:27:47 UTC
+++ src/print_volume.c
@@ -60,7 +60,7 @@ void print_volume(yajl_gen json_gen, cha
         free(instance);
     }
 
-#ifndef __OpenBSD__
+#if !defined(__OPENBSD__) && !defined(__FreeBSD__)
     /* Try PulseAudio first */
 
     /* If the device name has the format "pulse[:N]" where N is the
