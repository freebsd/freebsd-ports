--- driver/passwd-helper.c.orig	2021-10-04 22:18:28 UTC
+++ driver/passwd-helper.c
@@ -20,8 +20,6 @@
 
  *****************************************************************************/
 
-#error "email jwz@jwz.org about passwd-helper.c"
-
 
 /* The idea here is to be able to run xscreensaver without any setuid bits.
  * Password verification happens through an external program that you feed
