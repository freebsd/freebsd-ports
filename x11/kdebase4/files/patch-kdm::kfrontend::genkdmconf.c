--- kdm/kfrontend/genkdmconf.c.orig	Wed Sep  5 08:15:47 2001
+++ kdm/kfrontend/genkdmconf.c	Tue Oct 23 04:04:22 2001
@@ -212,7 +212,7 @@
  */
 
 #ifndef HALT_CMD
-# ifdef BSD
+# if defined(BSD) || defined(__FreeBSD__)
 #  define HALT_CMD	"/sbin/shutdown -h now"
 #  define REBOOT_CMD	"/sbin/shutdown -r now"
 # elif defined(__SVR4)
@@ -1606,7 +1606,7 @@
 #endif
 "\n"
 "#exec sessreg -a -l $DISPLAY "
-#ifdef BSD
+#if defined(BSD) || defined(__FreeBSD__)
 "-x " KDMCONF "/Xservers "
 #endif
 "$USER\n"
@@ -1628,7 +1628,7 @@
 #endif
 "\n"
 "#exec sessreg -d -l $DISPLAY "
-#ifdef BSD
+#if defined(BSD) || defined(__FreeBSD__)
 "-x " KDMCONF "/Xservers "
 #endif
 "$USER\n"
