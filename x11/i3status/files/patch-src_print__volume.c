--- src/print_volume.c.orig	2019-01-23 08:03:56 UTC
+++ src/print_volume.c
@@ -86,7 +86,7 @@ void print_volume(yajl_gen json_gen, char *buffer, con
         free(instance);
     }
 
-#if !defined(__DragonFly__) && !defined(__OpenBSD__)
+#if !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
     /* Try PulseAudio first */
 
     /* If the device name has the format "pulse[:N]" where N is the
